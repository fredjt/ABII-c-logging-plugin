I am writing this down here so I don't forget what I have already explored.

## The Problem

It would be great to decouple the build from the host and enable targeting a different version of glibc, a different
kernel, or a different compiler toolchain than the build system has without recreating the entire host environment'
(i.e. a containerized build). However, I have not found a satisfactory solution to this. Here is what I have tried,
what was great about each method (assuming it wasn't a completely stupid idea), and what was wrong:

---

- __Build against the host glibc__
    - It is difficult to keep the system headers from polluting the build. More importantly, we are still using the
      build system compiler, which is setting all of the `__MACRO__` feature flags to values defined by the build
      toolchain. If the build toolchain differs from the host one, then this can break the ABI in ways that don't matter
      for normal libraries, but do matter for interception by `LD_PRELOAD`. Also, the headers' API may not agree with
      the build system's startup files' ABI, resulting in a broken build that will run on neither the host nor the build
      machine.

---

- __Build against the build system glibc and use the host glibc headers in a namespace__
    - This is an interesting option. I can have cmake download the headers for the version of glibc I am targeting and I
      can #include them inside namespace abii {}. This effectively namespaces all of the type definitions (typedefs and
      structs), but it does not fix the issue with macros. The build compiler is setting the macros in the host headers
      and using them to define the API and sometimes even the ABI of the functions and types. For basic interception,
      this might be workable since the ABI remains largely the same, but for printing arguments, returns, struct
      members, etc. and their types and values, this does not work since we also need the API to match the host.

---

- __Build against the build system glibc and maintain a processed set of host headers__
    - This is the both the most labor-intensive solution and the closest one to succeeding. We can copy the host system
      headers, remove comments, function declarations, and any other things we don't need, and keep just the macro logic
      (#define, #ifdef, #ifndef, #undef, etc.) and the type definitions (typedefs and structs). We can then namespace
      the header to prevent the host types from colliding with the system types and prefix all of the macro names with
      something like ABII_HOST_* to prevent them from colliding as well. This opens up a great feature where we can then
      collect a list of these macros in a cmake file and iterate through them creating cache entries, finding their
      values in the build environment to provide sane defaults, and generating a header defining them that we can
      include from our processed host features.h, which is where those macro flags are used to set the glibc feature
      macros. This allows the user to override the build system defaults with what their host system uses, allowing them
      to almost emulate the host environment to generate the correct interception ABI. Besides the immense amount of
      effort required to maintain these processed headers for every supported version of glibc, there are several other
      accommodations that would need to be made such as stripping the namespace from printed types, which may then
      impose all of these workarounds on all future plugins despite there being no chance of header/type collision due
      to those plugins' target libraries not being build dependencies of the interception plugin library itself. Another
      issue is inherent to any attempt to build against a different version of glibc than the one being targeted. The
      mechanics of the plugin library may make use of functions that don't exist in the older version of glibc being
      targeted or (much more rarely) have been removed from a newer version being targeted. All of these could be worked
      around and solutions could be found without too much difficulty, but they add up to a cost way too high for the
      reward.

---

## The Solution

The solution to this issue is the obvious one: make the build environment the host environment. This can be broken down
into three cases of increasing complexity:

- __Host glibc, compiler toolchain, and kernel all match the build machine__
    - Simply build directly on the build machine against the system glibc with the system toolchain. If your goal is
      that simple, why are you even reading this?
- __Host glibc is different, but the toolchain and kernel match__
    - Build against the host glibc installed in a sysroot using the build system's toolchain and kernel headers.
- __Host glibc and toolchain differ from the build system or the kernel differs__
    - This is probably the most likely scenario for anyone building for a host system that is not their own (build !=
      host). In this case, build in a chroot or docker container. They share the build machine's kernel, but all that
      matters is the macro definitions in the headers, which the container will have for the host system.

---

Maybe one day I will come up with a solution to this. Maybe the C standard will learn some more things from C++ about
language introspection. But until that day comes and those things change, I don't really see a solution to this issue
other than the age-old method of building it where it is going to run. Thankfully, Docker has made this much easier than
it used to be, but I would still like a solution that doesn't enforce a large build dependency like Docker. 

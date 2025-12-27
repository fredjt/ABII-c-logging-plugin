cmake_minimum_required(VERSION 3.28)

project(ABII-c-logging-plugin LANGUAGES CXX VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)

if (BIT32)
	list(PREPEND CMAKE_PREFIX_PATH "/usr/lib32/cmake/abii")
endif ()
find_package(abii REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	message(STATUS "Enabling LTO for non-debug builds")
	set(CMAKE_OPTIMIZE_DEPENDENCIES TRUE)
	add_compile_options("-flto" "-ffat-lto-objects" "-O3")
endif ()
add_compile_options("-fPIC")

add_library(c-logger SHARED
            hooks/arpa/nameser_compat.h
            hooks/asm-generic/errno.h
            hooks/asm-generic/errno-base.h
            hooks/bits/types/__fpos64_t.h
            hooks/bits/types/__fpos_t.h
            hooks/bits/types/__locale_t.h
            hooks/bits/types/__mbstate_t.h
            hooks/bits/types/__sigset_t.h
            hooks/bits/types/__sigval_t.h
            hooks/bits/types/cookie_io_functions_t.h
            hooks/bits/types/res_state.h
            hooks/bits/types/sigevent_t.h
            hooks/bits/types/siginfo_t.h
            hooks/bits/types/stack_t.h
            hooks/bits/types/struct___jmp_buf_tag.h
            hooks/bits/types/struct_sched_param.h
            hooks/bits/types/struct_sigstack.h
            hooks/bits/types/struct_timespec.h
            hooks/bits/atomic_wide_counter.h
            hooks/bits/cpu-set.h
            hooks/bits/dirent.h
            hooks/bits/fcntl.h
            hooks/bits/fcntl-linux.h
            hooks/bits/ioctl-types.h
            hooks/bits/mqueue.h
            hooks/bits/netdb.h
            hooks/bits/pthreadtypes.h
            hooks/bits/sched.h
            hooks/bits/semaphore.h
            hooks/bits/sigaction.h
            hooks/bits/sigcontext.h
            hooks/bits/siginfo-consts.h
            hooks/bits/signum-arch.h
            hooks/bits/signum-generic.h
            hooks/bits/socket.h
            hooks/bits/socket_type.h
            hooks/bits/ss_flags.h
            hooks/bits/struct_mutex.h
            hooks/bits/struct_rwlock.h
            hooks/bits/struct_stat.h
            hooks/bits/termios-struct.h
            hooks/bits/thread-shared-types.h
            hooks/bits/time.h
            hooks/linux/audit.h
            hooks/netinet/in.h
            hooks/aio.cpp hooks/aio.h
            hooks/aliases.cpp hooks/aliases.h
            hooks/alloca.cpp
            hooks/ar.h
            hooks/argp.cpp hooks/argp.h
            hooks/argz.cpp
            hooks/assert.cpp
            hooks/ctype.cpp hooks/ctype.h
            hooks/dirent.cpp hooks/dirent.h
            hooks/dlfcn.cpp hooks/dlfcn.h
            hooks/elf.h
            hooks/envz.cpp
            hooks/err.cpp
            hooks/errno.cpp
            hooks/error.cpp
            hooks/execinfo.cpp
            hooks/fcntl.cpp hooks/fcntl.h
            hooks/fmtmsg.cpp hooks/fmtmsg.h
            hooks/fnmatch.cpp hooks/fnmatch.h
            hooks/fstab.cpp hooks/fstab.h
            hooks/fts.cpp hooks/fts.h
            hooks/ftw.cpp hooks/ftw.h
            hooks/gconv.h
            hooks/glob.cpp hooks/glob.h
            hooks/grp.cpp hooks/grp.h
            hooks/gshadow.cpp hooks/gshadow.h
            hooks/iconv.cpp
            hooks/ifaddrs.cpp hooks/ifaddrs.h
            hooks/inttypes.cpp hooks/inttypes.h
            hooks/langinfo.cpp hooks/langinfo.h
            hooks/libgen.cpp
            hooks/link.cpp hooks/link.h
            hooks/locale.cpp hooks/locale.h
            hooks/obstack.cpp hooks/obstack.h
            hooks/pthread.cpp hooks/pthread.h
            hooks/regex.cpp hooks/regex.h
            hooks/resolv.cpp hooks/resolv.h
            hooks/stdio.cpp hooks/stdio.h
            custom_enum_printers.h
            custom_printers.h)

target_link_libraries(c-logger PUBLIC abii::libabii)

if (BIT32)
	set_target_properties(c-logger PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
	add_compile_definitions("BIT32")
endif ()

target_include_directories(c-logger PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# CPack setup
if (BIT32)
	set(CPACK_PACKAGE_NAME "abii-c-logging-plugin-32")
else ()
	set(CPACK_PACKAGE_NAME "abii-c-logging-plugin")
endif ()
set(CPACK_PACKAGE_VENDOR "Trent Tanchin")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ABII-c-logging-plugin - Glibc logging plugin for ABII")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_GENERATOR "TGZ;DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Trent Tanchin <trent@tanchin.org>")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${PROJECT_VERSION}")

set(CPACK_SOURCE_IGNORE_FILES
    /build/
    /cmake-build-.*/
    /.git/
    /.idea/
    ~$)

include(CPack)

if (BIT32)
	set(CMAKE_INSTALL_PLUGINDIR "share/abii/plugins/32")
else ()
	set(CMAKE_INSTALL_PLUGINDIR "share/abii/plugins/64")
endif ()
install(TARGETS c-logger LIBRARY DESTINATION "${CMAKE_INSTALL_PLUGINDIR}")

if (NOT BIT32)
	install(FILES syms DESTINATION "share/abii/syms" RENAME "c-logger")
endif ()

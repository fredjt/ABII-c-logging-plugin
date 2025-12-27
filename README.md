# ABII-c-logging-plugin

This plugin for the <a href=https://github.com/fredjt/ABII>ABII project</a> covers the glibc C standard library
functions and enables a user to log any chosen C function calls in a process.

This plugin is in development and not yet complete, so not every function is available for interception just yet.

### Known issues:

- dlsym and dlvsym cannot be simultaneously intercepted
- Intercepting mcheck/mcheck_pedantic breaks mcheck/mcheck_pedantic functionality

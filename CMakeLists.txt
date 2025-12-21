cmake_minimum_required(VERSION 3.28)

project(ABII-c-logging-plugin LANGUAGES CXX VERSION 0.0.1)

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

add_library(c-logger SHARED
            include/arpa/nameser_compat.h
            include/asm-generic/errno.h
            include/asm-generic/errno-base.h
            include/bits/types/__fpos64_t.h
            include/bits/types/__fpos_t.h
            include/bits/types/__locale_t.h
            include/bits/types/__mbstate_t.h
            include/bits/types/__sigset_t.h
            include/bits/types/__sigval_t.h
            include/bits/types/cookie_io_functions_t.h
            include/bits/types/res_state.h
            include/bits/types/sigevent_t.h
            include/bits/types/siginfo_t.h
            include/bits/types/stack_t.h
            include/bits/types/struct___jmp_buf_tag.h
            include/bits/types/struct_sched_param.h
            include/bits/types/struct_sigstack.h
            include/bits/types/struct_timespec.h
            include/bits/atomic_wide_counter.h
            include/bits/cpu-set.h
            include/bits/dirent.h
            include/bits/fcntl.h
            include/bits/fcntl-linux.h
            include/bits/ioctl-types.h
            include/bits/mqueue.h
            include/bits/netdb.h
            include/bits/pthreadtypes.h
            include/bits/sched.h
            include/bits/semaphore.h
            include/bits/sigaction.h
            include/bits/sigcontext.h
            include/bits/siginfo-consts.h
            include/bits/signum-arch.h
            include/bits/signum-generic.h
            include/bits/socket.h
            include/bits/socket_type.h
            include/bits/ss_flags.h
            include/bits/struct_mutex.h
            include/bits/struct_rwlock.h
            include/bits/struct_stat.h
            include/bits/termios-struct.h
            include/bits/thread-shared-types.h
            include/bits/time.h
            include/linux/audit.h
            include/netinet/in.h
            include/aio.cpp
            include/aio.h
            include/dirent.cpp
            include/dirent.h
            include/obstack.cpp
            include/obstack.h
            include/pthread.cpp
            include/pthread.h
            include/regex.cpp
            include/regex.h
            include/stdio.cpp
            include/stdio.h
            custom_enum_printers.h
            custom_printers.h
            include/resolv.cpp
            include/resolv.h)

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
install(TARGETS c-logger LIBRARY DESTINATION ${CMAKE_INSTALL_PLUGINDIR})

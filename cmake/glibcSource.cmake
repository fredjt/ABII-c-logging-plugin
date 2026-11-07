include(FetchContent)

try_run(runresult compileresult
        SOURCES ${CMAKE_SOURCE_DIR}/cmake/glibc_version.cpp
        RUN_OUTPUT_STDOUT_VARIABLE GLIBC_VERSION
        )

set(GLIBC_BASE_URL "https://ftpmirror.gnu.org/gnu/glibc")
set(GLIBC_ARCHIVE_NAME "glibc-${GLIBC_VERSION}.tar.xz")

FetchContent_Declare(glibc URL "${GLIBC_BASE_URL}/${GLIBC_ARCHIVE_NAME}")
FetchContent_MakeAvailable(glibc)

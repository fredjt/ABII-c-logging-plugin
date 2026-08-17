FROM ubuntu:26.10

RUN dpkg --add-architecture i386
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    gdb \
    git \
    gcc-multilib \
    g++-multilib \
    libc6-dev:i386 \
    libstdc++6:i386

RUN git clone --recursive https://github.com/fredjt/ABII
RUN cd ABII && mkdir build && cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_LIBDIR=lib/x86_64-linux-gnu -GNinja .. && \
    ninja package && apt install -y ./abii*.deb

RUN cd ABII && rm -rf build && mkdir build && cd build &&  \
    cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_LIBDIR=lib/i386-linux-gnu -DBIT32=ON -GNinja .. &&  \
    ninja package && apt install ./abii*.deb

ENTRYPOINT ["top", "-b"]

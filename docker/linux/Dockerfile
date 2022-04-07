FROM ubuntu:20.04
RUN export DEBIAN_FRONTEND=noninteractive && apt-get update && \
    apt-get -y dist-upgrade && \
    apt-get -y install \
        build-essential \
        freeglut3-dev \
        curl \
        python3 \
        python3-pip \
        gdb \
        maven \
        autoconf \
        libtool \
        ninja-build \
       fonts-dejavu-core \
        git \
        git-lfs \
        golang \
        libxrender1 \
        libxtst-dev \
        awscli

# clang
RUN echo "deb https://apt.llvm.org/focal/ llvm-toolchain-focal-12 main" >> /etc/apt/sources.list && \
    echo "deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-12 main" >> /etc/apt/sources.list && \
    curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - && \
    apt-get update && \
    apt-get install -y \
        libclang-cpp12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        libllvm12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        libclang-common-12-dev=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        libclang1-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        liblldb-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        llvm-12-dev=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        llvm-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        llvm-12-runtime=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        llvm-12-tools=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        python3-lldb-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        clang-format-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        clang-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        lldb-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 \
        lld-12=1:12.0.1~++20211029101322+fed41342a82f-1~exp1~20211029221816.4 && \
    update-alternatives --install /usr/bin/cc cc /usr/bin/clang-12 30 && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-12 30 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-12 30

# cmake
RUN curl -L -o install_cmake.sh https://github.com/Kitware/CMake/releases/download/v3.20.1/cmake-3.20.1-linux-x86_64.sh && \
    sh install_cmake.sh --skip-license --prefix=/usr

# conan
RUN pip3 install conan==1.44.0 && \
    pip3 install 'requests[security]' 

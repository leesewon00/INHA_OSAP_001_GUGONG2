#!/bin/bash

# 기존 build 폴더가 있을 경우 삭제
cd src
if [ -d "build" ]; then
    rm -rf build
    echo "Removed existing build directory."
fi

# 새 build 폴더 생성
mkdir build
echo "Created new build directory."

# build 폴더로 이동
cd build

# CMake를 통해 빌드 파일 생성
cmake ..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed."
    exit 1
fi

# Make를 통해 컴파일 및 실행 파일 생성
make
if [ $? -ne 0 ]; then
    echo "Build failed."
    exit 1
fi

echo "Build completed successfully."

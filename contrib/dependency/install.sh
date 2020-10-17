#!/bin/bash
#
# Copyright (C) 2018 Yung-Yu Chen <yyc@solvcon.net>.
#
# Build and install xtensor-python.

if [ "$(uname)" == "Darwin" ] ; then
INSTALL_PREFIX=${INSTALL_PREFIX:-/usr/local}
else
INSTALL_PREFIX=${INSTALL_PREFIX:-/usr}
fi

install() {

  githuborg=$1
  pkgname=$2
  pkgbranch=$3
  pkgfull=$4
  cmakeargs="${@:5}"
  pkgrepo=https://github.com/$githuborg/$pkgname.git
  repotar=https://github.com/$githuborg/$pkgname/archive/$pkgbranch.tar.gz

  workdir=$(mktemp -d /tmp/build.XXXXXXXXX)
  echo "Work directory: $workdir"
  mkdir -p $workdir
  pushd $workdir
  echo "remote tarball: $repotar"
  curl -sSL -o $pkgfull.tar.gz $repotar
  rm -rf $pkgfull
  tar xf $pkgfull.tar.gz
  cd $pkgfull
  mkdir -p build
  cd build
  cmake $cmakeargs ..
  make install
  popd
  rm -rf $workdir

}

pybind11() {

  cmakeargs=("-DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX}")
  cmakeargs+=("-DCMAKE_BUILD_TYPE=Release")
  cmakeargs+=("-DPYTHON_EXECUTABLE:FILEPATH=`which python3`")
  cmakeargs+=("-DPYBIND11_TEST=OFF")
  # For C++17 with clang on Linux, we may need master.
  # https://github.com/pybind/pybind11/commit/759221f5c56939f59d8f342a41f8e2d2cacbc8cf
  install ${PYBIND_ORG:-pybind} pybind11 ${PYBIND_BRANCH:-v2.5.0} \
    ${PYBIND_LOCAL:-pybind11-2.5.0} "${cmakeargs[@]}"

}

if [ $1 == "pybind11" ]; then
  pybind11
elif [ $1 == "everything" ]; then
  pybind11
fi

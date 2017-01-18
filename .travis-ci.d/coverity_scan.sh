#!/bin/bash

source /cvmfs/clicdp.cern.ch/compilers/gcc/6.2.0/x86_64-centos7/setup.sh

cd /Package
mkdir build
cd build
cmake -DUSE_CXX11=ON -DBUILD_ROOTDICT=OFF .. && \
export PATH=/Package/cov-analysis-linux64/bin:$PATH && \
cov-build --dir cov-int make -j2 && \
tar czvf myproject.tgz cov-int
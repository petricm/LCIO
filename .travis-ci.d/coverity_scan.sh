#!/bin/bash

ILCSOFT=/cvmfs/clicdp.cern.ch/iLCSoft/builds/current/CI_gcc
source $ILCSOFT/init_ilcsoft.sh

cd /Package
mkdir build
cd build
cmake -DUSE_CXX11=ON -DBUILD_ROOTDICT=OFF .. && \
mv ../coverity_tool.tgz . && \
mkdir cov-analysis-linux64 && \
tar -xf coverity_tool.tgz -C cov-analysis-linux64 --strip-components=2 && \
export PATH=$(pwd)/cov-analysis-linux64/bin:$PATH && \
cov-build --dir cov-int make -j2 && \
tar czvf myproject.tgz cov-int
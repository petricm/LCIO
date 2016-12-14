#!/bin/bash

ILCSOFT=/cvmfs/clicdp.cern.ch/iLCSoft/builds/current/CI_gcc
source $ILCSOFT/init_ilcsoft.sh

cd /Package
mkdir build
cd build
cmake -DUSE_CXX11=ON -DBUILD_ROOTDICT=ON ..
wget https://scan.coverity.com/download/linux64 --post-data "token=${COVERITY_SCAN_TOKEN}&project=iLCSoft%2FLCIO" -O coverity_tool.tgz
mkdir cov-analysis-linux64
tar -xf coverity_tool.tgz -C cov-analysis-linux64 --strip-components=2
export PATH=$(pwd)/cov-analysis-linux64/bin:$PATH
cov-build --dir cov-int make -j2
tar czvf myproject.tgz cov-int
#!/bin/bash

ILCSOFT=/cvmfs/clicdp.cern.ch/iLCSoft/builds/current/CI_gcc
source $ILCSOFT/init_ilcsoft.sh

cd /Package
mkdir build
cd build
cmake -DUSE_CXX11=ON -DBUILD_ROOTDICT=OFF .. && \
wget https://scan.coverity.com/download/linux64 --post-data "token=${COVERITY_SCAN_TOKEN}&project=iLCSoft%2FLCIO" -O coverity_tool.tgz && \
mkdir cov-analysis-linux64 && \
tar -xf coverity_tool.tgz -C cov-analysis-linux64 --strip-components=2 && \
export PATH=$(pwd)/cov-analysis-linux64/bin:$PATH && \
cov-build --dir cov-int make -j2 && \
tar czvf myproject.tgz cov-int && \
export description=`date` && \
curl --form token=${COVERITY_SCAN_TOKEN} --form email=marko.petric@cern.ch --form file=@myproject.tgz --form version="master" --form description="${description}" https://scan.coverity.com/builds?project=iLCSoft%2FLCIO

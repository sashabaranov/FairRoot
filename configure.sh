#!/bin/bash
#
if [ "x$SIMPATH" == "x" ]; then
# check if FairSoftInst exists one level up
 if [ -d $PWD/../FairSoftInst ]; then
   export SIMPATH=$PWD/../FairSoftInst
 else
    echo "*** No FairSoft installation directory is defined."
    echo "*** Please set the environment variable SIMPATH to the Fairsoft installation directory."
    exit 1
 fi 
fi

# if on lxplus
distribution=$(lsb_release -is)
version=$(lsb_release -rs | cut -f1 -d.)     

if [ "$distribution$version" = "ScientificCERNSLC6" ]; then
 # operating system of last century
  source scl_source enable python27
  source scl_source enable devtoolset-3
fi

if [ ! -d build ]; then
 mkdir build
fi
cd build

export PATH=$SIMPATH/bin:$PATH
installDir="${PWD/FairRoot/FairRootInst}"
if [ "$distribution$version" = "ScientificCERNSLC6" ]; then
 xx=$($SIMPATH/bin/fairsoft-config --cxx)
 cmake .. -DCMAKE_INSTALL_PREFIX=$installDir -DCMAKE_CXX_COMPILER=$xx
else
 cmake .. -DCMAKE_INSTALL_PREFIX=$installDir
fi 
make
make install
make test

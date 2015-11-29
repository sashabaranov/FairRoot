#!/bin/bash
#
if [ "x$SIMPATH" == "x" ]; then
# check if FairSoftInst exists one level up
 if [ d $PWD/../FairSoftInst ]; then
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

if [ "$distribution$version" = "ScientificCERNSLC6" ]; then
 xx=$($SIMPATH/bin/fairsoft-config --cxx)
 echo $xx
 cmake -DCMAKE_INSTALL_PREFIX="$PWD/../FairRootInst" -DCMAKE_CXX_COMPILER=$xx
else
 cmake -DCMAKE_INSTALL_PREFIX="$PWD/../FairRootInst"
fi 
make
make install
make test

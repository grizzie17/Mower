#!/bin/bash
THISFILE1=${BASH_SOURCE[0]}
THISDIR1=$(cd -P `dirname $THISFILE1` && pwd -P)

source $THISDIR1/build-common.inc

echo | $CXX  -dM -E - | sort
exit $?

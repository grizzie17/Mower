#!/bin/bash
THISFILE1=${BASH_SOURCE[0]}
THISDIR1=$(cd -P `dirname $THISFILE1` && pwd -P)

source $THISDIR1/build-common.inc

echo | $CXX  -E -v - 2>&1 | sed -e ':x;s@/[A-Za-z0-9][A-Za-z0-9._-]*/\.\./@/@; t x'
exit $?

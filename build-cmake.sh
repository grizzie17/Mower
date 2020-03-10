#!/bin/bash
THISFILE=${BASH_SOURCE[0]}
THISDIR=$(cd -P `dirname $THISFILE` && pwd -P)


source $THISDIR/build-common.inc

rm -rf $THISDIR/build
mkdir -p $THISDIR/build

pushd $THISDIR/build &>/dev/null

cmake ..
sts=$?
if [ $sts ]; then
	make
fi


popd &>/dev/null

exit $sts

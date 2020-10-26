#!/bin/bash
THISFILE=${BASH_SOURCE[0]}
THISDIR=$(cd -P `dirname $THISFILE` && pwd -P)


source $THISDIR/build-common.inc

rm -rf $THISDIR/build
mkdir -p $THISDIR/build

pushd $THISDIR/build &>/dev/null

	export CMAKE_LIBRARY_PATH=/mingw64/x86_64-w64-mingw32/lib

	cmake "$@" ..
	sts=$?
	# if [ $sts ]; then
	# 	make
    #     sts=$?
	# fi


popd &>/dev/null

exit $sts

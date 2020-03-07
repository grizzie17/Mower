#!/bin/bash

XMACHINE=`uname -m`
XLIBDIR=


case `uname -o` in
[Mm]sys | cygwin* )
	case "$XMACHINE" in
	*64* )
		MINGX="mingw64"
		WXX="w64"
		;;
	* )
		MINGX="mingw32"
		WXX="w32"
		;;
	esac
	export ARCH="$MINGW_CHOST"
	#export ARCH="${XMACHINE}-${WXX}-mingw32"
	export ARCH_PREFIX="${ARCH}-"
	export CC="${ARCH_PREFIX}gcc"
	export CXX="${ARCH_PREFIX}g++"
	export CXXFLAGS="-g -ggdb -O0"
	export XINCDIR="/$MINGX/$ARCH/include"
	export CPPFLAGS="-D_DEBUG -I$XINCDIR"
	#export LDFLAGS="-g -ggdb -Wl,--discard-none -Wl,--gc-keep-exported -L/$MINGX/$ARCH/lib"
	export XLIBDIR="/$MINGX/$ARCH/lib"
	export LDFLAGS="-g -ggdb -L$XLIBDIR"
	;;
* )
	export ARCH=
	export ARCH_PREFIX=
	export CC=gcc
	export CXX=g++
	export CXXFLAGS="-g -ggdb -O0"
	export CPPFLAGS="-D_DEBUG -DOPENGL"
	export XLIBDIR="/usr/lib"
	export LDFLAGS="-g -ggdb"
esac
unset MINGX
unset WXX
unset XMACHINE

echo "ARCH=$ARCH"
echo "CPPFLAGS=$CPPFLAGS"
echo "LDFLAGS=$LDFLAGS"

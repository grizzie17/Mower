#!/bin/bash
THISFILE=${BASH_SOURCE[0]}
THISDIR=$(cd -P `dirname $THISFILE` && pwd -P)


case "$1" in
-c | --clean )
	$THISDIR/build-clean.sh
	;;
esac



source $THISDIR/build-common.inc

USRLOCAL=$THISDIR/usrlocal


pushd $THISDIR >/dev/null

	$THISDIR/autogen.sh  ||  exit $?


	mkdir -p $USRLOCAL  ||  exit $?
	mkdir -p $THISDIR/build		||	exit $?
	pushd $THISDIR/build >/dev/null
		echo ":::configure:::"
		$THISDIR/configure --prefix=$USRLOCAL  ||  exit $?
		case `uname -o` in
		[Mm]sys | cygwin* )
			#echo "patching libtool for Msys"
			#sed -e 's/ _spawnv / spawnv /g' -i libtool  ||  exit $?
			if [ -f $THISDIR/test-driver ]; then
				echo "patching test-driver"
				patch $THISDIR/test-driver < $THISDIR/build-patches/test-driver.patch  ||  exit $?
			fi
			;;
		esac
	popd >/dev/null


popd >/dev/null

echo "Complete..."
exit 0

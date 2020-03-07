#!/bin/bash
THISFILE=${BASH_SOURCE[0]}
THISDIR=$(cd -P `dirname $THISFILE` && pwd -P)
THISCMD=`basename $THISFILE`


#$THISDIR/build-clean.sh  ||  exit $?
#$THISDIR/build-config.sh  ||  exit $?

source $THISDIR/build-common.inc


ARG="$1"
ARGDIR=""
ARGFILE=""

if [ -n "$ARG" ]; then
	if [ "ALL" = "$ARG" ]; then
		ARGDIR=""
		ARGFILE=""
	else
		ARGDIR=`dirname $ARG`
		ARGFILE=`basename $ARG | sed -e 's/\.[^.]*$/.o/'`

		case "$ARGDIR" in
		/* )
			# do nothing
			;;
		* )
			ARGDIR="/$ARGDIR"
			;;
		esac
	fi
fi
if [ -n "$2" ]; then
	if [ "X-check" = "X$2" ]; then
		ARGFILE="check"
		ARGDIR="${ARGDIR%/test}"
	elif [ "X-make" = "X$2" ]; then
		ARGFILE=""
		ARGDIR="${ARGDIR%/test}"
	elif [ "X-install" = "X$2" ]; then
		ARGFILE="install"
		ARGDIR=""
		#export DESTDIR="$THISDIR/usrlocal"
	fi
fi



#echo "THISDIR=$THISDIR"
#echo "ARG=$ARG"
echo "ARGDIR=$ARGDIR"
echo "ARGFILE=$ARGFILE"


case `uname -s` in
Msys | MSYS | msys | MINGW* )
	echo "...WIN64"
	#export CPPFLAGS="-DWIN64"
	function tweak_paths() {
		cat -  | \
			sed \
				-e ':x; s@[^/][^/]*/\.\./@@;t x' \
				-e ':y; s@^\.\./@@g; t y' \
				-e "s@$THISDIR/@@g"
	}
	;;
[Ll]inux )
	echo "...linux"
	#export CPPFLAGS="-DLINUX -DLinux -Dlinux"
	function tweak_paths() {
		cat -
	}
	;;
* )
	echo "...undefined"
	;;
esac

pushd $THISDIR/build$ARGDIR >/dev/null

	make -j8 $ARGFILE 2>&1  |  tee $THISDIR/build/build.log  | tweak_paths
	sts=${PIPESTATUS[0]}

popd >/dev/null
if [ 0 -ne $sts ]; then
	echo "$THISCMD: make exited with status: $sts" >&2
fi
exit $sts

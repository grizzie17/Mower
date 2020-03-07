#!/bin/bash
#
#	Generation of the autotools configure file
#
THISFILE="${BASH_SOURCE[0]}"
THISDIR=$(cd -P `dirname $THISFILE` && pwd -P)
THISSCRIPT=`basename $THISFILE`

CONFIGURE_D=$THISDIR


ARCH_PREFIX=""
case `uname -o` in
[Mm]sys )
	ARCH_PREFIX="x86_64-w64-mingw32-"
	;;
esac

export ACLOCAL=aclocal
export AUTOM4TE=autom4te
export AUTOCONF=autoconf
export AUTOHEADER=autoheader
export AUTOMAKE=automake
export AUTOPOINT=autopoint
export AUTORECONF=autoreconf
export GETTEXTIZE=gettextize
export GLIBGETTEXTIZE=glib-gettextize
export INTLTOOLIZE=intltoolize
export LIBTOOLIZE=libtoolize
# export LIBTOOL=libtool
export M4=m4
export MAKE=make
export PKGCONFIG=pkg-config
export MKDIR=mkdir



# tell about a problem and then exit
function fatal()
{
	local sts=1

	echo "$1" | grep '^[0-9][0-9]*$' &>/dev/null
	if [ 0 -eq $? ]; then
		sts=$1
		shift
	fi
	echo "$THISSCRIPT - FATAL($sts): $*" >&2
	exit $sts
}

# make sure that the command exists and that it knows about its own version number
function assertCmd()
{
	local cmd="$1"
	local optional="$2"
	local sts=0
	local fullcmd
	local var
	local ver

	fullcmd=`which $ARCH_PREFIX$cmd 2>/dev/null`
	sts=$?
	if [ 0 -ne $sts ]; then
		fullcmd=`which $cmd 2>/dev/null`
		sts=$?
	fi

	#echo "fullcmd=$fullcmd" >&2
	var=`echo "$cmd" | tr '[a-z]' '[A-Z]' | sed -e 's/-//g'`

	if [ 0 -eq $sts ]; then
		ver=`$fullcmd --version | head -1 | sed -r -e 's/^.*[^0-9.]([0-9][0-9.]*)/\1/'`
		sts=$?
		if [ 0 -eq $sts ]; then
			eval export $var=$fullcmd
			eval export ${var}_V=$ver
			#echo "$var=${!var}" >&2
		else
			fatal $sts "command does not know about version option: $cmd"
		fi
	elif [ "Xoptional" = "X$optional" ]; then
		#echo "unable to locate command: $cmd"
		eval export $var=
	else
		fatal $sts "unable to locate command: $cmd"
	fi
	return $sts
}


# find the current configure script
if [ -r $PWD/configure.ac ]; then
	CONFIGURE_D=$PWD
	CONFIGURE_F=$PWD/configure.ac
elif [ -r $THISDIR/configure.ac ]; then
	CONFIGURE_D=$THISDIR
	CONFIGURE_F=$THISDIR/configure.ac
elif [ -r $THISDIR/configure.in ]; then
	CONFIGURE_D=$THISDIR
	CONFIGURE_F=$THISDIR/configure.in
else
	fatal 1 "unable to locate configure.ac or configure.in"
fi

# assure the needed commands exist
echo "Autotools commands discovery..."
assertCmd $ACLOCAL
assertCmd $AUTOCONF
assertCmd $AUTOHEADER
assertCmd $AUTOM4TE
assertCmd $AUTOMAKE
assertCmd $AUTOPOINT
assertCmd $AUTORECONF
assertCmd $GETTEXTIZE
assertCmd $GLIBGETTEXTIZE optional
assertCmd $INTLTOOLIZE
assertCmd $LIBTOOLIZE
# assertCmd $LIBTOOL
assertCmd $MAKE
assertCmd $PKGCONFIG
assertCmd $MKDIR

MACRO_D=m4
t=`grep '^[ \t]*AC_CONFIG_MACRO_DIR' $CONFIGURE_F 2>/dev/null`
if [ -n "$t" ]; then
	MACRO_D=`echo "$t" | sed -e 's/^[^[]*[[]//g' -e 's/[]].*$//g'`
fi

PREFIX=/usr
DATADIR=$PREFIX/share
ACLOCALDIR=$DATADIR/aclocal
ACLOCALEXTRAPATH=" -I $ACLOCALDIR/"

ACLOCAL="$ACLOCAL --system-acdir=$ACLOCALDIR/"

if [ -d $DATADIR/aclocal-$AUTOMAKE_V ]; then
	ACLOCAL="$ACLOCAL --automake-acdir=$DATADIR/aclocal-$AUTOMAKE_V"
fi

#EXTRA_AUTORECONF="--exclude=autopoint"


acpaths="$acpaths ${ACLOCALEXTRAPATH}"

# echo "ACLOCAL=$ACLOCAL"
# echo "AUTOCONF=$AUTOCONF"
# echo "AUTOHEADER=$AUTOHEADER"
# echo "AUTOMAKE=$AUTOMAKE"
# echo "AUTOPOINT=$AUTOPOINT"
# echo "AUTORECONF=$AUTORECONF"
# echo "LIBTOOLIZE=$LIBTOOLIZE"
# echo "INTLTOOLIZE=$INTLTOOLIZE"
# echo "PKGCONFIG=$PKGCONFIG"
# echo "MKDIR=$MKDIR"

## autoheader ##
need_autoheader=no
grep '^[ \t]*A[CM]_CONFIG_HEADER' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_autoheader=yes

## automake ##
need_automake=no
grep '^[ \t]*AM_INIT_AUTOMAKE' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_automake=yes

## gettextize ##
need_gettextize=no
grep '^[ \t]*AM_GNU_GETTEXT' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_gettextize=yes

## glib-gettextize ##
need_glib_gettextize=no
if [ -n "$GLIBGETTEXTIZE" ]; then
	grep '^[ \t]*AM_GLIB_GNU_GETTEXT' $CONFIGURE_F  &>/dev/null
	[ 0 -eq $? ]  &&  need_glib_gettextize=yes
fi

## intltoolize ##
need_intltoolize=no
grep '^[ \t]*[AI][CT]_PROG_INTLTOOL' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_intltoolize=yes

## libtoolize ##
need_libtoolize=no
grep '^[ \t]*LT_INIT' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_libtoolize=yes
grep '^[ \t]*AC_PROG_LIBTOOL' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_libtoolize=yes
grep '^[ \t]*AC_PROG_RANLIB' $CONFIGURE_F  &>/dev/null
[ 0 -eq $? ]  &&  need_libtoolize=yes


pushd $CONFIGURE_D >/dev/null

if true; then


	if [ "Xyes" = "X$need_glib_gettextize" ]; then
		echo "...glib-gettextize... $GLIB_GETTEXTIZE_V"
		echo "no" | $GLIBGETTEXTIZE --force --copy  ||  fatal $? "glib-gettextize exited with an error"
	elif [ "Xyes" = "X$need_gettextize" ]; then
		echo "...gettextize... $GETTEXTIZE_V"
		echo "no" | $GETTEXTIZE --force --copy  ||  fatal $? "gettextize exited with an error"
	fi

	if [ "Xyes" = "X$need_intltoolize" ]; then
		echo "...intltoolize... $INTLTOOLIZE_V"
		$INTLTOOLIZE --copy --force --automake  ||  fatal $? "intltoolize exited with an error"
	fi

	echo "...autoreconf... $AUTORECONF_V"
	#echo "......ACLOCAL=$ACLOCAL"
	$MKDIR -p $CONFIGURE_D/$MACRO_D
	ACLOCAL="$ACLOCAL" $AUTORECONF --install --force $EXTRA_AUTORECONF $acpaths  ||  fatal $? "autoreconf execution failed."


else


	if [ "Xyes" = "X$need_glib_gettextize" ]; then
		echo "...glib-gettextize... $GLIB_GETTEXTIZE_V"
		echo "no" | $GLIB_GETTEXTIZE --force --copy  ||  fatal $? "glib-gettextize exited with an error"
	elif [ "Xyes" = "X$need_gettextize" ]; then
		echo "...gettextize... $GETTEXTIZE_V"
		echo "no" | $GETTEXTIZE --force --copy  ||  fatal $? "gettextize exited with an error"
	fi

	#second aclocal to get around problem with aclocal 1.15
	echo "...aclocal... $ACLOCAL_V"
	if [ -d m4 ]; then
		$ACLOCAL -I m4  ||  fatal $? "aclocal exited with an error"
	else
		mkdir -p $CONFIGURE_D/m4  ||  fatal $? "unable to make $CONFIGURE_D/m4"
		$ACLOCAL -I m4 --install 2>/dev/null  ||  echo "...:::aclocal rerun..."  &&  $ACLOCAL -I m4  ||  fatal $? "aclocal exited with an error"
	fi

	if [ "Xyes" = "X$need_libtoolize" ]; then
		echo "...libtoolize... $LIBTOOLIZE_V"
		$LIBTOOLIZE --automake -c --force  ||  fatal $? "libtoolize exited with an error"
	fi

	if [ "Xyes" = "X$need_intltoolize" ]; then
		echo "...intltoolize... $INTLTOOLIZE_V"
		$INTLTOOLIZE --copy --force --automake  ||  fatal $? "intltoolize exited with an error"
	fi

	if [ "Xyes" = "X$need_autoheader" ]; then
		echo "...autoheader... $AUTOHEADER_V"
		$AUTOHEADER --force  ||  fatal $? "autoheader exited with an error"
	fi

	if [ "Xyes" = "X$need_automake" ]; then
		echo "...automake... $AUTOMAKE_V"
		export AUTOMAKE_JOBS=4
		$AUTOMAKE --add-missing --copy --force-missing --foreign  ||  fatal $? "automake exited with an error"
	fi

	echo "...autoconf... $AUTOCONF_V"
	$AUTOCONF --force  ||  fatal $? "autoconf exited with an error"

fi

	[ -e configure ]  ||  fatal $? "failed to create required file: configure"

popd >/dev/null

exit 0

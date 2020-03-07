#!/bin/bash
THISFILE1=${BASH_SOURCE[0]}
THISDIR1=$(cd -P `dirname $THISFILE1` && pwd -P)

echo "cleaning..."

pushd $THISDIR1 >/dev/null


	for f in `find $THISDIR -name Makefile.am`
	do
		x="${f%.am}"
		[ -e "$x" ]  &&  rm -f $x
		x="$x.in"
		[ -e "$x" ]  &&  rm -f $x
	done

	rm -rf \
		aclocal.m4 ar-lib autom4te.cache \
		build runtime usrlocal \
		compile configure config.guess \
		config.sub config.log config.status config.h.in config.h.in~ \
		depcomp .deps */.deps */*/.deps \
		install-sh install.sh libtool stamp-h1 config.h \
		ltmain.sh \
		m4 missing \
		test-driver \
		*/*.o */*/*.o
	sts=$?

popd >/dev/null

exit $sts

AC_PREREQ([2.69])
AC_INIT([Mower], [0.0.1], [john@grizzlyweb.com])
AC_CONFIG_SRCDIR([README.md])
AC_CONFIG_HEADERS([config.h])


AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
#AC_PROG_AWK
AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_SED

LT_INIT([shared,pic-only])


AC_LANG([C++])

AX_CXX_COMPILE_STDCXX_17([noext],[mandatory])

# GCC is a bit picky about redefinitions of built-in macros. Alas, "built-in"
# simply means "starts with double underscore", so we have to hack around that
# below. Note that clang is happy, even without the guard.
AH_VERBATIM([__STDC_WANT_LIB_EXT1__],
[
/* we want C11 library extensions  */
#ifndef __STDC_WANT_LIB_EXT1__
# define __STDC_WANT_LIB_EXT1__ 1
#endif
])
AH_VERBATIM([__STDC_WANT_SECURE_LIB__],
[
/* we want C11 secure library  */
#ifndef __STDC_WANT_SECURE_LIB__
# define __STDC_WANT_SECURE_LIB__ 1
#endif
])

AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])


# AC_CONFIG_FILES(
# 	[base-station/Makefile
# 	differential-gps/Makefile
# 	display/Makefile
# 	environment/Makefile
# 	mower/Makefile
# 	simulator/Makefile
# 	utilities/Makefile]
# )

AC_CONFIG_FILES(
	[display/Makefile
	environment/Makefile
	simulator/Makefile
	utilities/Makefile]
)

AC_CONFIG_FILES(
	[Makefile]
)
AC_OUTPUT

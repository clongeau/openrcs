AC_INIT([OpenRCS],[4.2.0],[Charles Longeau <chl@openbsd.org>],[OpenRCS])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S

AC_CHECK_HEADERS([sys/dirent.h dirent.h sys/time.h utimes.h])
AC_CHECK_FUNCS([fgetln strlcat strlcpy strtonum])

#comes from sudo's configure.in
AC_CHECK_FUNCS(utimes, [AC_CHECK_FUNCS(futimes futimesat, [break])], [AC_CHECK_FUNCS(futime) AC_LIBOBJ(utimes)])


#from here everything comes from portable openssh configure.ac script
AC_SEARCH_LIBS(basename, gen, AC_DEFINE(HAVE_BASENAME, 1,
	[Define if you have the basename function.]))

AC_DEFINE([_GNU_SOURCE], [], [Enable GNU Extensions])

CFLAGS="$CFLAGS -Wall"

AC_CONFIG_HEADER(config.h)
AC_CONFIG_FILES([Makefile
		openbsd-compat/Makefile
		src/Makefile
		])

AC_OUTPUT 

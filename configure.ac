AC_INIT([OpenRCS],[4.2.0],[Charles Longeau <chl@openbsd.org>])
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

# this part comes from http://webcvs.freedesktop.org/stsf/stsf/configure.ac?revision=1.13
if test "$GCC" = "yes" ; then
    # set GCC compiler options that should work with all versions
    CFLAGS="${CFLAGS} -Wall -pedantic -fpic -Wno-long-long"
    SHAREDLIB_LDFLAGS="-shared ${SHAREDLIB_LDFLAGS}"
    DEPEND_CCFLAGS="-MM"

    # -std=c99 is only supported in later releases of GCC and causes
    # Linux headers to go into strict ANSI mode, dropping non-ANSI functions
    # so we have to fall back to -std=gnu99 if c99 doesn't work
    save_CFLAGS="${CFLAGS}"
    CFLAGS="${CFLAGS} -std=c99 -Werror-implicit-function-declaration"
    AC_MSG_CHECKING([whether GNU cc -std=c99 option works])
    AC_TRY_COMPILE(AC_INCLUDES_DEFAULT, [char *a; a = strdup("foo");],
    	AC_MSG_RESULT([yes]) ; CFLAGS="$save_CFLAGS -std=c99",
	AC_MSG_RESULT([no]) ; 
	CFLAGS="$save_CFLAGS -std=gnu99 -Werror-implicit-function-declaration"
    	AC_MSG_CHECKING([whether GNU cc -std=gnu99 option works])
	AC_TRY_COMPILE(AC_INCLUDES_DEFAULT, [char *a; a = strdup("foo");],
		AC_MSG_RESULT([yes]) ; CFLAGS="$save_CFLAGS -std=gnu99",
		AC_MSG_RESULT([no]) ; CFLAGS="$save_CFLAGS"))
fi

AC_DEFINE([_GNU_SOURCE], [], [Enable GNU Extensions])

AC_ARG_WITH(Werror,
	[  --with-Werror           Build main code with -Werror],
	[
		if test -n "$withval"  &&  test "x$withval" != "xno"; then
			werror_flags="-Werror"
			if test "x${withval}" != "xyes"; then
				werror_flags="$withval"
			fi
		fi
	]
)

dnl Adding -Werror to CFLAGS early prevents configure tests from running.
dnl Add now.
CFLAGS="$CFLAGS $werror_flags"

AC_CONFIG_HEADER(config.h)
AC_CONFIG_FILES([Makefile
		openbsd-compat/Makefile
		src/Makefile
		])

AC_OUTPUT 

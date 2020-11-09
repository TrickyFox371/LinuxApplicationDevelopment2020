AC_PREREQ([2.69])
AC_INIT(package_buf, 1)
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/buf.h])
AC_CONFIG_HEADERS([config.h])
AC_LANG(C)

PKG_CHECK_MODULES([CHECK],[check])

AC_PROG_CC

AC_CONFIG_FILES([Makefile test/Makefile src/Makefile])

AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])
AC_OUTPUT

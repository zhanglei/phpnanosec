dnl $Id$
dnl config.m4 for extension nanosec

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(nanosec, for nanosec support,
 [  --with-nanosec             Include nanosec support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(nanosec, whether to enable nanosec support,
[  --enable-nanosec           Enable nanosec support])

if test "$PHP_NANOSEC" != "no"; then
  PHP_SUBST(NANOSEC_SHARED_LIBADD)
  PHP_NEW_EXTENSION(nanosec, nanosec.c, $ext_shared)
fi

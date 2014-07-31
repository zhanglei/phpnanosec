dnl $Id$
dnl config.m4 for extension nanosec

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(nanosec, for nanosec support,
dnl Make sure that the comment is aligned:
dnl [  --with-nanosec             Include nanosec support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(nanosec, whether to enable nanosec support,
dnl Make sure that the comment is aligned:
dnl [  --enable-nanosec           Enable nanosec support])

if test "$PHP_NANOSEC" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-nanosec -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/nanosec.h"  # you most likely want to change this
  dnl if test -r $PHP_NANOSEC/$SEARCH_FOR; then # path given as parameter
  dnl   NANOSEC_DIR=$PHP_NANOSEC
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for nanosec files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       NANOSEC_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$NANOSEC_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the nanosec distribution])
  dnl fi

  dnl # --with-nanosec -> add include path
  dnl PHP_ADD_INCLUDE($NANOSEC_DIR/include)

  dnl # --with-nanosec -> check for lib and symbol presence
  dnl LIBNAME=nanosec # you may want to change this
  dnl LIBSYMBOL=nanosec # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $NANOSEC_DIR/lib, NANOSEC_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_NANOSECLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong nanosec lib version or lib not found])
  dnl ],[
  dnl   -L$NANOSEC_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(NANOSEC_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nanosec, nanosec.c, $ext_shared)
fi

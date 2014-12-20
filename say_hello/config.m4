dnl $Id$
dnl config.m4 for extension say_hello

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(say_hello, for say_hello support,
dnl Make sure that the comment is aligned:
dnl [  --with-say_hello             Include say_hello support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(say_hello, whether to enable say_hello support,
Make sure that the comment is aligned:
[  --enable-say_hello           Enable say_hello support])

if test "$PHP_SAY_HELLO" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-say_hello -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/say_hello.h"  # you most likely want to change this
  dnl if test -r $PHP_SAY_HELLO/$SEARCH_FOR; then # path given as parameter
  dnl   SAY_HELLO_DIR=$PHP_SAY_HELLO
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for say_hello files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SAY_HELLO_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SAY_HELLO_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the say_hello distribution])
  dnl fi

  dnl # --with-say_hello -> add include path
  dnl PHP_ADD_INCLUDE($SAY_HELLO_DIR/include)

  dnl # --with-say_hello -> check for lib and symbol presence
  dnl LIBNAME=say_hello # you may want to change this
  dnl LIBSYMBOL=say_hello # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SAY_HELLO_DIR/lib, SAY_HELLO_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SAY_HELLOLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong say_hello lib version or lib not found])
  dnl ],[
  dnl   -L$SAY_HELLO_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SAY_HELLO_SHARED_LIBADD)

  PHP_NEW_EXTENSION(say_hello, say_hello.c, $ext_shared)
fi

/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_say_hello.h"

/* If you declare any globals in php_say_hello.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(say_hello)
*/

/* True global resources - no need for thread safety here */
static int le_say_hello;

double getRadian(double degree)
{
	return degree * PI / 180.0;
}
PHP_FUNCTION(say_hello_func)
{
	double lng1;
	double lat1;
	double lng2;
	double lat2;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &lng1, &lat1, &lng2, &lat2) == FAILURE) {
		return;
	}

	double radLat1 = getRadian(lat1);
	double radLat2 = getRadian(lat2);
	double a = radLat1 - radLat2;
	double b = getRadian(lng1)- getRadian(lng2);
	double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
	s = s * 6378137.0; 

	//php_printf("Hello "me);

	RETURN_DOUBLE(s);
}
/*
PHP_FUNCTION(say_hello_func)
{
	char *name;
	int name_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		return;
	}

	php_printf("Hello %s!", name);

	RETURN_TRUE;
}
*/

ZEND_BEGIN_ARG_INFO(arginfo_say_hello_func, 0)
ZEND_END_ARG_INFO()
/* {{{ say_hello_functions[]
 *
 * Every user visible function must have an entry in say_hello_functions[].
 */
const zend_function_entry say_hello_functions[] = {
	PHP_FE(say_hello_func, arginfo_say_hello_func)
	{NULL, NULL, NULL} /* Must be the last line in say_hello_functions[] */
};
/* }}} */

/* {{{ say_hello_module_entry
 */
zend_module_entry say_hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"say_hello",
	say_hello_functions,
	NULL,
	NULL,
	NULL,		/* Replace with NULL if there's nothing to do at request start */
	NULL,	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(say_hello),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SAY_HELLO
ZEND_GET_MODULE(say_hello)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("say_hello.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_say_hello_globals, say_hello_globals)
    STD_PHP_INI_ENTRY("say_hello.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_say_hello_globals, say_hello_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_say_hello_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_say_hello_init_globals(zend_say_hello_globals *say_hello_globals)
{
	say_hello_globals->global_value = 0;
	say_hello_globals->global_string = NULL;
}
*/
/* }}} */


/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(say_hello)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "say_hello support", "enabled");
    php_info_print_table_row(2, "author", "liufabin"); /* Replace with your name */
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */



/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

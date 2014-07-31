/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
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

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_nanosec.h"

#ifdef PHP_WIN32
#include "win32/time.h"
#else
#include <sys/time.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* If you declare any globals in php_nanosec.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(nanosec)
*/

/* True global resources - no need for thread safety here */
static int le_nanosec;

/* {{{ nanosec_functions[]
 *
 * Every user visible function must have an entry in nanosec_functions[].
 */
const zend_function_entry nanosec_functions[] = {
	PHP_FE(phpnanosec, NULL)
	PHP_FE_END	/* Must be the last line in nanosec_functions[] */
};
/* }}} */

/* {{{ nanosec_module_entry
 */
zend_module_entry nanosec_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"nanosec",
	nanosec_functions,
	PHP_MINIT(nanosec),
	PHP_MSHUTDOWN(nanosec),
	PHP_RINIT(nanosec),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(nanosec),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(nanosec),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_NANOSEC_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NANOSEC
ZEND_GET_MODULE(nanosec)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("nanosec.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_nanosec_globals, nanosec_globals)
    STD_PHP_INI_ENTRY("nanosec.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_nanosec_globals, nanosec_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_nanosec_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_nanosec_init_globals(zend_nanosec_globals *nanosec_globals)
{
	nanosec_globals->global_value = 0;
	nanosec_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(nanosec)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(nanosec)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(nanosec)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(nanosec)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(nanosec)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "nanosec support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


PHP_FUNCTION(phpnanosec)
{
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t);
	char *strg;

	len = spprintf(&strg, 0, "%Lf", (long double)(t.tv_sec + t.tv_nsec*0.000000001));
	RETURN_STRINGL(strg, len, 0);
}


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

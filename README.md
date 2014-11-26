PHP Nanoseconds PECL extension
===============================

This extension  provide PHP programmer the ability to retrive time with nanoseconds,
If you are building a realtime webapp, you may need this . such as process orders.

This PHP PECL extension tested above PHP 5.4+ and working well on Linux platform,
Tested with (CentOS 6.* and CentOS 7.*)


```bash
/usr/bin/phpize
./configure --with-nanosec --enable-nanosec --with-php-config=/usr/bin/php-config
make && make install
```


call nanosec function in PHP
```php
<?php
echo nanosec();
```

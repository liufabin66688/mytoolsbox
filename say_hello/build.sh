/usr/local/xzsoft/php/bin/phpize
./configure --with-php-config=/usr/local/xzsoft/php/bin/php-config
make
make install
/sbin/service php-fpm restart
/sbin/service nginx restart

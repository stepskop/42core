<?php
define( 'DB_NAME', 'DATABASE_NAME' );
define( 'DB_USER', 'DATABASE_USER' );
define( 'DB_PASSWORD', 'DATABASE_PASSWORD' );
define( 'DB_HOST', 'maria_db' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

define( 'WP_ALLOW_REPAIR', true );

define('AUTH_KEY',         'bVp.p#]go)/Ed@^Ytsf-*T22kNQ{!5Jh,%P+UsrSwGf|[49a%o1Q3=TIZiqLc&@1');
define('SECURE_AUTH_KEY',  '=Og}%zj}zP+o!3SF;8.OphT5-![yVxd,t4c?U/|>T|u^7O d#cDV6;Fy_1d=UD-z');
define('LOGGED_IN_KEY',    'u7We{08,+5YWIuCal+lGB0;@A?IV,$Eul2+_d[?ZRV6wa](oO#}WLbxt:S5.Z-/x');
define('NONCE_KEY',        ')+jrdmq=;w$6hd($U`?+j~NT|~#2SXaG[?P}0t8qQ$bIW qY!.)4Vd(TSH1<XI((');
define('AUTH_SALT',        '$07Xlx424T*;+*]dMzu8%)M[p*+fV+-[}$s-t*}m.L0g<wb==`D{kt+[_a(W7QwJ');
define('SECURE_AUTH_SALT', '-jrA@LF-WpY:/TniT:Yk$x4;IC6*XYy+KFx]Ps3DGRg|^+ 0j d<@%3x{T:rvo:z');
define('LOGGED_IN_SALT',   'StRqof2M95oib+-5QX8wqA@`K{C5>jy54m^M}dMGwuo$-T7O5=Y&|qsi0b9vGJ]G');
define('NONCE_SALT',       '41[QG:4<<@7Ps,&Iw:-.Y0$|K6r9ACF JjAwCNW#A8-htt|=1L-As.2)u/k|yP[d');

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );


define('WP_CACHE', true);

$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

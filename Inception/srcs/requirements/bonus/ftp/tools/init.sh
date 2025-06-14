#!/bin/bash

mkdir -p /var/run/vsftpd/empty

useradd -m -d /var/www/html -s /bin/bash $FTP_USER
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

chown -R $FTP_USER:$FTP_USER /var/www/html

# Use default config and only modify what's needed for write access
sed -i 's/#write_enable=YES/write_enable=YES/' /etc/vsftpd.conf
echo "allow_writeable_chroot=YES" >> /etc/vsftpd.conf
echo "pasv_enable=YES" >> /etc/vsftpd.conf
echo "pasv_min_port=21100" >> /etc/vsftpd.conf
echo "pasv_max_port=21110" >> /etc/vsftpd.conf

vsftpd /etc/vsftpd.conf
#!/bin/bash
chmod 755 /media -R
chmod 755 /home/* -R
chmod 4755 /bin/su
chmod 4755 /usr/bin/sudo
killall -u test
userdel test
reboot

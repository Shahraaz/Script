#!/usr/bin/bash
# echo "---"
# tail /var/log/kerio-kvc/error.log
# echo "---"
# tail /var/log/kerio-kvc/debug.log
echo "---"
sudo /etc/init.d/kerio-kvc start
echo "---"
echo "cat /var/log/kerio-kvc/error.log"
echo "---"
tail -n 5 /var/log/kerio-kvc/error.log
echo "---"
echo "cat /var/log/kerio-kvc/debug.log"
echo "---"
tail -n 15 /var/log/kerio-kvc/debug.log

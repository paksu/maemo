#
# Regular cron jobs for the qthello package
#
0 4	* * *	root	[ -x /usr/bin/qthello_maintenance ] && /usr/bin/qthello_maintenance

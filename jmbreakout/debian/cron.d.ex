#
# Regular cron jobs for the jmbreakout package
#
0 4	* * *	root	[ -x /usr/bin/jmbreakout_maintenance ] && /usr/bin/jmbreakout_maintenance

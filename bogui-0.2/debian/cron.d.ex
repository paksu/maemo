#
# Regular cron jobs for the bogui package
#
0 4	* * *	root	[ -x /usr/bin/bogui_maintenance ] && /usr/bin/bogui_maintenance

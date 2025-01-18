we are looking for file that are from the targeted user (flag00)

* find / -group flag00  2>/dev/null

	/usr/sbin/john

	/rofs/usr/sbin/john
we got 2 file

* cat /usr/sbin/john

	cdiiddwpgswtgt <-- too short to be a password


cdiiddwpgswtgt translated to nottoohardhere (cesar cipher rotated by 11)


* su flag00 with password nottoohardhere

*	getflag --> x24ti5gi3x0ol2eh4esiuxias

*	su level01 with password  x24ti5gi3x0ol2eh4esiuxias

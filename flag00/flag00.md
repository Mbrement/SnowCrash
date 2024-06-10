find / -group flag00  2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
------
cat /usr/sbin/john
cdiiddwpgswtgt <-- too short to be a password
--------------
cdiiddwpgswtgt translated to nottoohardhere (cesar cipher rotated by 11)
--------
su flag00 pwd nottoohardhere
---
getflag --> x24ti5gi3x0ol2eh4esiuxias
---
su level01 pwd x24ti5gi3x0ol2eh4esiuxias
---
done
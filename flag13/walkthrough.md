* I try to linpeas it, show me dirty cow (exploit of 2016, 3 year after the creation of this project), I keep it here

* the program check if the uid is 4242 (id -u <username>), run lldb, b getuid, s, register write eax 4242, thread return, c, you have the flag


		flag 14 
		open getflag in gdb, 
		catch syscall ptrace
		set ($eax) = 0 
		continue
		end
		b getuid
		s
		set $eax = 3014
		c

2A31L79asukciNyi8uppkEuSx

7QiHafiNa3HVozsaXjaw
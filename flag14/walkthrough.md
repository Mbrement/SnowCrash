* I try to linpeas it, show me dirty cow (exploit of 2016, 3 year after the creation of this project), I keep it here but didn't use the exploit, as it wasn't intended

* we have nothing else,  so I try to debug gdb, it trap ptrace. 

* it use the uid to check wich user use it, so I get the uid of flag14 (id -u <username>)

* open getflag in gdb,
 
		catch syscall ptrace
		command 1 
		set ($eax) = 0 
		continue
		end
		b getuid
		s
		set $eax = 3014
		c
7QiHafiNa3HVozsaXjaw
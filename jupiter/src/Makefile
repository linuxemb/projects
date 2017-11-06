all: jupiter


jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter"
	@echo "*** all Test passed ***"
clean:
	-rm jupiter
install:
	install -d $(prifix)/bin
	install -m 0755 jupiter $(prefix)/bin
# 2nd way of  install
	
#	cp jupiter /usr/bin
#	chown root:root /usr/bin/jupiter
#	chmod +x /usr/bin/jupiter
.PHONE: all clean check



# See LICENSE file for copyright and license details.

PREFIX = /usr

all: 
	go build -o cputemp

clean:
	rm -f cputemp

install:
	mkdir -p ${PREFIX}/bin
	cp -f cputemp ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/cputemp

uninstall:
	rm -f ${PREFIX}/bin/cputemp

.PHONY: all clean install uninstall

# See LICENSE file for copyright and license details.

PREFIX = /usr

all: 
	go build -o fzf cmd/fzf.go

clean:
	rm -f fzf

install:
	chmod 755 fzf
	mkdir -p ${PREFIX}/bin
	cp -f fzf ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/fzf

.PHONY: all clean install uninstall

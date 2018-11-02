TARGET = /usr/local/bin
BINARY = docker-compose

all: 

clean:

install:
	mkdir -p ${TARGET}
	cp -f ${BINARY} ${TARGET}
	chmod 755 ${TARGET}/${BINARY}

uninstall:
	rm -f ${TARGET}/${BINARY}

.PHONY: all clean install uninstall

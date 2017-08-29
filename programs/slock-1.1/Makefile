# slock - simple screen locker
# See LICENSE file for copyright and license details.

include config.mk

SRC = slock.c
OBJ = ${SRC:.c=.o}

all: slock

.c.o:
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

slock: ${OBJ}
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@rm -f slock ${OBJ} slock-${VERSION}.tar.gz

dist: clean
	@mkdir -p slock-${VERSION}
	@cp -R LICENSE Makefile README config.mk ${SRC} slock-${VERSION}
	@tar -cf slock-${VERSION}.tar slock-${VERSION}
	@gzip slock-${VERSION}.tar
	@rm -rf slock-${VERSION}

install: all
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f slock ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/slock
	@chmod u+s ${DESTDIR}${PREFIX}/bin/slock

uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/slock

.PHONY: all clean dist install uninstall

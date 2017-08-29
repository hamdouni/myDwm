# dmenu - dynamic menu
# See LICENSE file for copyright and license details.

include config.mk

SRC = dmenu.c draw.c stest.c
OBJ = ${SRC:.c=.o}

all: dmenu stest

.c.o:
	@${CC} -c $< ${CFLAGS}

${OBJ}: config.mk draw.h

dmenu: dmenu.o draw.o
	@${CC} -o $@ dmenu.o draw.o ${LDFLAGS}

stest: stest.o
	@${CC} -o $@ stest.o ${LDFLAGS}

clean:
	@rm -f dmenu stest ${OBJ} dmenu-${VERSION}.tar.gz

dist: clean
	@mkdir -p dmenu-${VERSION}
	@cp LICENSE Makefile README config.mk dmenu.1 draw.h dmenu_run stest.1 ${SRC} dmenu-${VERSION}
	@tar -cf dmenu-${VERSION}.tar dmenu-${VERSION}
	@gzip dmenu-${VERSION}.tar
	@rm -rf dmenu-${VERSION}

install: all
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f dmenu dmenu_run stest ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/dmenu
	@chmod 755 ${DESTDIR}${PREFIX}/bin/dmenu_run
	@chmod 755 ${DESTDIR}${PREFIX}/bin/stest
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < dmenu.1 > ${DESTDIR}${MANPREFIX}/man1/dmenu.1
	@sed "s/VERSION/${VERSION}/g" < stest.1 > ${DESTDIR}${MANPREFIX}/man1/stest.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/dmenu.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/stest.1

uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/dmenu
	@rm -f ${DESTDIR}${PREFIX}/bin/dmenu_run
	@rm -f ${DESTDIR}${PREFIX}/bin/stest
	@rm -f ${DESTDIR}${MANPREFIX}/man1/dmenu.1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/stest.1

.PHONY: all clean dist install uninstall

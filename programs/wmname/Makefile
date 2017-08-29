# wmname - prints/sets the WM name

include config.mk

SRC = wmname.c
OBJ = ${SRC:.c=.o}

all: wmname

.c.o:
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

wmname: ${OBJ}
	@${LD} -o $@ ${OBJ} ${LDFLAGS}
	@strip $@

clean:
	@rm -f wmname ${OBJ} wmname-${VERSION}.tar.gz

dist: clean
	@mkdir -p wmname-${VERSION}
	@cp -R LICENSE Makefile README config.mk wmname.1 ${SRC} wmname-${VERSION}
	@tar -cf wmname-${VERSION}.tar wmname-${VERSION}
	@gzip wmname-${VERSION}.tar
	@rm -rf wmname-${VERSION}

install: all
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f wmname ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/wmname
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < wmname.1 > ${DESTDIR}${MANPREFIX}/man1/wmname.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/wmname.1

uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/wmname

.PHONY: all clean dist install uninstall

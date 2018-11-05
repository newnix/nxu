.POSIX:

PREFIX = ${HOME}
DESTDIR = ${PREFIX}/bin
MUSER = ${USER}
GROUP = ${USER}
TARGET = nxls
HELP = -h
SRC = nxls.c
DBG = gdb

CFLAGS = -Os -fpic -fpie -fPIE -fPIC -Wall -Wextra -std=c99 -pedantic
LDFAGS = -Wl,relro,now,combreloc,gc-sections

CC = clang-devel
LD = ld.lld-devel

debug: ${TARGET}.c
	$(CC) -g${DBG} ${CFLAGS} ${TARGET}.c -o ${TARGET}
	@mkdir -pv ${DESTDIR}
	@cp -vf ${TARGET} ${DESTDIR}/${TARGET}
	@rm -f ${TARGET}
	@${DESTDIR}/${TARGET} ${HELP}

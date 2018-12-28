.POSIX:

## Basic env vars
MUSER = ${SUER}
GROUP = ${USER}
PREFIX = ${HOME}
DESTDIR = /bin/c/
MODE = 0755
TARGET = nxls
SRC = nxls.c

## Include and Lib search paths
INCS = -I. -I/usr/include -I/usr/local/include
LIBS = -L. -L/usr/lib -L/usr/local/lib

## Some build related flags
DBG = gdb
DBGFLAGS = -g${DBG}
CLANGFLAGS = -Weverything -Oz 
GCCFLAGS = -Os
## Pass this to the linker
LDFLAGS = --gc-sections,--icf=all
## Actual flags used during compilation
CFLAGS = ${CLANGFLAGS} -Wall -Wextra -pedantic -std=c99 -fpic -fpie -fPIC -fPIE\
				 -march=native -mtune=native -z relro -z now -z combreloc -Wl,${LDFLAGS}\
				 -pipe -fstrict-aliasing

## Which toolchain to use
## change the CLANGFLAGS to GCCFLAGS if switching from clang to gcc
CC = clang-devel
LD = lld

## The flag for invoking usage()
HELP = -h

## "help" make target
help:
	@printf "Build configuration for %s:\n" "${TARGET}"
	@printf "\nPREFIX:\t%s\nDIR:\t%s\nINST:\t%s\nOWNER:\t%s\nGROUP:\t%s\nMODE:\t%s\nCC:\t%s\nLD:\t%s\nCFLAGS:\t%s\nINCS:\t%s\nLIBS:\t%s\n\n"\
		"${PREFIX}" "${DESTDIR}" "${PREFIX}${DESTDIR}${TARGET}" "${MUSER}"\
		"${GROUP}" "${MODE}" "${CC}" "${LD}" "${CFLAGS}" "${INCS}" "${LIBS}"

build: ${SRC}
	$(CC) -o $(TARGET) $(CFLAGS) $(INCS) $(LIBS) ${SRC}

build-dbg: ${SRC}
	$(CC) -o $(TARGET) $(DBGFLAGS) $(CFLAGS) $(INCS) $(LIBS) ${SRC}

debug: build-dbg
	@mkdir -p ${PREFIX}${DESTDIR}
	@chown ${MUSER}:${GROUP} ${TARGET}
	@chmod ${MODE} ${TARGET}
	@cp -fp ${TARGET} ${PREFIX}${DESTDIR}
	@rm -f ${TARGET}
	@printf "\n\n"
	$(PREFIX)$(DESTDIR)$(TARGET) $(HELP)

install: build
	@rm -f ${PREFIX}${DESTDIR}${TARGET}
	@strip -s ${TARGET}
	@mkdir -p ${PREFIX}${DESTDIR}
	@chown ${MUSER}:${GROUP} ${TARGET}
	@chmod ${MODE} ${TARGET}
	@cp -fp ${TARGET} ${PREFIX}${DESTDIR}
	@rm -f ${TARGET}
	@printf "\n\n"
	$(PREFIX)$(DESTDIR)$(TARGET) $(HELP)

uninstall: ${PREFIX}${DESTDIR}${TARGET}
	@rm -f ${PREFIX}${DESTDIR}${TARGET}

rebuild: uninstall debug

reinstall: uninstall install

run:
	${PREFIX}${DESTDIR}${TARGET} $@

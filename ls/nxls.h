/* 
 * This file simply contains function definitions for those found in nxls.c
 */

#define __NXLS_H__
#ifndef NXLS_TARGETS_
#include "targets.c"
#endif

/* Some definitions for later use */
#define DRE '/'
#define EXE '*'
#define LNK '@'

typedef struct _List {
	struct dirent *entry;
} List;

/* Function declarations */
int targets(char **arglist, uint16_t flags);
int buildlist(struct dirent *entry, int (*callback)(List *list));
int xls(List *list);
int _nxalphasort(List *list);
int sizesort(List *list);
int dotstrip(List *list);
int statdata(List *list);
int fsappend(List *list);
static void __attribute__((noreturn)) usage(void);

static void
__attribute__((noreturn)) usage(void) {
	fprintf(stdout, "nxls: List directory contents\n"
			"\t-a Include dotfiles\n"
			"\t-f Print absolute paths\n"
			"\t-h This message\n"
			"\t-l \"Long\" output\n"
			"\t-r Rucurse into child directories\n"
			"\t-s Sort by size\n"
			"\t-F Append file type symbols\n"
			"\t-H Human friendly sizes\n"
			"\t-S Dump stat(2) struct info\n"
			"\t-0 NULL terminate each listing\n"
			"\t-1 One entry per line\n");
	exit(0);
}

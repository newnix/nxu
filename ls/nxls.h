/* 
 * This file simply contains function definitions for those found in nxls.c
 */

#include <sys/types.h>
#define __NXLS_H__

/* Some definitions for later use */
#define DRE '/'
#define EXE '*'
#define LNK '@'

#include <sys/syslimits.h>

typedef struct _Item {
	struct dirent *entry;
	struct stat *estat;
} item __packed;

typedef struct _List {
	item **entry; /* dynamic array of item structs */
	struct _List *parent; /* pointer to the parent List item */
	struct _List *child; /* pointer to the next List (only useful with the -r flag) */
	uint16_t items; /* holds the count of items in the entry array */
	unsigned int (*addEntry)(item *entry); /* I guess this will provide similar functionality as member functions in OOP, may need to be broken out */
} List __packed;

extern char *__progname;

/* Function declarations */
int targets(char **arglist, uint16_t flags);
int buildlist(struct dirent *entry, int (*callback)(List *list));
int xls(List *list);
int _nxalphasort(List *list);
int sizesort(List *list);
int dotstrip(List *list);
int statdata(List *list);
int fsappend(List *list);

/* usage declaration */
static void __attribute__((noreturn)) usage(void);

static void
__attribute__((noreturn)) usage(void) {
	fprintf(stdout, "%s: List directory contents\n"
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
			"\t-1 One entry per line\n",
			__progname);
	exit(0);
}

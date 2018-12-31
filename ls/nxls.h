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
	item **entries; /* dynamic array of item structs */
	struct _List *parent; /* pointer to the parent List item */
	struct _List *child; /* pointer to the next List (only useful with the -r flag) */
	uint16_t items; /* holds the count of items in the entry array */
	unsigned int (*addEntry)(item *entry); /* I guess this will provide similar functionality as member functions in OOP, may need to be broken out */
} List __packed;

/* 
 * The List tree should turn out something like this: 
 *
 * List->entries->entry->d_name; - item name
 * List->parent; - the parent directory of the given entry
 * List->child; - child directories of the List structure
 * List->items; - count of directory entries in the entry array
 * List->addEntry(item *entry); - Provided this works as intended, it's a function to update the struct with the new entry
 */
extern char *__progname;

/* Function declarations */
int targets(char **arglist, unsigned int flags);
int buildlist(struct dirent *entry, int (*callback)(List *list));
int xls(List *list);
int _nxalphasort(List *list);
int sizesort(List *list);
int dotstrip(List *list);
int statdata(List *list);
int fsappend(List *list);
/* this may need to be revisited, but the idea is to generate an in-memory tree of the information we're going to display */
int listgen(List *list);
/* usage declaration */
void __attribute__((noreturn)) usage(void);

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

/* Item struct declaration */
/* 
 * A dirent * has the following important members:
 * d_namelen - length of the entry's name
 * d_name - name of the entry
 * d_type - filetype
 */
typedef struct _Item {
	struct dirent *entry;
	struct stat *estat;
} item;

/* List struct declaration */
typedef struct _List {
	struct _List *parent;
	struct _List *children;
	struct _Item *entries;
	unsigned long childcount;
} list;

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
int buildlist(struct dirent *entry, int (*callback)(list *tlist));
int xls(list *tlist);
int _nxalphasort(list *tlist);
int sizesort(list *tlist);
int dotstrip(list *tlist); 
int statdata(list *tlist);
int fsappend(list *tlist);
int listdump(list *tlist);
/* this may need to be revisited, but the idea is to generate an in-memory tree of the information we're going to display */
int listgen(list *tlist);
/* usage declaration */
void __attribute__((noreturn)) usage(void);

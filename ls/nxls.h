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

/* 
 * This is a composite struct to allow us to operate on the info found
 * both in the stat struct and the dirent struct, these will only be filled
 * if the user demands it via the related flags
 */
typedef struct _List_Item {
	struct stat *statptr;
	struct dirent *dptr;
} item;

/* 
 * This struct will be used to form a tree of entries in the specified directories,
 * which will allow additional transformations as desired by the user, such as allowing
 * an ascii tree to be printed, with or without additional data if so requested and 
 * such functionality is ever added
 */
typedef struct _List {
	struct _List *parent; /* NULL if top of the tree, will not hold ".." */
	struct _List *childdir; /* Only populated when recursion is desired, allows populating subdirectories in the same structure */
	struct _List_Item *items; /* array of items in the current directory */
	uint64_t childcount; /* unlikely to actually need such a large amount of space, used to possibly make certain operations easier */
} list;

/* necessary functions */
int modlist(int (*modfunc), list *listptr);
/* usage declaration */
void __attribute__((noreturn)) usage(void);

/* 
 * define targets()
 */
#define NXLS_TARGETS_

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef __NXLS_H__
#include "nxls.h"
#endif
/*
 * this function, and any related helpers that may need to be created as this idea is fleshed out
 * will be to scan through **argv, which will build a List structure tree, which 
 * will have the potential for being built recursively and manipulated to match the user demands.
 * This then gets transferred to a single buffer, possibly in sections due to size matters,
 * which then gets printed out to stdout
 */

int
targets(char **arglist, unsigned int flags) {
	list targetlist;
	/* Initialize the list to refer to itself */
	targetlist.parent = &targetlist;
	targetlist.children = &targetlist;
	targetlist.entries = NULL;
	targetlist.childcount = 0;
	DIR *dirp;
	struct dirent *direp;
	int *callback1;

	direp = NULL;
	dirp = NULL;

	if (*arglist != NULL) {
		/* Print the current directory */
		for (; *arglist != NULL; arglist++) {
			if ((dirp = opendir(*arglist)) != NULL) {
				fprintf(stdout, "Opened %s (%p)\n", *arglist, dirp);
				for (direp = readdir(dirp); direp != NULL; direp = readdir(dirp)) {
					/* this needs to add the dirent pointer to targetlist.entry */
					/*
					 * Most likely needs to be reworked later, but this should illustrate intent at this time, 
					 * take the dirent struct and use it to generate more nodes in the *List tree structure
					 * Likely need to rethink the callback to allow the drent to be passed in, or an item 
					 * struct pointer
					 */
					if (buildlist(direp, dumplist(&targetlist)) != 0) {
						fprintf(stderr, "[%s:%d] Unable to add %s to list\n", __FILE__, __LINE__, direp->d_name);
					}
				}
			} else {
				fprintf(stderr, "Cannot open %s\n", ".");
			}
		}
	} else {
		fprintf(stderr, "Arglist is NULL\n");
		return(0);
	}
	return(0);
}

int
dumplist(list *tlist) {
	fprintf(stdout,"list->parent:\t%p\nlist->children:\t%p\nlist->entries:\t%p\nlist->childcount:\t%lu\n\n",
			tlist->parent, tlist->children, tlist->entries, tlist->childcount);
	return(0);
}

int
buildlist(struct dirent *entry, int (*callback)(list *tlist)) {
	int retcode;
	fprintf(stdout, "Working with %s\n", entry->d_name);
	retcode = callback;
	return(retcode);
}

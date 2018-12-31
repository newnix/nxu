/* 
 * define targets()
 */
#define NXLS_TARGETS_

/*
 * this function, and any related helpers that may need to be created as this idea is fleshed out
 * will be to scan through **argv, which will build a List structure tree, which 
 * will have the potential for being built recursively and manipulated to match the user demands.
 * This then gets transferred to a single buffer, possibly in sections due to size matters,
 * which then gets printed out to stdout
 */

int
targets(char **arglist, unsigned int flags) {
	List targetlist;
	DIR *dirp;
	struct dirent *direp;

	direp = NULL;
	dirp = NULL;

	if (*arglist != NULL) {
		/* Print the current directory */
		if ((dirp = opendir(".")) != NULL) {
			for (; direp != NULL; direp = readdir(dirp)) {
				/* this needs to add the dirent pointer to targetlist.entry */
				/*
				 * Most likely needs to be reworked later, but this should illustrate intent at this time, 
				 * take the dirent struct and use it to generate more nodes in the *List tree structure
				 * Likely need to rethink the callback to allow the drent to be passed in, or an item 
				 * struct pointer
				 */
				if (buildlist(direp, listgen(&targetlist)) != 0) {
					fprintf(stderr, "[%s:%d] Unable to add %s to list\n", __FILE__, __LINE__, direp->d_name);
				}
			}
		} else {
			fprintf(stderr, "Cannot open %s\n", ".");
		}
	} else {
		for (; *arglist != NULL; arglist++) {
			/* dead simple tracking string */
			fprintf(stdout, "[%s:%d] Adding %s to target list\n", __FILE__, __LINE__, *arglist);
		}
	}
	return(0);
}

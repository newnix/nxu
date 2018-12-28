/* 
 * define targets()
 */
#define NXLS_TARGETS_

int
targets(char **arglist, uint16_t flags) {
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

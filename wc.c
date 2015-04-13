// wc.c

// NOTE: POSIX says wc counts the number of \n's,
// so thats what we are doing.

#include <stdio.h>

#define isblank(c) (((c)==' ') || ((c) == '\n') || ((c) == '\t'))

int main(int argc, char **argv){

	FILE *fd;
	int c;
	unsigned nls = 0;
	unsigned words = 0;
	unsigned cs = 0;
	int w = 0; // does buf points to a word?

	if(argc > 2){
		fprintf(stderr, "invalid args\n");
		return -1;
	}
	if(argc == 1){
		fd = stdin;
	}else if((fd = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Can't open file:  %s\n", argv[1]);
		return -1;
	}
	while((c = fgetc(fd)) != EOF){
		cs++;
		if(!isblank(c)){
			if(!w){
				words++;
				w = 1;
			}
		}else{
			w = 0;
		}
		if(c == '\n')
			nls++;
	}
	fclose(fd);
	printf("Bytes: %d\n", cs);
	printf("Lines: %d\n", nls);
	printf("Words: %d\n", words);
	return 0;
}

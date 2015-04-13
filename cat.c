// cat.c

#include <stdio.h>

#define BUFSIZE 65536

int main(int argc, char **argv){

	char buf[BUFSIZE+1];
	FILE *fd;

	if(argc > 2){
		puts("invalid arguments");
	}else if(argc == 1){
		fd = stdin;
	}else if((fd = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Can't open file:  %s\n", argv[1]);
		return -1;
	}
	while(1){
		int len = fread(buf, 1, BUFSIZE, fd);
		if(ferror(fd)){
			perror("Error");
			fclose(fd);
			return -1;
		}
		buf[len] = '\0';
		printf("%s", buf);
		if(feof(fd))
			break;
	}
	fclose(fd);
	return 0;
}

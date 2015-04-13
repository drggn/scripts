// grep.c
// toy grep implementation. only uses stdio.
// initially written as a homework assingment

#include <stdio.h>

#define BYTES 256
#define BUFSIZE 65536

void mktbl(char *pat, int *tbl, int len){
	for(int i = 0; i < BYTES; i++)
		tbl[i] = len;
	for(int i = 0; i < len-1; i++)
		tbl[(int)pat[i]] = (len - 1) - i;
}

int main(int argc, char **argv){
	FILE *fd;
	char buf[BUFSIZE];
	int tbl[BYTES];
	int len;
	int bsiz;
	int i;
	char *pat;
	int last = 0;
	int pos = 0;

	if(argc < 2){
		fprintf(stderr, "invalid args\n");
		return -1;
	}
	pat = argv[1];
	len = strlen(argv[1]);
	mktbl(argv[1], tbl, len);

	if(argc == 2){
		fd = stdin;
	}else{
		fd = fopen(argv[2], "r");
		if(!fd){
			fprintf(stderr, "Can't read file: %s\n", argv[2]);
			return -1;
		}
	}

 loop:
	// read a block
	bsiz = fread(buf, 1, BUFSIZE-1, fd);
	if(ferror(fd)){
		perror("Error");
		fclose(fd);
		return -1;
	}
	if(feof(fd)){
		last = 1;
	}else{
		bsiz--;
		while(buf[bsiz] != '\n' && buf+bsiz != buf)
			bsiz--;
		if(buf+bsiz == buf){
			fprintf(stderr, "Line to long\n");
			return -1;
		}
	}
	buf[bsiz] = '\0';
	// we don't want to split lines
	pos += bsiz;
	fseek(fd, pos, SEEK_SET);

	i = len - 1;
	// horspool
	while(i < bsiz){
		int j = len - 1;
		while((j >= 0) && (buf[i] == pat[j])){
			i--;
			j--;
		}
		if(j<0){
			char *bol = buf + (i+1);
			char *eol = buf + (i+1);

			while((*bol != '\n') && (*bol != '\0') && (bol != buf))
				bol--;
			while((*eol != '\n') && (eol != (buf + bsiz)))
				eol++;
			*eol = '\0';
			if(*bol == '\n' || *bol == '\0')
				bol++;
			printf("%s\n", bol);
			i = (eol-buf)+1;
			continue;
		}
		int off = tbl[(int)buf[i]];
		i += off;
	}
	// did we read the last chunk?
	if(last)
		return 0;

	goto loop;
}

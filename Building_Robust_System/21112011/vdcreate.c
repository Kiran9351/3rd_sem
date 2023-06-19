#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "math.h"

typedef struct SB{
	long size_disk;
	int size_block;
	int size_fmd;
} SB;

typedef struct FMD {
	char filename[255];
	int file_size;
	int *fp;
} FMD;

void vdCreate(char *filename, int size, char b) {
	SB *sb = (SB *)malloc(sizeof(struct SB));
	if(b == 'M') {
		sb->size_disk = size*1024*1024;
	}
	if(b == 'G') {
		sb->size_disk = size*1024*1024*1024;
	}
	sb->size_block = 1024;
	int no_blocks = my_ceil((double)sb->size_disk/sb->size_block);
	int md_bytes = my_ceil((double)no_blocks/8);
	int sb_size = sizeof(struct SB);
	int flag_bytes = md_bytes;
	int no_blocks_flags;
	int buf_size = md_bytes;
	unsigned char *buf = (unsigned char *)malloc(sizeof(unsigned char) * buf_size);
	nt d;
	char ch = '\0';
	d = open(filename, O_CREAT | O_WRONLY, 00700);
	lseek(d, sb->size_disk, SEEK_SET);
	write(d, &ch, 1);
	lseek(d, 0, SEEK_SET);
	int n;
	int i = 0;
	while(i < sizeof(struct SB)) {
		buf[i] = ((char *)sb)[i];
		i++;
	}
	n = write(d, buf, sizeof(struct SB));
	if(flag_bytes > 1024) {
		no_blocks_flags = my_ceil((double)flag_bytes/sb->size_block);
	}
	else if(flag_bytes < 1024) {
		no_blocks_flags = 1;
	}
	else {
		no_blocks_flags = 2;
	}
	i = 0;
	while(i < flag_bytes) {
		buf[i] = 0xff;
		i++;
	}
	
	i = 0;
	while(no_blocks_flags >= 0) {
		buf[i] >>= no_blocks_flags;
		i++;
		no_blocks_flags -= 8;
	}
	n = write(d, buf, flag_bytes);
	close(d);
	
}

int main(int argc, char **argv) {
	printf("%ld\n", sizeof(SB));
	exit(1);

	if(argv[3][0] == 'M') {
		vdCreate(argv[1], atoi(argv[2]), argv[3][0]);
	}
	else if(argv[3][0] == 'G') {
		vdCreate(argv[1], atoi(argv[2]), argv[3][0]);
	}
}

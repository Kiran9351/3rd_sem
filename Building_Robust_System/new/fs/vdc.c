#include "vdc.h"

void vdcreate(int size_of_disk, int size_of_block)
{
	SB *sb = malloc(sizeof(SB));
	
	sb -> disk_size = size_of_disk * 1024 * 1024 * 1024;
	sb -> block_size = size_of_block * 1024;
	printf("Disk size = %ld\n",sb->disk_size);
	printf("Block size = %d\n",sb->block_size);
	
	char ch = '\0';
	int fd = open("disk",O_CREAT | O_WRONLY, 00777);
	lseek(fd, sb -> disk_size - 1, SEEK_SET);
	write(fd, &ch,1);

	//Total no. of blocks in disk
	int no_of_total_blocks = ceil((double)sb->disk_size/sb->block_size);
	printf("No. of total blocks = %d\n",no_of_total_blocks);

	//No. of bytes for flag bits
	int bytes_for_fbits = ceil((double)no_of_total_blocks/8);
	printf("Bytes for flag bits = %d\n",bytes_for_fbits);
	
	//No. of blocks for flag bits
	int blocks_for_fbits = ceil((double)bytes_for_fbits/sb->block_size);
	printf("Blocks for flag bits = %d\n",blocks_for_fbits);
	
	//Size of file metadata
	int size_of_fmd = ceil((double) sb -> disk_size/100)*3;
	printf("Size of file metadata = %d\n",size_of_fmd);

	//No. of blocks for file metadata
	int no_of_blocks_fmd = ceil((double)size_of_fmd / sb -> block_size);
	printf("No. of blocks for fmd = %d\n",no_of_blocks_fmd);
	
	int bytes_to_move = 0;
	bytes_to_move += (no_of_blocks_fmd * (sb->block_size));
	bytes_to_move += 1024;

	unsigned char *buff = (unsigned char*)malloc(sizeof(unsigned char) * sb -> block_size);
	
	lseek(fd,0,SEEK_SET);
	
	write(fd,sb,sizeof(SB));	
	
	lseek(fd,sb->block_size,SEEK_SET);
	
	for(int i = 0 ; i < sb -> block_size; i++)
	{
		buff[i] = 0xff;
	}

	for(int i = 0; i < blocks_for_fbits; i++)
	{
		write(fd,buff,sb->block_size);
	}

	bytes_to_move += (blocks_for_fbits * sb->block_size);
	printf("Bytes to move = %d\n",bytes_to_move);

	lseek(fd,sb->block_size,SEEK_SET);
	
	//Bits to make zero.
	int bytes_to_make_zero = (blocks_for_fbits + no_of_blocks_fmd + 1)/8;
	
	ch = 0x00;
	for(int i = 0; i < bytes_to_make_zero; i++)
	{
		write(fd,&ch,sizeof(char));
	}

	//Write all file metadatas 
	FMD *fmd = (FMD*)malloc(sizeof(FMD));
	fmd -> file_name[0] = '\0'; 
	fmd -> file_size = -1;
	fmd -> block_no = -1;	
	fmd -> flag = 0;

	lseek(fd,(blocks_for_fbits * 1024)+1024,SEEK_SET);

	for(int i = 0; i < (no_of_blocks_fmd * 4); i++)
	{
		write(fd,fmd,sizeof(fmd));
	}

}	

int main(int argc, char **argv)
{
	int size_of_disk = 0, size_of_block = 0;

	printf("Enter size of disk in GB = ");
	scanf("%d",&size_of_disk);
	
	printf("Enter size of block in kb = ");
	scanf("%d",&size_of_block);

	vdcreate(size_of_disk, size_of_block);

	return 0;
}

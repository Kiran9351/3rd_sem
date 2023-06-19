#include "vdc.h"

long find_fmd(long bytes_to_move_to_fmd, int no_of_blocks_fmd)
{
	int fd = open("disk",O_RDONLY);
	lseek(fd,bytes_to_move_to_fmd,SEEK_SET);
	
	FMD *fmd = (FMD*)malloc(sizeof(FMD));
	int size_of_fmd = sizeof(FMD);
	
	read(fd,fmd,sizeof(FMD));
	int i = 0;
	long bytes_to_move_to_found_fmd = 0;
	while(i < (no_of_blocks_fmd*4) && (fmd->flag != 0))
	{
		read(fd,fmd,sizeof(FMD));
		bytes_to_move_to_found_fmd += size_of_fmd;
		i++;
	}
	
	//Check this function.
	// We need fmd location, so that we can make changes in file.
	// That's why we need to return fmd location not fmd structure.
	return bytes_to_move_to_found_fmd;
}

long fmd_functions(char *file_name, long file_size, int block_size, int byte_to_move_to_fbits, long bytes_to_move_to_fmd, long bytes_for_fbits, int no_of_blocks_fmd)
{
	bool block_availability = check_blocks(long file_size, ing block_size, int bytes_to_move_to_fbits, long bytes_for_bits);
	
	if(block_availability == false)
	{
		printf("There are not enough blocks for file\n");metablock_no 
		return NULL;
	}
	
	int first_block = find_first_metablock(bytes_to_move_to_fbits, bytes_for_fbits);
	
	long bytes_to_move_to_found_fmd = find_fmd(bytes_to_move_to_fmd, no_of_blocks_fmd);
	
	lseek(fd,bytes_to_move_to_fmd + bytes_to_move_to_found_fmd,SEEK_SET);

	FMD *fmd = NULL;
	read(fd,fmd,sizeof(FMD));
	
	strcpy(fmd->file_name, file_name);
	fmd -> file_size = file_size;
	fmd -> flag = 1;
	fmd -> block_no = first_block;
	
	fmd = find_data_blocks(bytes_to_move_to_fbits, fmd, int block_size);
	
	lseek(fd,bytes_to_move_to_fmd + bytes_to_move_to_found_fmd,SEEK_SET);
	write(fd,fmd,sizeof(fmd));
	
	return bytes_to_move_to_found_fmd;
	
}

void insert_data(long bytes_to_move_to_found_fmd, long bytes_to_move_to_fmd, int block_size)
{
	int fd = open("disk", O_WRONLY);
	
	lseek(fd,bytes_to_move_to_fmd + bytes_to_move_to_found_fmd, SEEK_SET);
	
	FMD *fmd = NULL;
	read(fd,fmd,sizeof(FMD));
	
	lseek(fd,fmd->block_no * block_size, SEEK_SET);
	
	int no_of_blocks = ceil((double)fmd -> file_size/block_size);
	
	//We need buffer to store inserting data
	// then iterate on that buffer to insert data into disk.

	for(int i = 0; i < no_of_blocks; i++)
	{
		read
	}
}

int main()
{
        char file_name[100]
        long file_size = 0;

        printf("Enter file name = ");
        scanf(" %[^\n]s",file_name);

        printf("Enter file size in kb : ");
        scanf("%d",file_size);

        file_size = file_size * 1024;
    
        SB *sb = malloc(sizeof(SB));
     
        sb = (SB*)malloc(sizeof(SB));
            
        int fd = open("disk",O_RDONLY);
        read(fd,sb,sizeof(SB));
     
        long disk_size = sb -> disk_size;
        int block_size = sb -> block_size;
     
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

        int bytes_to_move_to_fbits = block_size;
        long bytes_to_move_to_fmd = block_size + bytes_for_fbits;
        long byte_to_move_to_end_of_fmd = bytes_to_move_to_fmd + size_of_fmd;

        //FMD Functions
        FMD *fmd = (FMD*)malloc(sizeof(FMD));
        int bytes_to_move_to_found_fmd = fmd_functions(file_name, file_size,block_size, bytes_to_move_to_fbits, bytes_to_move_to_fmd, byte_for_fbits,no_of_blocks_fmd)
	
	insert_data(bytes_to_move_to_found_fmd,bytes_to_move_to_fmd);

        return 0;
}



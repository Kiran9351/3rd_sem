#include "bitmap.h"

unsigned char *Bitmap_to_Array(char *diskname, int size_bitmap,int size_block) {
   int  d = open(diskname, O_RDONLY);
    
   // int sb_size = sizeof(struct SB);

    //SB *sb = (SB *)malloc(sb_size);

    //read(d, sb, sb_size);

    //int no_blocks = ceil((double)sb->size_disk/sb->size_block);
	//int md_bytes = (ceil((double)no_blocks/8)) + sb_size;
	//int flag_bytes = md_bytes - sb_size;
	//int size_bitmap = flag_bytes;

    unsigned char *bmap = (unsigned char *)malloc(sizeof(unsigned char) * size_bitmap);

    lseek(d, size_block, SEEK_SET);

    read(d, bmap, size_bitmap);

    return bmap;
}

int BitMap_isBitSet(unsigned char *bmap, int block_no) {
    // int entry_no = block_no / 8;
    // int bit_no = block_no % 8;
    // unsigned char e = bmap[block_no];
    // for(int i = 0; i < 8; i++) {
    //	int ret = (e) & (1 << (i));	
    //	if(ret != 0) {
    //  		return 1;
    //	}
    //	else {
    //  		return 0;
    //	}
    // }
    int count = 0;
    unsigned char e = bmap[block_no];
    for(int i = 0; i < 8; i++) {
    	if((e & (1 << i)) == (1 << i))
    		count++;
    }
    return count;
}

int BitMap_getFreeBlocks(unsigned char *bmap, int size_bitmap) {
    int i;
    int count = 0;
    for(i = 0; i < size_bitmap; i++) {
        // if(BitMap_isBitSet(bmap, i)) {
            count = count + BitMap_isBitSet(bmap, i);
        // }
    }
    return count;
}

int BitMap_set(unsigned char *bmap, int pos, int status) {
    int array_index = pos / 8;
    int offset = pos % 8;
    if (status) {
        return bmap[array_index] |= (status << (8 - 1 - offset));
    }
    else if (!status) {
        return bmap[array_index] &= ~(1 << (8 - 1 - offset));
    }
    else;
        // return ERROR_RESEARCH_FAULT;
}


int BitMap_indexToBlock(int entry, unsigned char bit_num) {
	int num = (entry * 8) + bit_num;
	return num;
}

unsigned char* find_blocks(int cnt, unsigned char *bmap, int blocks_for_file, int bytes_to_skip_to_first_block, int size_bitmap, int i,int j)
{
	int k = j+1, l = 0;
	
	unsigned char *buff = (unsigned char*)malloc(sizeof(unsigned char) * block_size);

	while(i < size_bitmap)
	{
		
		for(j = k; j < 8; j++)
		{
			if((e << (1 << j)) == (1 << j))
			{
				cnt++;
				buff[l] = (unsigned char)((i*8)+j);
				l++; 
				
				
				if(cnt == blocks_for_file)
				{
					i = size_bitmap;
					break;
				}
			}
		} 
		k = 0;
	}

	return buff;
}

unsigned char *write_to_fmd(unsigned char *bmap, int file_size, int block_size, int bytes_to_skip_to_fmd, int size_bitmap)
{
	int i = 0, j = 0, b = 0;

	while(i < size_bitmap)
	{
		e = bmap[i];
		for(j = 0; j < 8; j++)
		{
			if((e << (1 << j)) == (1 << i))
			{
				cnt = 1;
				b = i;
				i = size_bitmap;
				break;
			}
		}

		i++;
	}
	
	i = b;
	//lseek(fd,bytes_to_skip_to_fmd,SEEK_SET);
	
	//FMD *fmd = (FMD*)malloc(sizeof(FMD));
	//read(fd,fmd,sizeof(FMD));
	
	//fmd -> block_no = ((i*8)+j);
	
	//Bytes to skip for first block of file
	bytes_to_skip_to_first_block = fmd->block * 1024;
	
	//Assuming file_size is in bytes,
	int blocks_for_file = file_size/block_size;
	
	
	unsigned char *buff = (unsigned char*)malloc(sizeof(unsigned char) * block_size);
	buff = find_blocks(cnt,bmap,blocks_for_file, bytes_to_skip_to_first_block,size_bitmamp, i);
	
	//lseek(fd,bytes_to_skip_to_first_block, SEEK_SET);
	//write(fd,buff,block_size);
	
	return buff;
}

int main(int argc, char **argv) {
    d = open(argv[1], O_RDONLY);
    
    int sb_size = sizeof(struct SB);

    SB *sb = (SB *)malloc(sb_size);

    read(d, sb, sb_size);

    int no_blocks = ceil((double)sb->size_disk/sb->size_block);
	int md_bytes = (ceil((double)no_blocks/8)) + sb_size;
	int flag_bytes = md_bytes - sb_size;
	int size_bitmap = flag_bytes;

    unsigned char *bmap = (unsigned char *)malloc(sizeof(unsigned char) * size_bitmap);

    bmap = Bitmap_to_Array(argv[1],int size_bitmap,sb->size_block);
    
    // bmap[0] = 0x03;
    // bmap[1] = 0xff;
    // bmap[2] = 0xf3;
    // bmap[3] = 0x00;

    int total_free_blocks = BitMap_getFreeBlocks(bmap, size_bitmap);

    /*int i;
    int *block_nos = (int *)malloc(sizeof(int) * size_bitmap);
    for(i = 0; i < size_bitmap; i++) {
        block_nos[i] = BitMap_indexToBlock((BitMap_isBitSet(bmap, i)), bmap[i]);
        printf("%d\t", block_nos[i]);
    }
    printf("\n");*/

    printf("total_free_blocks : %d\n", free_blocks);

    /*int i;
    while(i < size_bitmap) {
        if(i % 8 == 0) {
            printf("\n");
        }
        printf("%02x\t", bmap[i]);
        i++;
    }*/
}

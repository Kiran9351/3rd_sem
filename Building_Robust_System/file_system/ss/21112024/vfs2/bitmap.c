#include "bitmap.h"

unsigned char *Bitmap_to_Array(char *diskname) {
    d = open(diskname, O_RDONLY);
    
    int sb_size = sizeof(struct SB);

    SB *sb = (SB *)malloc(sb_size);

    read(d, sb, sb_size);

    int no_blocks = ceil((double)sb->size_disk/sb->size_block);
	int md_bytes = (ceil((double)no_blocks/8)) + sb_size;
	int flag_bytes = md_bytes - sb_size;
	int size_bitmap = flag_bytes;

    unsigned char *bmap = (unsigned char *)malloc(sizeof(unsigned char) * size_bitmap);

    lseek(d, sb->size_block, SEEK_SET);

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

    bmap = Bitmap_to_Array(argv[1]);
    
    // bmap[0] = 0x03;
    // bmap[1] = 0xff;
    // bmap[2] = 0xf3;
    // bmap[3] = 0x00;

    int free_blocks = BitMap_getFreeBlocks(bmap, size_bitmap);

    /*int i;
    int *block_nos = (int *)malloc(sizeof(int) * size_bitmap);
    for(i = 0; i < size_bitmap; i++) {
        block_nos[i] = BitMap_indexToBlock((BitMap_isBitSet(bmap, i)), bmap[i]);
        printf("%d\t", block_nos[i]);
    }
    printf("\n");*/

    printf("free_blocks : %d\n", free_blocks);

    /*int i;
    while(i < size_bitmap) {
        if(i % 8 == 0) {
            printf("\n");
        }
        printf("%02x\t", bmap[i]);
        i++;
    }*/
}

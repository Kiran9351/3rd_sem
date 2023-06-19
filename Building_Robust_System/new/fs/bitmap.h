
long find_first_metablock(int bytes_to_move_to_fbits, long bytes_for_fbits)
{
	unsigned char *buff = (unsigned char*)malloc(sizeof(unsigned char) * bytes_for_fbits);
	
	int fd = open("disk",O_WRONLY);
	
	lseek(fd,bytes_to_move_to_fmd,SEEK_SET);
	read(fd,buff,bytes_for_fbits);
	
	while(i < bytes_for_bits)
	{
		char ch = buff[i];
		// 0 1 2 3 4 5 6 7 
	
		for(int j = 0; j < 8; j++)
		{
			if((ch & (1 << j)) == (1 << j))
			{
				ch = ch & (~(1 << j)); //Making bit zero
				lseek(fd,bytes_to_move_to_fbits, SEEK_SET);
				write(fd,buff,bytes_for_fbits);
				close(fd);
				return ((i * 8) + (7 - j));
			}
		}
		
		i++;
	}
}

FMD *find_data_blocks(long bytes_to_move_to_fbits, FMD *fmd, int block_size)
{
	//Traverse through bmap
		//If we found bmap[i] bit value == 1 then 
		// calculate block no. associated with that bit
		// Then write it down in fmd->block
		
	int cnt = 0, fd = 0, block_no = 0;
	
	fd = open("disk",O_WRONLY);
	//Seeking till the actual location of the fmd -> block_no.
	lseek(fd,fmd->block_no * block_size,SEEK_SET)
	
	while(i < bytes_for_bits)
	{
		char ch = buff[i];
		// 0 1 2 3 4 5 6 7 
		// 15 

		for(int j = 0; j < 8, cnt < 15; j++)
		{
			if((ch & (1 << j)) == (1 << j))
			{
				ch = ch & (~(1 << j)); //Making bit zero
				//lseek(fd,bytes_to_move_to_fbits, SEEK_SET);
				//write(fd,buff,bytes_for_fbits);
				//close(fd);
				block_no = ((i * 8) + (7 - j));
				write(fd,&block_no,sizeof(int));
				cnt++;
			}
		}
		
		i++;
	}
	
	lseek(fd,bytes_to_move_to_fbits,SEEK_SET);
	write(fd,buff,bytes_for_fbits);
	close(fd);
}

int count_blocks(int bytes_to_move_to_fbits, long bytes_for_fbits)
{
	int fd = open("disk",O_RDONLY);
	lseek(fd,bytes_to_move_to_fbits);
	
	unsigned char *buff = (unsigned char*)malloc(sizeof(unsigned char) * bytes_for_bits);
	read(fd,buff,bytes_for_fbits);

	close(fd);	

	int count = 0;

	for(i = 0; i < bytes_for_bits)
	{
		char ch = buff[i];

		for(int j = 0; j < 8; j++)
		{
			if((ch & (1 << j)) == (1 << j))
			{
				count++;
			}
		}
	}

	return count;
}

bool check_blocks(long file_size, int block_size, int bytes_to_move_to_fbits, long bytes_for_fbits)
{
	int total_no_of_available_blocks = count_blocks(bytes_to_move_to_fbits,bytes_for_bits);
	
	int blocks_need = ceil((double)file_size/block_size) + 1;
	
	if(total_no_of_available_blocks < blokcks_need)
	{
		return false;
	}

	return true;
}

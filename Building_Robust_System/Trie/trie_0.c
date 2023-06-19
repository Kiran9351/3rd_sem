#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define NO_OF_CHARS 26

typedef struct trienode
{	
	struct trienode *next[NO_OF_CHARS];
	
	bool end;
}trienode;

trienode *create_trie_node()
{
	int i = 0;

	trienode *new_node = NULL;
	
	new_node = (trienode*)malloc(sizeof(trienode));

	if(new_node == NULL)
	{
		printf("ERROR in creating new node\n");
		return NULL;
	}

	for(i = 0; i < NO_OF_CHARS; i++)
	{
		new_node -> next[i] = NULL;
	}

	new_node -> end = false;

	return new_node;
}

bool insert_file_name(trienode **root, char *fname)
{
	int i = 0, index = 0;

	if(*root == NULL)
	{
		*root = create_trie_node();
	}	

	int len = 0;
	
	trienode *temp = *root;	

	len = strlen(fname);

	for( i = 0; i < len; i++)
	{
		if(fname[i] >= 'a' && fname[i] <= 'z')
		{
			index = (int)fname[i] - 97;
		}
		else
		{
			index = (int)fname[i] - 65;
		}

		if(temp -> next[index] == NULL)
		{
			temp -> next[index] = create_trie_node();
		}

		temp = temp -> next[index];
	}

	if(temp -> end == true)
	{
		return false;
	}
	else
	{
		temp -> end = true;
		return true;
	}
}

trienode *filenames(trienode *root)
{
	char buffer[100], ch;
	int value = 1, iCnt = 0;;

	//int fd = open("filenames.txt", O_RDONLY);
/*
	while(value != 0)
	{
		value = 0;
		printf("I am here\n");
		iCnt = 0;
		while(ch != '\n')
		{
			iCnt = read(fd,&ch,1);
			strcat(buffer,&ch);
		}
		
		insert_file_name(&root,buffer);
	}
*/

	FILE *file = fopen("filenames.txt", "r");

	while(fgets(buffer,sizeof(buffer),file))
	{
		insert_file_name(&root,buffer);
//		printf("buffer : %s\n",buffer);
	}

	return root;
}

void Display_rec(trienode *node, char *prefix, int len)
{
	char newprefix[len + 2];
	memcpy(newprefix,prefix,len);
	newprefix[len + 1] = '\0';

	if(node -> end)
	{	
		printf("Word : %s\n",prefix);
	}

	for(int i = 0; i < NO_OF_CHARS; i++)
	{
		if(node -> next[i] != NULL)
		{
			newprefix[len] = (char)(i+97);
			Display_rec(node -> next[i],newprefix,len + 1);
		}
	}
}

void Display_trie(trienode *root)
{
	if(root == NULL)
	{
		printf("Trie is empty\n");
		return;
	}

	Display_rec(root,NULL,0);
}

int main()
{
	trienode *root = NULL;

	root = filenames(root);

//	Display_trie(root);
	

	return 0;
}

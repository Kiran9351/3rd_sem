#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int node_no;
	int data;
	
	struct node *left;
	struct node *right;
}node;

typedef struct parent
{
        node *node_ptr;
   
        struct parent *next;
}parent;


typedef struct tree
{
	node *root;
	parent *head;
}tree;

int NO = 0;
parent *last_ptr = NULL;

tree *create_tree_struct()
{
	tree *first = NULL;
	
	first = (tree*)malloc(sizeof(tree));
		
	if(first == NULL)
	{
		printf("Error in creating tree struct\n");
		return NULL;
	}

	first -> root = NULL;
	
	first -> head = NULL;

	return first;
}

parent *create_parent_node(node *tNode)
{
	parent *pNode = NULL;

	pNode = (parent*)malloc(sizeof(parent));
	
	if(pNode == NULL)
	{
		printf("Error in creating parent node\n");
		return NULL;
	}

	pNode -> node_ptr = tNode;
	
	pNode -> next = NULL;

	return pNode;
}

node *create_tree_node(int iValue)
{
	node *new_node = NULL;

	new_node = (node*)malloc(sizeof(node));
	
	if(new_node == NULL)
	{
		return NULL;
	}
	
	NO += 1;
	
	new_node -> node_no = NO;
	new_node -> data = iValue;

	new_node -> left = NULL;
	new_node -> right = NULL;
	
	return new_node;
}

void list_insert_last(tree* tFirst, node *tNode)
{
	if(tFirst -> head == NULL)
	{
		tFirst -> head = create_parent_node(tNode);
	
		last_ptr = tFirst -> head;
	}
	else
	{
		last_ptr -> next = create_parent_node(tNode);
		last_ptr = last_ptr -> next;
	}

	return;
}

void list_delete_first(tree *tFirst)
{
	if(tFirst -> head != NULL)
	{
		parent *temp = tFirst -> head;

		tFirst -> head = temp -> next;

		free(temp);
	}
	
	return;
}

void insert_tree_node(tree *tFirst, int iValue)
{
        if(tFirst == NULL)
        {
		printf("Tree is not created\n");
                return;
        }   

	if(tFirst -> root == NULL)
	{
		tFirst -> root = create_tree_node(iValue);
	
		list_insert_last(tFirst,tFirst -> root);
	}
	else
	{
		if(tFirst -> head -> node_ptr -> left == NULL)
		{
			node *new_node = create_tree_node(iValue);

			tFirst -> head -> node_ptr -> left = new_node;
		
			list_insert_last(tFirst,new_node);
		}
		else
		{
			node *new_node = create_tree_node(iValue);
		
			tFirst -> head -> node_ptr -> right = new_node;

			list_insert_last(tFirst,new_node);

			list_delete_first(tFirst);
		}
	}

	return;
}

node* search_in_tree(node *root, node* node_ptr)
{

	if(root == NULL)
	{
		return NULL;
	}
	
	if(root == node_ptr)
	{
		return root;
	}

	node *left = search_in_tree(root -> left, node_ptr);

	if(left != NULL)
	{
		return left;
	}

	node *right = search_in_tree(root -> right, node_ptr);

	return right;
}

void inorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	inorder(root -> left);
	printf("%d ",root -> data);
	inorder(root -> right);	
}

int main()
{
	tree *first = NULL;
	
	first = create_tree_struct();

	insert_tree_node(first,10);
	
	insert_tree_node(first,20);

	insert_tree_node(first,30);
	
	insert_tree_node(first,40);

	insert_tree_node(first,50);

	insert_tree_node(first,60);
	
	insert_tree_node(first,70);
	
	insert_tree_node(first,80);

	insert_tree_node(first,90);

	insert_tree_node(first,100);

	inorder(first -> root);	
	printf("\n");

	node *bRet = search_in_tree(first -> root,first -> root -> left);
	if(bRet != NULL)
	{
		printf("Value is in tree\n");
	}
	else
	{
		printf("Value is not in tree\n");
	}
/*
	printf("first node = %d\n",first -> root -> data);

	printf("first parent node = %d\n",first->head->node_ptr -> data);
		
	printf("second node = %d\n",first -> root ->left -> data);
        printf("second parent node = %d\n",first->head->next->node_ptr -> data);

*/
	return 0;
}

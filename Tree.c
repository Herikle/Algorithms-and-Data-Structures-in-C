#include <stdio.h>
#include <stdlib.h>
//Uma arvore binária de pesquisa com métodos simples.
struct Node{
	struct Node *right;
	struct Node *left;
	int key;
};

struct Node *root;

void insert(int key, struct Node **leaf)
{
	if((*leaf) == NULL)
	{
		(*leaf) = (struct Node*)malloc( sizeof( struct Node ) ); 
		(*leaf)->key = key;
		(*leaf)->right = NULL;
		(*leaf)->left = NULL;
	}
	else if(key==(*leaf)->key){
		printf("Chave já existe, escolha outra.\n");
	}
	else if(key>(*leaf)->key){
		insert(key, &(*leaf)->right);
	}else if(key<(*leaf)->key){
		insert(key, &(*leaf)->left);
	}
}
void search(int key, struct Node *leaf)
{
	if(leaf!=NULL)
	{	
		if(key==leaf->key)
			printf("Encontrado: %d\n",leaf->key);
		else if(key>leaf->key)
			search(key,leaf->right);
		else if(key<leaf->key)
			search(key,leaf->left);
	}
	else
		printf("Chave não encontrada.\n");
}
void inOrder(struct Node *leaf)
{
	if(leaf!=NULL)
	{
		inOrder(leaf->left);
		printf("key: %d\n", leaf->key);
		inOrder(leaf->right);
	}
}
struct Node* hasTwoChild(struct Node* leaf)
{
	if(leaf->left==NULL)
		return leaf;
	return hasTwoChild(leaf->left);
}

struct Node* removenode(int key, struct Node* leaf)
{
	if(leaf == NULL) 
		return leaf;
	else if(key>leaf->key)
		leaf->right = removenode(key, leaf->right);
	else if(key<leaf->key)
		leaf->left = removenode(key, leaf->left);
	else
	{
		if(leaf->right==NULL)
		{
			struct Node* new = leaf->left;
			free(leaf);
			return new;
		}else if(leaf->left==NULL)
		{
			struct Node *new = leaf->right;
			free(leaf);
			return new;
		}

		struct Node* new = hasTwoChild(leaf);

		leaf->key = new->key;

		leaf->right = removenode(new->key,leaf->right);

	}
	return leaf; 
}

int main()
{
	int choose, value;

	do
	{
		printf("1 - Inserir\n2 - Remover\n3 - Procurar\n4 - Em ordem\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				printf("Valor = ");
				scanf("%d",&value);
				insert(value, &root);
			break;
			case 2:
				printf("Valor = ");
				scanf("%d",&value);
				removenode(value,root);
			break;
			case 3:
				printf("Valor = ");
				scanf("%d",&value);
				search(value,root);
			break;
			case 4:
				inOrder(root);
			break;
		}
	}while(choose!=0);
	return 0;
}
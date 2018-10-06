#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node Node;

struct Node
{
	char data;
	Node*left;
	Node*right;
};

Node *newNode(char item)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(Node* root, char data)
{
	Node*new_node = newNode(data);
	if (root == NULL) {
		root = new_node;
		return;
	}
	
	Node*cur = root;
	Node*prev = root;
	while (cur != NULL) {
		prev = cur;
		if (new_node->data<cur->data) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	if (new_node->data < prev->data) {
		prev->left = new_node;
	}
	else {
		prev->right = new_node;
	}

}
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c \n", root->data);
		inorder(root->right);
	}
}
Node* search(Node*root, char key) {
	if (root == NULL || root->data == key){
		//printf("%s \n", "searching result:");
	    //printf("%c \n", root->data);
	return root;
    }
	// Key is greater than root's key
	
		
		if (root->data < key) {
			return search(root->right, key);
		}
		else {
			return search(root->left, key);
		}
	
	//printf("%s \n", "cant find letter");
	return NULL;
}

void delete_all(Node *tree)
{
	if (tree == NULL)
		return;

	delete_all(tree->left);
	delete_all(tree->right);
	free(tree);
}

int main() {
	char c[] = { 'F', 'L', 'O', 'C', 'C', 'I', 'N', 'A', 'U', 'C', 'I', 'N', 'I', 'H', 'I', 'L', 'I', 'P', 'I', 'L', 'I', 'F', 'I', 'C', 'A', 'T', 'I', 'O', 'N' };
	Node*root = newNode('F');

	for (int i = 0; i < 29; i++) {
		insert(root, c[i]);
	}
	inorder(root);
	int count = 0;

	while (count <4 ) {
		char randomletter = 'A' + (rand() % 26);
		printf("%s  ", "searching for");
		printf("% c\n", randomletter);
		search(root, randomletter);
		if(search(root, randomletter) != NULL) {
			printf("%s \n", "result");
			printf("%c \n", randomletter);
		}
		else {
			printf("%s", "NO RESULT");
		}
			
			    
		count++;
	}
	

	delete_all(root);
	return 0;
}
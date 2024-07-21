#include"tree.h"

int main()
{
	ThreadTree root;
	printf("Input:");
	CreateTree(&root);
	printf("\n");

	printf("Threading Binary Tree!\n");
	Inthreading(root);
	printf("\n");

	printf("Inorder traverse:");
	InorderTraverse(&root);
	printf("\n");


	return 0;
}

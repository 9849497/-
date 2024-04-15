#include"FileName.h"

void test01() {
	qm qm;
	tree* root = InitTree();
	InsertTree(root, 4);
	InsertTree(root, 26);
	InsertTree(root, 9);
	InsertTree(root, 24);
	PrintTree(root, &qm);
	tree* tmp = FindElem(root, 26);
	printf("%d \n", tmp->data);
	FrontFind(root);
	
}

int main() {
	test01();
	return 0;
}
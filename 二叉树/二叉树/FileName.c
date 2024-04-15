#include"FileName.h"

tree* InitTree() {
	tree* root = (tree*)malloc(sizeof(tree));
	if (root == NULL) {
		perror("malloc failed!");
		exit(1);
	}
	root->data = 10;
	root->lchild = root->rchild = NULL;
	return root;
}



queue* InitQM(qm*qm) {
	queue* Q = (queue*)malloc(sizeof(queue));
	if (Q == NULL) {
		perror("malloc failed!");
		exit(1);
	}
	Q->next = NULL;
	qm->tail = qm->top = Q;
	return Q;
}



void InsertQueue(tree* root , qm* qm) {
	queue* newnode = (queue*)malloc(sizeof(queue));
	if (newnode == NULL) {
		perror("malloc failed!");
		return;
	}
	newnode->node = root;
	newnode->next = NULL;
	if (qm->top->next == NULL) {
		//空队列
		qm->top->next = newnode;
		return;
	}
	//不是空队列
	qm->tail->next->next = newnode;
	qm->tail = qm->tail->next;
}



tree* DeleteQueue(qm* qm) {
	if (qm->top->next == NULL) {
		return NULL;
	}
	//不是空队列
	//top指向头节点
	//这一步是修改头节点指针，使之出队
	tree* tmp = qm->top->next->node;
	qm->top->next = qm->top->next->next;
	return tmp;
}



void PrintQueue(qm* qm) {
	if (qm->top->next == NULL) {
		printf("NULL");
		return;
	}
	queue* tmp = qm->top->next;
	while (tmp != NULL) {
		//队列未空
		printf("%d ", tmp->node->data);
		tmp = tmp->next;
	}
}



void PrintTree(tree* root,qm*qm) {
	//这一步 不是废话
	//主要是判断是不是空的二叉树；
	if (root == NULL) {
		printf("NULL");
		return;
	}
	//先将根节点插入队列
	queue* Q = InitQM(qm);
	InsertQueue(root, qm);
	while (qm->top->next != NULL) {
		tree* tmp;
		printf("%d->", qm->top->next->node->data);
		tmp = DeleteQueue(qm);
		if (tmp->lchild != NULL) {
			InsertQueue(tmp->lchild, qm);
		}
		if (tmp->rchild != NULL) {
			InsertQueue(tmp->rchild, qm);
		}
	}
	printf("NULL\n");
}



void InsertTree(tree* root, int data) {
	tree* newnode = (tree*)malloc(sizeof(tree));
	if (newnode == NULL) {
		perror("malloc failed!");
		exit(1);
	}
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;
	//data比节点小，插入左子树，反之
	if (data < root->data) {
		if (root->lchild == NULL) {
			//证明找到了父节点
			root->lchild = newnode;
			return;
		}
			InsertTree(root->lchild, data);
	}
	else if (data >= root->data) {
		if (root->rchild == NULL){
			//父节点位置
			root->rchild = newnode;
			return;
		}
		InsertTree(root->rchild, data);
	}
	return;
}



tree* FindElem(tree* root, int data) {
	if (data == root->data) {
		return root;
	}
	if (root->data < data && root->rchild != NULL) {
		return FindElem(root->rchild, data);
	}
	else if (root->data > data && root->lchild != NULL) {
		return FindElem(root->lchild, data);
	}

	return NULL;
}

//根，左，右
void FrontFind(tree* root) {
	if (root == NULL)
		return;
	printf("%d ", root->data);
	FrontFind(root->lchild);
	FrontFind(root->rchild);
}
	


void MidFind(tree* root) {
	if (root == NULL)
		return;
	MidFind(root->lchild);
	printf("%d ", root);
	MidFind(root->rchild);
}



void BehindFind(tree* root) {
	if (root == NULL)
		return;
	BehindFind(root->lchild);
	BehindFind(root->rchild);
	printf("%d ", root->data);
}
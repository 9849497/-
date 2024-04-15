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
		//�ն���
		qm->top->next = newnode;
		return;
	}
	//���ǿն���
	qm->tail->next->next = newnode;
	qm->tail = qm->tail->next;
}



tree* DeleteQueue(qm* qm) {
	if (qm->top->next == NULL) {
		return NULL;
	}
	//���ǿն���
	//topָ��ͷ�ڵ�
	//��һ�����޸�ͷ�ڵ�ָ�룬ʹ֮����
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
		//����δ��
		printf("%d ", tmp->node->data);
		tmp = tmp->next;
	}
}



void PrintTree(tree* root,qm*qm) {
	//��һ�� ���Ƿϻ�
	//��Ҫ���ж��ǲ��ǿյĶ�������
	if (root == NULL) {
		printf("NULL");
		return;
	}
	//�Ƚ����ڵ�������
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
	//data�Ƚڵ�С����������������֮
	if (data < root->data) {
		if (root->lchild == NULL) {
			//֤���ҵ��˸��ڵ�
			root->lchild = newnode;
			return;
		}
			InsertTree(root->lchild, data);
	}
	else if (data >= root->data) {
		if (root->rchild == NULL){
			//���ڵ�λ��
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

//��������
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
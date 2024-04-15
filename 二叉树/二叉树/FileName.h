#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	struct tree* lchild;
	struct tree* rchild;
}tree;

typedef struct queue {
	tree* node;
	struct queue* next;
}queue;

typedef struct queuemanager {
	queue* top;
	queue* tail;
}qm;

//��ʼ����
tree* InitTree();

//��ʼ������
queue* InitQM(qm*qm);

//���еĲ���
void InsertQueue(tree* root , qm* qm);

//���е�ɾ��
tree* DeleteQueue(qm* qm);

//���еĴ�ӡ
void PrintQueue(qm* qm);

//���Ĳ�α���
void PrintTree(tree* root,qm*qm);

//�����������Ĳ���
void InsertTree(tree* root, int data);

//�����������Ĳ���
tree* FindElem(tree* root, int data);

//���������������
void FrontFind(tree* root);

void MidFind(tree* root);

void BehindFind(tree* root);
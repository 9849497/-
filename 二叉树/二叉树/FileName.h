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

//初始化树
tree* InitTree();

//初始化队列
queue* InitQM(qm*qm);

//队列的插入
void InsertQueue(tree* root , qm* qm);

//队列的删除
tree* DeleteQueue(qm* qm);

//队列的打印
void PrintQueue(qm* qm);

//树的层次遍历
void PrintTree(tree* root,qm*qm);

//二叉搜索树的插入
void InsertTree(tree* root, int data);

//二叉搜索树的查找
tree* FindElem(tree* root, int data);

//二叉树的先序遍历
void FrontFind(tree* root);

void MidFind(tree* root);

void BehindFind(tree* root);
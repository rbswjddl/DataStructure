#pragma once

typedef int BTData;

typedef struct _node
{
	BTData data;
	struct _node* left;
	struct _node* right;
}BTreeNode;

BTreeNode* MakeBTreeNode();
int GetData(BTreeNode* node);
void SetData(BTreeNode* node, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* node);
void MakeRightSubTree(BTreeNode* main, BTreeNode* node);
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

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);
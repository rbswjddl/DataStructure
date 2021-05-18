#include<stdio.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode()
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int GetData(BTreeNode* node)
{
	return node->data;
}

void SetData(BTreeNode* node, BTData data)
{
	node->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* node)
{
	if (main->left != NULL)
		free(main->left);

	main->left = node;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* node)
{
	if (main->right != NULL)
		free(main->right);

	main->right = node;
}
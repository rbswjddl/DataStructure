#include "BinarySearchTree.h"
#include<stdio.h>

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTMakeInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{
		if (GetData(cNode) == data)
			return;

		pNode = cNode;

		if (GetData(pNode) < data)
			cNode = GetRightSubTree(pNode);
		else
			cNode = GetLeftSubTree(pNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode == NULL)
		*pRoot = nNode;
	else
	{
		if (GetData(pNode) < data)
			MakeRightSubTree(pNode, nNode);
		else
			MakeLeftSubTree(pNode, nNode);
	}
}

BTreeNode* BSTSearch(BTreeNode* pRoot, BSTData target)
{
	BTreeNode* node = pRoot;

	while (node != NULL)
	{
		if (GetData(node) == target)
			return node;

		if (GetData(node) < target)
			node = GetRightSubTree(node);
		else
			node = GetLeftSubTree(node);
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, cNode);


	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		
		if (GetData(cNode) < target)
		{
			cNode = GetRightSubTree(cNode);
		}
		else
		{
			cNode = GetLeftSubTree(cNode);
		}
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		SetData(mNode, delData);
		dNode = mNode;
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}
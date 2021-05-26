#include<stdio.h>
#include "AVLRebalance.h"

BTreeNode* RotateLL(BTreeNode* pRoot)
{
	BTreeNode* pNode = pRoot;
	BTreeNode* cNode = GetLeftSubTree(pRoot);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateRR(BTreeNode* pRoot)
{
	BTreeNode* pNode = pRoot;
	BTreeNode* cNode = GetRightSubTree(pRoot);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateLR(BTreeNode* pRoot)
{
	BTreeNode* pNode = pRoot;
	BTreeNode* cNode = GetLeftSubTree(pRoot);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* pRoot)
{
	BTreeNode* pNode = pRoot;
	BTreeNode* cNode = GetRightSubTree(pRoot);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

int GetHeight(BTreeNode* pRoot)
{
	int leftHeight;
	int rightHeight;

	if (pRoot == NULL)
		return 0;

	leftHeight = GetHeight(GetLeftSubTree(pRoot));
	rightHeight = GetHeight(GetRightSubTree(pRoot));

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

int GetHeightDiff(BTreeNode* pRoot)
{
	int leftSubHeight;
	int rightSubHeight;

	if (pRoot == NULL)
		return 0;

	leftSubHeight = GetHeight(GetLeftSubTree(pRoot));
	rightSubHeight = GetHeight(GetRightSubTree(pRoot));

	return leftSubHeight - rightSubHeight;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int heightDiff = GetHeightDiff(*pRoot);

	if (heightDiff > 1)
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
		{
			*pRoot = RotateLL(*pRoot);
		}
		else
		{
			*pRoot = RotateLR(*pRoot);
		}
	}

	if (heightDiff < -1)
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) > 0)
			*pRoot = RotateRL(*pRoot);
		else
			*pRoot = RotateRR(*pRoot);
	}

	return *pRoot;
}
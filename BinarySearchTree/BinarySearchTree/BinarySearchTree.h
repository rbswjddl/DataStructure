#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeInit(BTreeNode** pRoot);

BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* pRoot, BSTData target);

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowAll(BTreeNode* bst);
#endif
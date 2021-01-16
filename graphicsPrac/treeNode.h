#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

using namespace std;

struct TreeNode
{
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int treeData, TreeNode *leftBranch = nullptr,
      TreeNode *rightBranch = nullptr);

   TreeNode *insert(TreeNode *root, int value = 0);

   int sumLeafNodes(TreeNode *root = nullptr);
   void traverse(TreeNode *node);
};

#endif

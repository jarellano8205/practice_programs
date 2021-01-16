#include "treeNode.h"

TreeNode::TreeNode(int treeData, TreeNode *leftBranch,
      TreeNode *rightBranch): data(treeData), left(leftBranch),
      right(rightBranch)
{}

TreeNode* TreeNode::insert(TreeNode *root, int value)
{
   if (root == nullptr)
   {
      return new TreeNode(value);
   }
   
   if (root->data > value)
   {
      root->left  = insert(root->left, value);
   }
   else
   {
      root->right = insert(root->right, value);
   }
   return root;
}

int TreeNode::sumLeafNodes(TreeNode *root)
{
   int totalSum = 0;

   if (root == nullptr)
   {
      return 0;
   }

   if (root->left == nullptr && root->right == nullptr)
   {
	   return root->data;
   }

   totalSum = sumLeafNodes(root->left) + sumLeafNodes(root->right);

   return totalSum;
}

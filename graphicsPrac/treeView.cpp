#include "treeView.h"

TreeView::TreeView() {}

void TreeView::addToNumber(unsigned char key)
{
   nodeVal += key;
   glutSetWindowTitle(nodeVal.c_str());
}

void TreeView::drawTree()
{
  
   if (root == nullptr)
   {
      return;
   }

   traverseDraw(root, glutGet(GLUT_WINDOW_WIDTH) / 2
		   , glutGet(GLUT_WINDOW_HEIGHT) - 50); 

}

void TreeView::traverseDraw(TreeNode *r, int x, int y)
{
   if (r == nullptr)
   {
      return;
   }

   stringstream ss;
   ss << r->data;
   DrawTextString(ss.str().c_str(), x, y, Green);

   if (r->left != nullptr)
   {
      DrawLine(x, y, x - 75, y - 75, White);
   }
   
   if (r->right != nullptr)
   {
      DrawLine(x, y, x + 75, y - 75, White);
   }

   traverseDraw(r->left, x - 75, y - 75);

   traverseDraw(r->right, x + 75, y - 75);
}

void TreeView::insertNumberIntoTree()
{
   // insert into TreeNode *root
   if (nodeVal.length() == 0)
   {
      return;
   }

   int value;
   stringstream ss;
   ss.str(nodeVal);
   ss >> value;
  
   root = root->insert(root, value);

   nodeVal.clear();

   stringstream sss;
   sss << "Tree View - Enter integer <return> :: SumOfLeaves = "
       << root->sumLeafNodes(root);
   glutSetWindowTitle(sss.str().c_str());
}

#ifndef TREEVIEW_H
#define TREEVIEW_H
#include <iostream>
#include <sstream>
#include <GL/freeglut.h>
#include "graphics.h"
#include "treeNode.h"

using namespace std;

class TreeView
{
   TreeNode *root;
   string nodeVal;
public:
   TreeView();

   void addToNumber(unsigned char);
   void insertNumberIntoTree();
   void drawTree();
   void traverseDraw(TreeNode *r, int x = 300, int y = 460);
};

#endif

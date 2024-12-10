/// dev Volosikova M.A.
#include <iostream>
#include <vector>
#include "Tree.h"

/*
   

          3
         / \
        0   4
         \    
          2
         /
        1

*/

int main()
{
    TreeNodeTests1();
    TreeNodeTests2();
    /*TreeNode<int>* A0 = new TreeNode<int>(0);
    TreeNode<int>* A1 = new TreeNode<int>(1);
    TreeNode<int>* A2 = new TreeNode<int>(2);
    TreeNode<int>* A3 = new TreeNode<int>(3);
    TreeNode<int>* A4 = new TreeNode<int>(4);*/

   /* A0->left = A1;
    A0->right = A2;
    A1->right = A3;
    A2->right = A4;*/ 
    
    TreeNode<int>* A0 = new TreeNode<int>;
    insert(A0, 0);
    insert(A0, 1);
    insert(A0, 2);
    insert(A0, 3);
    insert(A0, 4);


    Tree<int>::runTests();



   
    LRN(A0);

    std::cout << std::endl;
    
    TreeNode<int>* A15 = new TreeNode<int>;
   // A15->right = new TreeNode<int>;
   // A15->left = new TreeNode<int>;
   A15 = copyTree(A0);

   // A15 = searchRecursive(A0, 4);
    LRN(A15);

    std::cout << std::endl;
  //  std::cout <<A15->data;
    LRN(A0);

   // delete A1->left;
   // delete A2->left;
   // delete A0->left;
   // delete A0->right;
   // delete A0;

 

}
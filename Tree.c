#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

PTreeNode TreCreateNode(Element e) {
    /*if(e) {
        PTreeNode node = (PTreeNode)malloc(sizeof(TreeNode));
        if (node) {
            node->data = e;
            node->left = NULL;
            node->right = NULL;
            return node;
        }
        return NULL;
    }
    return NULL;
    */
    return TreCreateNode2(e, NULL, NULL);
}
PTreeNode TreCreateNode2(Element e, PTreeNode left, PTreeNode right) {
    PTreeNode node = (PTreeNode)malloc(sizeof(TreeNode));
    if (node) {
          node->data = e;
          node->left = left;
          node->right = right;
         return node;
    }
    return NULL;
}
//               11(root)
//      3(p1)              17(p3)
//           7(p2)     13(p4)   19(p5)

void TreDestroy(PTreeNode root) {
    if (root) {
        TreDestroy(root->left); //서브트리 먼저 없애라.
        TreDestroy(root->right); //서브트리 먼저 없애라.
        free(root);
    }
}
// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void TreIterate(PTreeNode root, IterateFunc func, void* p, TreeTraverseOrder order) {
    if (root) {
        switch (order) {
        case TTO_PREORDER:
            func(&(root->data),&p);
            TreIterate(root->left, func, p, order);
            TreIterate(root->right, func, p, order);
            break;
        case TTO_INORDER:
            TreIterate(root->left, func, p, order);
            func(&(root->data), &p);
            TreIterate(root->right, func, p, order);
            break;
        case TTO_POSTORDER:
            TreIterate(root->left, func, p, order);
            TreIterate(root->right, func, p, order);
            func(&(root->data), &p);
            break;
        }
    }
}


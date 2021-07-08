#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
#include "Tree.h"
PTreeNode BSTreInsert(PTreeNode root, Element e, CompareElement compare){
	PTreeNode node;
	if (root == NULL) {
		node = TreCreateNode(e);
		return node;
	}
	else if (compare(&(root->data), &e) == 1) {
		root->left = BSTreInsert(root->left, e, compare);
	}
	else if (compare(&(root->data), &e) == -1) {
		root->right = BSTreInsert(root->right, e, compare);
	}
	return root;
}

//               11(root)
//      3(p1)              17(p3)
//           7(p2)     13(p4)   19(p5)

PTreeNode min_value_node(PTreeNode node) {
	while (node->left) {
		node->left = min_value_node(node->left);
	}
	return node;
}

PTreeNode BSTreDelete(PTreeNode root, Element e, CompareElement compare) {
	if (root == NULL) {
		return root;
	}
	if (compare(&(root->data), &e) == 1) {
		root->left = BSTreDelete(root->left, e, compare);
	}
	else if(compare(&(root->data), &e) == -1) {
		root->right = BSTreDelete(root->right, e, compare);
	}
	else if(compare(&(root->data), &e) == 0) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->right == NULL || root->left == NULL) {
			if (root->right == NULL) {
				PTreeNode temp = root;
				root = root->left;
				free(temp);
			}
			else {
				PTreeNode temp = root;
				root = root->left;
				free(temp);
			}
		}
		else {
			PTreeNode node = min_value_node(root->right);
			root->data = node->data;
			root->right = BSTreDelete(node->right, node->data, compare);
		}
	}
	return root;
}

PTreeNode BSTreSearch(PTreeNode root, Element e, CompareElement compare) {
	if (root) {
		if (root == NULL) {
			return NULL;
		}
		else if (compare(&(root->data), &e) == 0) {
			return root;
		}
		else if (compare(&(root->data), &e) == 1) {
			return BSTreSearch(root->left, e, compare);
		}
		else if (compare(&(root->data), &e) == -1) {
			return BSTreSearch(root->right, e, compare);
		}
	}
	return NULL;
}
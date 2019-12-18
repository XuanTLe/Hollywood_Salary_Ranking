#include "stdafx.h"
#include <iostream>
#include <string>



/****************************************************************************************************************
Function: insert
Inputs:   User's input of pay and name for Hollywood actor/actress
Outputs:  Add a new actor/actress with new data in the binary tree based on sorted pay
Purpose:  This function asks user for input of actor/actress , create a node and add those information to it.
Then, the function add the node to the tree based on sorted order
*****************************************************************************************************************/
void HollywoodPay::insert(HollywoodTree* &tree, float p, string n)
{
	// if tree is empty, create new node and assign pay and name to that node
	// that node also becomes the root node
	if (!tree)
	{
		tree = new HollywoodTree(p, n);
	}

	// if pay in root node is the same as pay entered, return
	if (tree->pay == p)
		return;

	// if pay entered is smaller than pay in root node, recursion call for left subtree
	if (p < tree->pay)
		insert(tree->left, p, n);

	// if pay entered is larger than pay in root node, recursion call for right subtree	
	else
		insert(tree->right, p, n);
}

/****************************************************************************************************************
Function: destroySubtree
Inputs:   root of binary tree
Outputs:  destroy all nodes
Purpose:  This function is used for destructor to destroy entire tree
*****************************************************************************************************************/
void HollywoodPay::destroySubtree(HollywoodTree* tree)
{
	if (!tree) return; // return when tree is empty
	destroySubtree(tree->left); // recursion call for left subtree
	destroySubtree(tree->right); // recursion call for right subtree

	delete tree; // delete node
}

/****************************************************************************************************************
Function: search
Inputs:   User's input of name to be searched
Outputs:  Signal the user whether the name was found or not
Purpose:  This function asks user for input of name to be searched and signals the user whether
the name was found or not
*****************************************************************************************************************/
bool HollywoodPay::search(HollywoodTree* node, string n)
{
	if (node == NULL)
		return false;
	
	if (node->name == n)
		return true;
	
	// recur left sub tree if not found at root
	bool leftSub = search(node->left, n);
	if (leftSub) return true;
	
	// recur right sub
	bool rightSub = search(node->right, n);
	return rightSub;
	
}

/****************************************************************************************************************
Function: remove
Inputs:   root pointer, User's input of name to be removed
Outputs:  remove an entry
Purpose:  This function asks user for name to be removed and removes it from the tree
*****************************************************************************************************************/
void HollywoodPay::remove(HollywoodTree *&tree, string n)
{
	if (tree == nullptr) // return when tree is empty
		return;
		
	if (tree->name == n) makeDeletion(tree);
	
	else
	{
		remove(tree->left, n);
		remove(tree->right, n);
	}

}

/****************************************************************************************************************
Function: makeDeletion
Inputs:   root node
Outputs:  delete the root node of a tree that is passed to this function
Purpose:  This function delete the root node of a tree that is passed to this function.
Depend on how many children a node has, the removal procedures are different
*****************************************************************************************************************/
void HollywoodPay::makeDeletion(HollywoodTree* &tree)
{
	
	HollywoodTree *nodeToDelete = tree;

	// locate where left subtree is attached
	HollywoodTree *attachPoint;
	// Node has one child
	if (tree->right == nullptr)
	{
		// Replace tree with its left subtree
		tree = tree->left;
	}

	else if (tree->left == nullptr)
	{
		// Replace tree with its right subtree
		tree = tree->right;
	}
	else
		// Node has two children
	{
		// Move attachPoint to right subtree
		attachPoint = tree->right;
		// Move attachPoint to the smallest node in the right subtree
		while (attachPoint->left != nullptr)
			attachPoint = attachPoint->left;
		// Attach left subtree of original tree to the smallest node of the right subtree
		attachPoint->left = tree->left;
		// Replace original tree with right subtree
		tree = tree->right;
	}
	// Delete root of original tree
	delete nodeToDelete;
}

/****************************************************************************************************************
Function: displayTree
Inputs:   root node
Outputs:  display all nodes in the tree in inoder
Purpose:  This function display all nodes in the tree in reverse "in-inoder" traversal
*****************************************************************************************************************/
void HollywoodPay::displayTree(HollywoodTree* tree)
{
	if (tree)
	{
		displayTree(tree->right);
		cout << " " << tree->name << " - $" << tree->pay << " million" << endl;
		displayTree(tree->left);
	
	}

}



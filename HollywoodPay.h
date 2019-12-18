#pragma once
#ifndef _HOLLYWOODPAY_
#define _HOLLYWOODPAY_
#include <iostream>
#include <string>

using namespace std;

class HollywoodPay
{
private:
	struct HollywoodTree
	{
		float pay;
		string name;
		HollywoodTree* left; // left node
		HollywoodTree* right; // right node
		HollywoodTree(float p, string n)
		{
			pay = p;
			name = n;
			left = nullptr;
			right = nullptr;
		}
	};

	HollywoodTree* root; // root node of binary tree
						 // private methods 
	void insert(HollywoodTree* &, float, string);
	void destroySubtree(HollywoodTree*);
	void remove(HollywoodTree* &, string);
	void makeDeletion(HollywoodTree* &);
	void displayTree(HollywoodTree*);
	// Public interface 
public:
	HollywoodPay()
	{
		root = NULL;
	}

	~HollywoodPay()
	{
		destroySubtree(root);
	}
	
	HollywoodTree* getRootNode()
	{
		return root;
	}


	void insert(float p, string n)
	{
		insert(root, p, n);
	}

	bool search(HollywoodTree* node, string n);
	
	void remove(string n)
	{
		remove(root, n);
	}

	void showTree(void)
	{
		displayTree(root);
	}
};
#include "HollywoodPay.cpp"
#endif

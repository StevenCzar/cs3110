/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #6
	Due: 4/02/20
*/

#include "wordtree.h"
#include <iostream>

WordTree::WordTree() : root(NULL)
{
	//default constructor sets root to NULL
}

WordTree::~WordTree()
{
	//do postorder traversal of tree and delete nodes as you go
	//do left-right-root
	while(root!=NULL)
	{
		deleteSubTree(root);
	}
}

void WordTree::addWord(TreeNode *&node, std::string word)
{
	//check to see if node has empty string in it first
	if(node == NULL)
	{
		node = new TreeNode;
		node->value = word;
		node->left = NULL;
		node->right = NULL;
		node->count = 1;
	}
	//otherwise you're adding a node
	else
	{
		//check equal
		if(node->value == word)
		{
			//increase count
			node->count+=1;
		}
		//check less than
		else if(word < node->value)
		{
			//if there is a node there, go there
			if(node->left!=NULL)
			{
				addWord(node->left, word);
			}
			//if there is no node there, add it
			else
			{
				node->left = new TreeNode;
				node->left->value = word;
				node->left->left = NULL;
				node->left->right = NULL;
				node->left->count = 1;
			}
		}
		//else it is larger...
		else
		{
			//if there is a node there, go there
			if(node->right!=NULL)
			{
				addWord(node->right, word);
			}
			//if there is not a node there, add it
			else
			{
				node->right = new TreeNode;
				node->right->value = word;
				node->right->left = NULL;
				node->right->right = NULL;
				node->right->count = 1;
			}
		}
	}
}

void WordTree::deleteSubTree(TreeNode *node)
{
	//left right root
	//check left
	if(node->left != NULL)
	{
		//go left
		deleteSubTree(node->left);
	}
	//check right
	if(node->right != NULL)
	{
		//go right
		deleteSubTree(node->right);
	}
	//otherwise you're at current node, delete
	delete node;
	node = NULL;
}

void WordTree::getCounts(TreeNode * node, int threshold, int& number) const
{
	//traverse tree inorder
	//left root right
	//if node counter is equal or greater than threshold, output it and add 1 to number

	//see if node is to left
	if(node->left != NULL)
	{
		//go left
		getCounts(node->left, threshold, number);
	}
	//now at the current node...
	//if the count is greater than number of occurances, add 1 to number and print info on what it was
	if(node->count >= threshold)
	{
		std::cout << node->value << "(" << node->count << ")\n";
		number += 1;
	}
	//see if node is on the right
	if(node->right != NULL)
	{
		//go right
		getCounts(node->right, threshold, number);
	}

}

void WordTree::addWord(std::string word)
{
	//just call addword at the root and let it do it's job
	addWord(root, word);
}

void WordTree::findWord(std::string word)
{
	//create traversal node
	TreeNode *node = new TreeNode;
	//set node to be at the root
	node = root;
	//while word isn't found and left and right are both not null
	while((node->value != word) && (node!=NULL))
	{
		std::cout << node->value << std::endl;
		//if less than, go left if you can go left
		if((node->value < word) && (node->left != NULL))
		{
			node = node->left;
		}
		//if greater than, go right if you can go right
		else if((node->value > word) && (node->right != NULL))
		{
			node = node->right;
		}
		else
		{
			//if you make it here, it means you had to go a direction but there wasn't a node there
			//thus not found word
			std::cout << "The word '" << word << "' was not found in the text\n";
			return;
		}
	}
	//when you make it out, it's because you either found the word
	//or both the children are null
	if(node->value == word)
	{
		std::cout << "The word '" << word << "' occurs " << node->count << " time(s) in the text\n";
	}
	else
	{
		std::cout << "The word '" << word << " was not found in the text\n";
	}
	//deallocate space for traversal node
	delete node;
	node = NULL;
}

void WordTree::getCounts(int threshold)
{
	//call getCounts from root
	int number = 0;
	getCounts(root, threshold, number);
	//print final statement
	std::cout << number << " nodes had words with " << threshold << " or more occurance(s).\n";
}
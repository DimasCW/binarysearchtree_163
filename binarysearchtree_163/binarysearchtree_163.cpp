#include <iostream>
#include<string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//Constructur for the node class
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;
	BinaryTree() {
		ROOT = NULL; //Initializing ROOT to null
	}

	void insert(string element) //insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); //Alocate memory for the nenw node
		newNode->info = element; //	Assign value to the data fied of the new node
		newNode->leftchild = NULL; //Make the left child of the new node point to null
		newNode->rightchild = NULL; //Make the right child of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search (element, parent, currentNode); //Locaete the node which will be the parent of the node to be insserted

		if (parent == NULL)// if hte parents is NULL (Tree is empty)
		{
			ROOT = newNode; //Mark the new node as ROOT
			return; //EXIT
		}

		if (element < parent -> info)//if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode;//make the left child of the parent point to the new node
		}
		else if (element > parent->info) //if the value in the data field of the new node is greather than that of the parent
		{
			parent->rightchild = newNode;//make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) {
		//this function searches the currentnode of the specified node as well as the current node of its parent
		currentNode = ROOT;
		parent == NULL;
		while ((currentNode != NULL)&&(currentNode -> info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << "";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL) {
			cout << "tree is empty" << endl;
			return;
		}
	}


};
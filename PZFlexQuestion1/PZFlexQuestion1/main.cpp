#include <iostream>
using namespace std;

//Node class
class Node {
	int key;
	Node* left;
	Node* right;
public:
	Node() { key = -1; left = NULL; right = NULL; };
	void setKey(int aKey) { key = aKey; };
	void setLeft(Node* aLeft) { left = aLeft; };
	void setRight(Node* aRight) { right = aRight; };
	int Key() { return key; };
	Node* Left() { return left; };
	Node* Right() { return right; };
};

// Tree class
class Tree {
	Node* root;
public:
	Tree();
	~Tree();
	Node* Root() { return root; };
	void addNode(int key);
	int countNodes(Node* root);
	bool compareTrees(Tree* otherTree);
	bool compareNodes(Node* n1, Node* n2);
private:
	void addNode(int key, Node* leaf);
	void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() {
	root = NULL;
}

// Destructor
Tree::~Tree() {
	freeNode(root);
}

// Free the node
void Tree::freeNode(Node* leaf)
{
	if (leaf != NULL)
	{
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}

// Add a node
void Tree::addNode(int key) {
	// No elements. Add the root
	if (root == NULL) {
		cout << "add root node ... " << key << endl;
		Node* n = new Node();
		n->setKey(key);
		root = n;
	}
	else {
		cout << "add other node ... " << key << endl;
		addNode(key, root);
	}
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf) {
	if (key <= leaf->Key()) {
		if (leaf->Left() != NULL)
			addNode(key, leaf->Left());
		else {
			Node* n = new Node();
			n->setKey(key);
			leaf->setLeft(n);
		}
	}
	else {
		if (leaf->Right() != NULL)
			addNode(key, leaf->Right());
		else {
			Node* n = new Node();
			n->setKey(key);
			leaf->setRight(n);
		}
	}
}

//function to count the nodes in a tree
int Tree::countNodes(Node* root)
{
	if (root == NULL)
	{
		return 0;  //shows that the tree is empty
	}
	else {
		int count = 1;   //counts the root as the first node found
		count += countNodes(root->Left());

		count += countNodes(root->Right());

		return count;
	}
}

//compares the values of the nodes in the tree
//to see if the trees are the same
bool Tree::compareTrees(Tree* otherTree)
{
	bool areTreesSame;

	Node* firstTree = this->Root();
	Node* secondTree = otherTree->Root();

	if (firstTree->Key() == secondTree->Key())
	{
		//roots are therefore the same
		areTreesSame = this->compareNodes(firstTree, secondTree);
	}
	else
	{
		//roots are not the same therefore trees are not similar
		areTreesSame = false;
	}

	return areTreesSame;
}

bool Tree::compareNodes(Node* n1, Node* n2)
{
	if (n1 || n2)
	{
		if (n1->Key() == n2->Key())
		{
			compareNodes(n1->Left(), n2->Left());
			compareNodes(n1->Right(), n2->Right());
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

int main()
{
	//creates new tree
	Tree* tree1 = new Tree();

	//fills tree 1 with nodes
	tree1->addNode(10);
	tree1->addNode(20);
	tree1->addNode(30);
	tree1->addNode(40);
	tree1->addNode(50);
	tree1->addNode(60);
	tree1->addNode(70);

	cout << "Tree 1 completed\n\n";

	//creates second tree
	Tree* tree2 = new Tree();

	//fills second tree with nodes
	tree2->addNode(10);
	tree2->addNode(20);
	tree2->addNode(30);
	tree2->addNode(40);
	tree2->addNode(50);
	tree2->addNode(60);
	tree2->addNode(70);

	cout << "Tree 2 completed\n\n";

	//compares structures of trees
	cout << "Comparison of trees\n";
	int numNodesTree1 = tree1->countNodes(tree1->Root());
	int numNodesTree2 = tree2->countNodes(tree2->Root());

	//tells the user if the structure of both trees are similar or not
	if (numNodesTree1 == numNodesTree2)
	{
		cout << "Both trees have a similar structure as they contain the same number of nodes (" << numNodesTree1 << ").";

		//checks to see if the values of the nodes in each tree are the same
		bool areTreesSameValue = tree1->compareTrees(tree2);

		//tells the user if the trees have the same values
		if (areTreesSameValue == true)
		{
			cout << "Both trees have the same value, therefore are the same tree.";
		}
	}
	else
	{
		cout << "Both trees have different structures, Tree 1 contains " << numNodesTree1 << " nodes, whilst tree 2 contains " << numNodesTree2 << " nodes.";
		cout << "The trees are not identical.";
	}

	int in;
	cin >> in;
	return 0;
}
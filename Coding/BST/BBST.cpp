// C++ program to convert a left and right unbalanced BSTs to a balanced BST
#include <bits/stdc++.h>
using namespace std;

// Node Structure
struct Node {
	int data;
	Node* left;
    Node* right;
};

// Utility function to create a new node
Node* newNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// Function to do preorder traversal of tree
void preOrder(Node* node) {
    // Base case
    if(node == NULL)
		return;
	
    cout<<("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// This function traverse the skewed binary tree and stores its nodes pointers in vector nodes[]
void storeBSTNodes(Node* root, vector<Node*> &nodes) {
    // Base case
	if(root==NULL)
		return;

	// Store nodes in Inorder (which is sorted order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

// Recursive function to construct binary tree 
Node* buildTreeUtil(vector<Node*> &nodes, int start, int end) {
    // base case
	if(start > end)
		return NULL;

	// Get the middle element and make it root.
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	// Using index in Inorder traversal, construct left and right subtress
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

// This functions converts an unbalanced BST to a balanced BST
Node* buildTree(Node* root) {
    // Store nodes of given BST in sorted order
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Balancing left-screwed tree.
void executeExample1(){
    /* Ex-1 Constructed skewed binary tree is
                    10
                /
                8
            /
            7
        /
        6
    /
    5 
    */

    Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	cout<<("Preorder traversal of balanced BST is :")<<endl;
	preOrder(root);
    cout<<endl;
}

// Balancing right-screwed tree.
void executeExample2(){
    /* Ex-2 Constructed skewed binary tree is
                    5
                        \
                        6
                            \
                            7
                                \
                                8
                                    \
                                    10 
    */

    Node* root = newNode(5);
	root->right = newNode(6);
	root->right->right = newNode(7);
	root->left->right->right = newNode(8);
	root->right->right->right->right = newNode(10);

	root = buildTree(root);

	cout<<("Preorder traversal of balanced BST is :")<<endl;
	preOrder(root);
    cout<<endl;
}

// Driver program
int main() {
    executeExample1();
    // executeExample2();

	return 0;
}
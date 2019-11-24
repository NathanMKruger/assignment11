//	Nathan Kruger
//
//  bst.h
//  
//  Defines a class for a binary search tree.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef bst_hpp
#define bst_hpp

#include <list>
#include <optional>
#include <random>

using namespace std;

namespace csi281 {
    
    
    template <typename T>
    class BST {
    public:
        // *Node* represents one node in the tree
        struct Node {
            Node (T k, Node *l, Node *r) : key(k), left(l), right(r) {}
            T key;
            Node *left;
            Node *right;
        };
        
        // Delete a node and all of its children
        void deleteHelper(Node *node) {
            if (node == nullptr) { return; }
            deleteHelper(node->left);
            deleteHelper(node->right);
            delete node;
        }
        
        // Delete all nodes
        ~BST() {
            deleteHelper(root);
        }
        
        // Add a new node to the tree with *key*
        // Make sure to insert it into the correct place
        // NOTE: We are allowing duplicates, so, <= and >, or < and >=
        // for traversing left and right should be used
        // TIP: If the tree is empty, remember that you
        // need to initialize root
        void insert(T key) {
            // YOUR CODE HERE
			Node myNode = new Node (key, nullptr, nullptr);
			Node *currentNode = root;

			while (currentNode != nullptr)
			{
				myNode = currentNode; //reassign new myNode as currentNode
				if (key <= currentNode->key)
				{
					currentNode = currentNode->left; //go to the left of currentNode
				}
				else //if key is greater than the key value in currentNode
				{
					currentNode = currentNode->right; //go to the right of currentNode
				}
			}

			if (root == nullptr) //sees if root exists or not
			{
				root->key = key; //if not, then the current key will become the root node
			}
			else if (key <= myNode->key)
			{
				myNode->left = key; //insert new key and replace the nullptr left of myNode
			}
			else //if key is greater than key value of myNode
			{
				myNode->right = key; //insert new key and replace the nullptr right of myNode
			}

			count++; //increment count variable
        }
        
        // Do a search through the tree and return
        // whether or not it contains *key*
        bool contains(const T &key) {
            // YOUR CODE HERE
			Node *currentNode = root; //create and track current node
			  while (currenNode != nullptr && key != currentNode->key)
			  {
				  if (key < currentNode->key)
				  {
					currentNode = currentNode->left; //move currentNode to the left
				  }
				  else //if the key is greater than the key within currentNode
				  {
					currentNode = currentNode->right; //move currentNode to the right
				  }
			}
			  if (currentNode->key == key)
			  {
				  return true; //key is contained in the tree
			}
			  else
			  {
				  return false; //key is NOT contained in the tree
			  }
        }
        
        // Helper for inOrderWalk() to call for entire bst
        void inOrderWalk(list<T> &accumulated) {
            inOrderWalk(accumulated, root);
        }
        
        // Walk through the entire tree in ascending order, starting
        // from *current*, and accumulate the values in the
        // list *accumulated*
        // TIP: See page 288 of Chapter 12 of Introduction to Algorithms
        void inOrderWalk(list<T> &accumulated, Node *current) {
            // YOUR CODE HERE
			  if (current != nullptr)
			  {
				  inOrderWalk(accumulated, current->left); //go to all available left nodes in regards to current
				cout << current->key; //print key in current
				inOrderWalk(accumulated, current->right); //move to the next right node in regards to current
			}
        }
        
        // Find the minimum key in the tree
        // If the tree is empty, return nullopt
        optional<T> minimum() {
            // YOUR CODE HERE
			Node *currentNode = root; //tracks current node
			while (currentNode->left != nullptr) //loop goes until the end of the complete left side
			{
				currentNode = currentNode->left //assign currentNode with the smaller valued left node
			}
			return currentNode->key; //return the value/key of the currentNode when at end of tree hight
        }
        
        // Find the maximum key in the tree
        // If the tree is empty, return nullopt
        optional<T> maximum() {
            // YOUR CODE HERE
			Node *currentNode = root; //tracks current node
			while (currentNode->right != nullptr) //loop goes until the end of the complete right side
			{
				currentNode = currentNode->right; //assign currentNode with the larger valued right side
			}
			return currentNode->key; //return the value/key of the currentNade when at the end of tree hight
        }
        
        // How many nodes are in the tree?
        int getCount() { return count; }
    
    private:
        Node *root = nullptr;
        int count = 0;
    };
    
    
}


#endif /* bst_hpp */

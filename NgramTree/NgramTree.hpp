//
//  NgramTree.hpp
//  Created by Gökberk Keskinkılıç on 8.11.2021.
//

#ifndef NgramTree_hpp
#define NgramTree_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef string string;

class TreeNode {            // node in the tree
private:
    TreeNode() {}
    TreeNode(const string& nodeItem, TreeNode *left = NULL, TreeNode *right = NULL)
    :item(nodeItem),count(1),leftChildPtr(left),rightChildPtr(right) {}

    string item;                // data portion
    int count;                  // occurence count
    TreeNode *leftChildPtr;     // pointer to left child
    TreeNode *rightChildPtr;    // pointer to right child

    friend class NgramTree;
};


class NgramTree{
public:
    NgramTree();
    ~NgramTree();
    
    void destroyNgramTree();
    
    void addNgram( string ngram );
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree( string fileName, int n );
    // my additional public functions
    TreeNode* ngramTreeRetrieve( string searchKey);
    //void ngramTreeRetrieve( string searchKey, TreeNode*& node);
    void ngramTreeInsert(const string newItem);
    void printTree( ostream& out, TreeNode* tree);
    
private:
    TreeNode* root;
    bool isEmpty();
    TreeNode* retrieveItem(TreeNode*& treePtr, string searchKey);
    //void retrieveItem(TreeNode* treePtr, string searchKey, TreeNode*& node);
    void insertItem(TreeNode*& treePtr, const string newItem);
    friend ostream& operator<<( ostream& out, NgramTree tree );
    int countNodes(TreeNode* root);
    bool isCompleteHelper( TreeNode* root, int index, int totalCount);
    bool isFullTreeHelper( TreeNode*& root);
    int getHeight( TreeNode*& node);
    
};

#endif /* NgramTree_hpp */

//
//  NgramTree.cpp
//  Created by Gökberk Keskinkılıç on 8.11.2021.
//

#include "NgramTree.hpp"
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cmath>

/**
 @brief empty constructor for ngram tree
 */
NgramTree::NgramTree(){
    root = NULL;
}

/**
 @brief deconstructor for ngram tree
 */
NgramTree::~NgramTree(){
    
}

void NgramTree::addNgram( string ngram){
    // if root is empty, initialize the tree
//    TreeNode* tmp = ngramTreeRetrieve( ngram);
//    TreeNode* tmp;
//    ngramTreeRetrieve(ngram, tmp);
//    if (tmp == NULL){      // means that item couldn't be found
//        ngramTreeInsert(ngram);
//        cout << ngram << " inserted ----- couldnt be found" << endl;
//    }
//    else{
//        tmp->count = tmp->count + 1;
//        cout << ngram << "'s count incremented +++++" << endl;
//    }
    ngramTreeInsert(ngram);

}

int NgramTree::countNodes(TreeNode* root){
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->leftChildPtr) + countNodes(root->rightChildPtr));
}

int NgramTree::getTotalNgramCount(){
    return countNodes( root);
}

bool NgramTree::isComplete(){
    int totalCount = getTotalNgramCount();
    int index = 0;
    return isCompleteHelper( root, index, totalCount);
}

bool NgramTree::isCompleteHelper( TreeNode* root, int index, int totalCount){
    if (root == NULL)
        return true;

    else if (index >= totalCount)
        return false;
    else
        return ( isCompleteHelper( root->leftChildPtr, 2 * index + 1, totalCount ) && isCompleteHelper( root->rightChildPtr, 2 * index + 2, getTotalNgramCount()));
}

bool NgramTree::isFull(){
    return isFullTreeHelper(root);
}

bool NgramTree::isFullTreeHelper( TreeNode*& root){
    // If empty tree
    if (root == NULL)
        return true;
    else if ( getTotalNgramCount() == ( pow( 2, getHeight(root) ) - 1) )
        return true;
    else
        return false;
}

void NgramTree::generateTree( string fileName, int n){
    string text;                // content of input file
    ifstream file;
    file.open( fileName.c_str(), fstream::in );
    if (file.is_open()){
        while( file >> text){           // take file word by word
            if( (int)text.length() >= n){
                for( int i = 0; i <= (int)text.length() - n; i++){
                    string subn = text.substr(i,n);
                    addNgram( subn );       // add ngram to tree
                }
            }
        }
        file.close();           // Close the file
    }
    else cout << "Unable to open file :( \n";
}

//void NgramTree::ngramTreeRetrieve( string searchKey, TreeNode*& node){
//        retrieveItem( root, searchKey, node);
//}
//
//void NgramTree::retrieveItem( TreeNode* treePtr, string searchKey, TreeNode*& node){
//    if (treePtr == NULL)
//        cout << "key not found" << endl;
//    else if (searchKey == treePtr->item)
//        node = treePtr;
//    else if (searchKey < treePtr->item)
//        retrieveItem(treePtr->leftChildPtr, searchKey, node);
//    else
//        retrieveItem(treePtr->rightChildPtr, searchKey, node);
//}

//
//TreeNode* NgramTree::ngramTreeRetrieve( string searchKey){
//        return retrieveItem( root, searchKey);
//}
//
//
//TreeNode* NgramTree::retrieveItem(TreeNode*& treePtr, string searchKey){
//    if (treePtr == NULL) {
//        return NULL;        // return NULL to indicate not found
//    } else {
//        if (searchKey == treePtr->item) {
//            cout << treePtr->item << " found---------" << endl;
//            return treePtr; // node found
//        }
//        else if (searchKey < treePtr->item) {
//            retrieveItem(treePtr->leftChildPtr, searchKey);
//        }
//        else {
//            retrieveItem(treePtr->rightChildPtr, searchKey);
//        }
//    }
//    return NULL; // it will not come to this stage, just to shut up compiler
//}

void NgramTree::ngramTreeInsert(const string newItem){
        insertItem(root, newItem);
}

void NgramTree::insertItem(TreeNode*& treePtr, const string newItem){
    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new TreeNode( newItem, NULL, NULL);
        cout << "---" << newItem << " added to tree" << endl;
        if (treePtr == NULL)
            cout << "error: insert failed";
    }
    // Else search for the insertion position
    else{
        if( newItem == treePtr->item){
            (treePtr->count)++;
            cout << newItem << "'s count incremented +++++" << endl;
        }
        else if ( newItem < treePtr->item){
            insertItem(treePtr->leftChildPtr, newItem);
        }
        else{
            insertItem(treePtr->rightChildPtr, newItem);
        }
    }
}

void NgramTree::printTree(ostream& out, TreeNode* root){
    if( root != NULL){
        printTree( out, root->leftChildPtr);
        cout << root->item << " appears " << root->count << " time(s)" << endl;
        printTree( out, root->rightChildPtr);
    }
}

ostream& operator<<(ostream& out, NgramTree tree){
    if( tree.root == NULL){
        cout << "Tree is empty." << endl;
        return out;
    }
    tree.printTree( out, tree.root);
    return out;
}

int NgramTree::getHeight( TreeNode*& node){
    if (node == NULL) {
        return 0;
    }
    else {
        return 1 + max(getHeight(node->leftChildPtr), getHeight(node->rightChildPtr));
    }
}






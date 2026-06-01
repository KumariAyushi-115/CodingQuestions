/*
Problem Statement #
Given a binary tree where each node can only have a digit (0-9) value, each root-to
leaf path will represent a number. Find the total sum of all the numbers
represented by all paths
*/

#include <iostream>
using namespace std;

class Node{
    public:
    
    int val;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        this->val =val;
        this->left =nullptr;
        this->right= nullptr;
    }
};


int helperFunction(Node* root, int num){
    
    if(root == nullptr) return num;
    
    num = num*10 + root->val;
    
    if(root->left  == nullptr && root->right == nullptr){
     return num;
        
    }
    
    else{
        
       return helperFunction(root->left, num)  +  helperFunction(root->right, num);
        
        
    }
    
}


int sum(Node* root){
    
    return helperFunction(root,0);
    
    
}

int main() {
   
  Node* root = new Node(1);
   root->left = new Node(7);
   root->right=new Node(9);
  
   root->left->left = new Node(4);
   root->left->right= new Node(5);
   
   root->right->left = new Node(2);
   root->right->right = new Node(7);
   
   cout<<sum(root);

    return 0;
}

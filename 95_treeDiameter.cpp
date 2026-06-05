/*
  Tree Diameter (medium) #
Given a binary tree, find the length of its diameter. The diameter of a tree is the
number of nodes on the longest path between any two leaf nodes. The diameter
of a tree may or may not pass through the root
*/

#include <iostream>
#include<vector>
#include <climits>
#include<algorithm>
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

int helper(Node* root, int &maxi){
    
    if(root == nullptr) return 0;
    
    int left_height = helper(root->left,maxi);
    int right_height = helper(root-> right, maxi);
    
    int total = left_height + right_height +1;
    
    if(maxi < total){
        maxi = total;
    }
    
    return max(left_height ,right_height) +1 ;
    
}

int treeDiameter(Node*root){
    int maxi = 0;
    helper(root, maxi);
    return maxi;
}

int main() {
   
  Node * root = new Node(1) ;
  root->left = new Node(0) ;
  root->right =new Node(1) ;
  root->left->left =new  Node(1); 
  root->left->right =new Node(2);
  root->right->left = new Node(6); 
  root->right->right = new Node(5); 
  
cout<<treeDiameter(root);
    return 0;
}

/*
  Problem Statement #
Given a binary tree and a number sequence, find if the sequence is present as a
root-to-leaf path in the given tree
*/

#include <iostream>
#include<vector>
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

bool helper(Node* root, vector<int> &seq, int i){
    
    if(root == nullptr ) return false;
    
    if( i>seq.size()-1 || root->val != seq[i])
    {
        return false;
    }
    
    if(root->val == seq[i] && root->left == nullptr && root->right == nullptr && i == seq.size()-1 )
    {
        return true;
    }
    
    return helper(root->left,seq,i+1) || helper(root->right,seq,i+1);

}
bool sequenceCheck(Node* root, vector<int> &seq){
    
    if(root == nullptr) 
      return seq.empty();
  
   return helper(root, seq, 0);
}

int main() {
   
  Node * root = new Node(1) ;
  root->left = new Node(0) ;
  root->right =new Node(1) ;
  root->left->left =new  Node(1); 
  root->right->left = new Node(6); 
  root->right->right = new Node(5); 
  vector<int> seq = {1,0,7};
   cout<<sequenceCheck(root,seq);
seq = {1,1,6};
 cout<<sequenceCheck(root,seq);

    return 0;
}

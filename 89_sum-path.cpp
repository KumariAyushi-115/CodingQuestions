/*
Problem Satetement : Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf
such that the sum of all the node values of that path equals ‘S’.
*/

#include <iostream>
#include<vector>
#include<queue>
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

bool check(Node* root, int sum){
    if(root == nullptr)
    return false;
    
    if(root->val == sum && root->left == nullptr && root->right == nullptr){
        return true;
    }
    
   int rem_sum = sum - root->val;
    
   return check(root->left,rem_sum) || check(root->right,rem_sum);

}

int main() {
   
  Node* root = new Node(1);
   root->left = new Node(2);
   root->right=new Node(3);
  
   root->left->left = new Node(4);
   root->left->right= new Node(5);
   
   root->right->left = new Node(6);
   root->right->right = new Node(7);

  cout<<check(root,10);
  
    return 0;
}

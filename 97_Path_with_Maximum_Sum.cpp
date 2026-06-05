/*

Path with Maximum Sum (hard) #
Find the path with the maximum sum in a given binary tree. Write a function that
returns the maximum sum.
A path can be defined as a sequence of nodes between any two nodes and
doesn’t necessarily pass through the root. The path must contain at least one node.

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

int helper(Node* root, int &sum){
    
    if(root == nullptr) return 0;
    
    int left_sum = max(0,helper(root->left,sum));
    int right_sum = max(0,helper(root-> right, sum));
    
    int total = left_sum + right_sum + root->val;
    
    if(sum < total){
        sum = total;
    }
    
    return max(left_sum ,right_sum) + root->val; ;
    
}

int maxSum(Node*root){
    if(root == nullptr) return 0;
    int sum = INT_MIN;
    helper(root, sum);
    return sum;
}

int main() {
   
  Node * root = new Node(1) ;
  root->left = new Node(0) ;
  root->right =new Node(1) ;
  root->left->left =new  Node(1); 
  root->left->right =new Node(2);
  root->right->left = new Node(6); 
  root->right->right = new Node(5); 
  
cout<<maxSum(root);
    return 0;
}

/*
Problem Statement #
Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of
all the node values of each path equals ‘S’. Please note that the paths can start or
end at any node but all paths must follow direction from parent to child (top to
bottom)
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


void helper(Node* root,int sum, vector<vector<int>> &res, vector<int>& cur){
    
    if(root == nullptr) return ;
    
    cur.push_back(root->val);
    
    long long curSum =0;
    for(int i=cur.size()-1;i>=0;i--){
        curSum += cur[i];
        
        if(sum == curSum){
            vector<int> sub(cur.begin()+i, cur.end());
        res.push_back(sub);
        }
    }
    
    helper(root->left, sum, res, cur);
    
    helper(root->right, sum, res, cur);
    
    cur.pop_back();
}

vector<vector<int>> func(Node* root,int sum){
    
    vector<vector<int>> result;
    vector<int> cur;
    if(root == nullptr) return  result;
    helper(root,sum,result,cur);
    
    return result;
    
    
}
int main() {
   
  Node * root = new Node(1) ;
  root->left = new Node(0) ;
  root->right =new Node(1) ;
  root->left->left =new  Node(1); 
  root->right->left = new Node(6); 
  root->right->right = new Node(5); 
 
 vector<vector<int>> ch = func(root, 7);
 
 for(auto c: ch){
     for(auto k : c){
         cout<<k<<"->";
     }
     cout<<endl;
 }
  

    return 0;
}

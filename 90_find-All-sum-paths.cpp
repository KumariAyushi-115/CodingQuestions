/*
Problem Statement #
Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the
sum of all the node values of each path equals ‘S’.
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

void helper(Node* root,int sum, vector<vector<int>>& allpaths, vector<int>& cur_path ){
    
    if(root == nullptr)return;
    
    cur_path.push_back(root->val);
    
    if(root->val==sum && root->left == NULL && root->right == NULL){
        allpaths.push_back(cur_path);
    }
    
    helper(root->left, sum - root->val, allpaths,cur_path);
    helper(root->right, sum - root->val, allpaths,cur_path);
    
    cur_path.pop_back();
    
}
vector<vector<int>> findAllPath(Node*root, int sum){
    vector<vector<int>> a;
    vector<int> c;
    helper(root,sum,a,c);
    return a;
}

int main() {
   
  Node* root = new Node(1);
   root->left = new Node(7);
   root->right=new Node(9);
  
   root->left->left = new Node(4);
   root->left->right= new Node(5);
   
   root->right->left = new Node(2);
   root->right->right = new Node(7);

  vector<vector<int>>vec=  findAllPath(root,12);
  for(auto k : vec){
      for(auto i : k){
          cout<<i<<" ";
      }
      cout<<endl;
  }
    return 0;
}

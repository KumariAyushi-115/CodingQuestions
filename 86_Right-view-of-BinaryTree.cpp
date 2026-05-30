/*Problem statement :  Right View of a Binary Tree (easy) #
Given a binary tree, return an array containing nodes in its right view. The right
view of a binary tree is the set of nodes visible when the tree is seen from the
right side.*/
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

vector<int> rightViewBT(Node* root){

    vector<int> res;
    if(root == nullptr){
        return res;
    }
    queue<Node*> q;
    q.push(root);
 
    while(!q.empty()){
   
        int level = q.size();
        int lastVal =0;
        for(int i=0;i<level;i++){
            Node* cur = q.front();
            q.pop();
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
            lastVal =  cur->val;
      
        }
        res.push_back(lastVal);
    }
    
    return res;
}


int main() {
   
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right=new Node(3);
   root->left->left = new Node(4);

  
  vector<int> vec =rightViewBT(root);
  for(auto  k: vec){
      cout<<k;
  }
    return 0;
}

#include <iostream>
#include <deque>
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

deque<vector<int>> reverseLevelOrderTraverse(Node* root){
    deque<vector<int>> res;
    if(root == nullptr) return res ;
    
    queue<Node*> q;
    q.push(root);
    
    while(! q.empty()){
        int level = q.size();
        vector<int> levelwise;
        
        for(int i =0;i<level;i++){
            Node* cur = q.front();
            q.pop();
            levelwise.push_back(cur->val);
            
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
            
        }
        
        res.push_front(levelwise);
    }
    return res;
}



int main() {
    // Write C++ code here
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right=new Node(3);
  
   root->left->left = new Node(4);
   root->left->right= new Node(5);
   
   root->right->left = new Node(6);
   root->right->right = new Node(7);
   
   
  deque<vector<int>> s =  reverseLevelOrderTraverse( root);
  
  for(auto c: s){
      for(auto k:c){
          cout<<k<<"->";
      }
      cout<<endl;
  }
    return 0;
}

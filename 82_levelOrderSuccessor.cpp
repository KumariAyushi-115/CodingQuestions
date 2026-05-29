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


int levelOrderSuccessor(Node* root, int key){
    
    if(root == nullptr) return -1;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        
        for(int i = 0; i< level ; i++){
            Node* cur = q.front();
            q.pop();
            
            if(cur->left !=nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
            
            if(cur->val == key && !q.empty() )
            return q.front()->val;
        }
    }
    return -1;
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
   
   
 int ch = levelOrderSuccessor(root,1);
 cout<<ch;
 
}

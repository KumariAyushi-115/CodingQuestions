#include <iostream>
#include<queue>

using namespace std;

class Node{
    public:
    
    int val;
    Node* left;
    Node* right;
    Node* next ;
    Node(int val)
    {
        this->val =val;
        this->left =nullptr;
        this->right= nullptr;
        this->next = nullptr;
    }
};

void connectAllOrderSibling(Node* root){
    if(root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        
        for(int i =0;i< level ; i++){
             Node* cur = q.front();
             q.pop();
            
            if(cur->left !=nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
            
            if(!q.empty()){
                cur->next = q.front();
            }
            else{
                cur->next=NULL; //for reusability as per arichitectural reusability for real time application 
            }
            
        }
    }
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
   
  connectAllOrderSibling(root);
 
}

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next =  nullptr;
    }

};


Node* subReverse(int k, Node* head){

    if(k<=1 || head == nullptr)return head;

    Node* cur = head;
    Node* prev = nullptr;
    Node* next = NULL;

    while(true){
       
        Node* prevSublistLast = prev;
        Node* curSublistLast = cur;

        for(int i=0;i<k && cur != nullptr;i++){
            next =cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if(prevSublistLast != NULL){
            prevSublistLast->next=prev;
        }
        else{
            head = prev;
        }
          curSublistLast->next = cur;

        if(cur == nullptr) break;

    
        prev = curSublistLast;
    }

    return head;
}

void print(Node* head){
    Node* cur = head;

    while(cur != NULL){

        if(cur->next == nullptr){
            cout<<cur->val;
            break;
        }
        cout<<cur->val <<"->";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
   // cout<<"hello";
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next =  new  Node(3);
    head->next->next->next =  new Node(4);
    head->next->next->next->next = new Node(5);
   print(head);

   head= subReverse(3,head);
   print(head);
}
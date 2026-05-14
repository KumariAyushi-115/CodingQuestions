#include <iostream>
using namespace std;

class ListNode { 
 public: 
  int value = 0; 
  ListNode *next; 
  ListNode(int value) { 
    this->value = value; 
    next = nullptr; 
  } 
}; 

ListNode* reverse(ListNode*head){
    
    ListNode*cur = head;
    ListNode*prev =NULL;
    ListNode*next;
   
    while(cur != nullptr  ){
       next = cur->next;
       cur->next = prev;
       prev = cur;
       cur = next;
    }
    
    return prev;
}

ListNode * subReverse(int k, ListNode* head){
    
    ListNode*cur = head;
    ListNode*prev = nullptr;
    ListNode*next = nullptr;
     bool flag = true;
    
    while(true){
        
        ListNode* prevLast = prev;
        ListNode* curLast = cur;
        
        if(flag){
             
        for(int i = 0;i<k && cur != nullptr;i++){
            next = cur->next;
            cur->next =prev;
            prev = cur;
            cur =next;
    
        }
        
        if(prevLast != NULL){
           prevLast->next = prev;
        }
        else{
            head = prev;
        }
        curLast->next = cur;
        if(cur == nullptr ) break;
        
      
        flag=false;
        //prev = curLast;
        }
        
        else{
         
        //cout<<endl<<prev->value<<endl;
            for(int i=0;i<k;i++){
               
               prev = cur;
               cur = cur->next;
            
            }
             if(cur == nullptr ) break;
           //  cur=temp;
            // prev=
            cout<<endl<<prev->value<<endl;
            flag = true;
        }
        
        
    }
    return head;
    
}
void print(ListNode *head){
    ListNode *cur = head;
    while(cur != nullptr){
        if (cur->next == nullptr)
        {
            cout<<cur->value<<endl;
            break;
        }
        else {
        cout<<cur->value<< "->";
        cur=cur->next;
        }
    }
   // cout<<endl;
}
int main() {
    // Write C++ code here
     ListNode *head = new ListNode(1); 
  head->next = new ListNode(2); 
  head->next->next = new ListNode(3); 
  head->next->next->next = new ListNode(4); 
  head->next->next->next->next = new ListNode(5); 
  head->next->next->next->next->next = new ListNode(6); 
  head->next->next->next->next->next->next = new ListNode(7); 
  head->next->next->next->next->next->next->next = new ListNode(8); 
 head->next->next->next->next->next->next->next->next = new ListNode(9); 
 head->next->next->next->next->next->next->next->next->next = new ListNode(10); 
 head->next->next->next->next->next->next->next->next->next->next = new ListNode(11); 
 head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(12); 
print(head);
head = subReverse(2,head);
print(head);
    return 0;
}

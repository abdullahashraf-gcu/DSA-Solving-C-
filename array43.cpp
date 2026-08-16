#include <iostream>

using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
   
int main() {
    
   
    ListNode* head = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);
    ListNode* node4 = new ListNode(40);
    ListNode* node5 = new ListNode(50);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next=node3;

    ListNode *temp=head;
    ListNode *prev=nullptr;

    while ( temp != NULL || temp != nullptr){
        ListNode * front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    

    while (prev != NULL) {
            cout << prev->val << " -> ";
            prev = prev->next;
        }
    
    
    return 0;
}
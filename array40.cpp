#include <iostream>

using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };



int main() {
    
   
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
  

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    ListNode* slow = head;
    ListNode* fast = head;


        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                cout<<slow->val<<endl;
                cout<<fast->val<<endl;
                break;
                // return slow;
            }
        }
        vrwrf
        // return NULL;
    
    
    return 0;
}
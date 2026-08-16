#include <iostream>

using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

   bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }


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

   bool hasC =hasCycle(head);
    
    
    return 0;
}
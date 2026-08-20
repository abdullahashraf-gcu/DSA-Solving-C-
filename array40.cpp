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
    ListNode* check=head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps
            if(check==slow || check== fast){
                // return check;
            }
            if (slow == fast) {
                check=check->next;
            }
        }
        
         return NULL;
    
    
    return 0;
}
// this sol works fine , but better sol is below , for visuals : https://leetcode.com/problems/linked-list-cycle-ii/description/comments/1576428/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Phase 2: Find cycle start
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};
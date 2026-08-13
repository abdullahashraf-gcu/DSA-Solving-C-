#include<iostream>

using namespace std;

struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
class Solution {
public:
    void deleteNode(ListNode* node) {
      
        while (true){
  if(node->next->next==NULL){
             node->val=node->next->val;
             node->next=NULL;
             break;
        }
        node->val=node->next->val;
        node=node->next;
        }

    }
};
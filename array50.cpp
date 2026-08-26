#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(1);

    

    head->next = node2;
    node2->next = node3;
    node3->next = nullptr;
 

     ListNode* temp=head;
        int count=0;

        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }

        int array[count/2];
        temp=head;
        for(int i = 0 ; i<count/2;i++){
            array[i]=temp->val;
            temp=temp->next;
        }
        if(count%2!=0){
            temp=temp->next;
        }
        cout<<array[0]<<endl;
        bool isPal=true;
         for(int i = (count/2)-1 ; i>=0;i--){
            if(array[i]!=temp->val){
                cout<<array[i]<<" "<<i<<" "<<temp->val<<endl;
                isPal=false;
                break;
            }
            temp=temp->next;
        }


    return 0;
} 
 
 


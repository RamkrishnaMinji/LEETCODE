#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast, *slow;

        if(head->next==NULL){
            delete(head);
            head=NULL;
            return head;
        }
        if(head->next->next==NULL) {
            delete(head->next);
            head->next=NULL;
            return head;
        }
        
        fast=slow=head;
        fast = fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};
int main(){

}

//here fast and slow pointer is used to go to the middle of the linked list
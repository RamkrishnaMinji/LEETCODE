#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
 
    ListNode* rev(ListNode* head){
        if(!head||head->next==NULL) return head;
        ListNode* prev,*curr,*ptr;
        prev = NULL;
        curr=head;
        ptr=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=ptr;
            if(ptr)
            ptr=ptr->next;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow,*fast;
        ListNode* curr = head;
        slow=head;
        fast=head->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        int ans=-1;
        
        slow->next = rev(slow->next);
        
        slow = slow->next;
        while(slow){
            if((curr->val+slow->val)>ans) ans = slow->val+curr->val;
            slow=slow->next;
            curr=curr->next;
        }
        return ans;
    }
};

int main(){

}
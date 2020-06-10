/*19. Remove Nth Node From End of List
Medium

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p1=head;
        ListNode* p2=head;
     
        for(int i=0;i<n && p2!=NULL;i++)
            p2=p2->next;
        if(p2==NULL) return p1->next;
        while(p2->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        
        p1->next=p1->next->next;
        return head;
        
  
    }
};

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* head=NULL; 
             if(l1->val < l2->val){
                    
                    head=l1;
                    l1=l1->next;

                }
                 else {
                    
                    head=l2;
                    l2=l2->next;

                }
        
        ListNode* L=head;
        while(l1!=NULL && l2!=NULL){
            
             
                if(l1->val < l2->val){
                    
                    L->next=l1;
                    l1=l1->next;

                }
                 else {
                    
                    L->next=l2;
                    l2=l2->next;

                }
            L=L->next;
        }
            
            
        if(l1!=NULL)
            L->next=l1;
        else
            L->next=l2;
            
        return head;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size(),i=1;
       
        if(n==0) return NULL;
        if(n==0) return lists[0];
        
        while(lists.size()>1){
            lists.push_back(mergeTwoLists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
        
    }
};

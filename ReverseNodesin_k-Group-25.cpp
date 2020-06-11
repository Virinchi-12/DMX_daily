class Solution {
public:
//     ListNode* reverseList(ListNode* head,ListNode* tail) {
//         ListNode *prev=tail;
//         while(head!=tail){
            
//             auto *temp=head->next;
//             head->next=prev;
//             prev=head;
//             head=temp;
//         }
//         return prev;
        
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* node=head;
//         for(int i=0;i<k;++i)
//         {
//             if(node==NULL)
//                 return head;
            
//             node=node->next;
//         }
        
//         ListNode* newhead=reverseList(head,node);
//         head->next=reverseKGroup(node,k);
//         return newhead;
        
    //Above code also works but is a bit complicated
    
    
    int lenoflist(ListNode* head){
        int len=0;
        if(head==NULL) return 0;
        ListNode* node=head;
        while(node!=NULL){
            len++;
            node=node->next;
        }
        return len;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(lenoflist(head)<k) return head;
        
        ListNode* cur=head,*prev=NULL,*next=NULL;
        
        for(int i=0;i<k;i++){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        // return prev;
        head->next=reverseKGroup(cur,k);
        return prev;
        
    }
    
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode*  dummy=new  ListNode();
         ListNode*  prev=dummy;
          dummy->next=head;
        int n=0; 
         ListNode*  temp=dummy;
         ListNode*  curr=dummy;
         ListNode* nex=dummy;
        while(head!=NULL) 
        {
            head=head->next;
            n++;
        }
        while(n>=k)
        {
            int j=1; 
              curr=prev->next;
            nex=curr->next;
            while(j<k)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
                j++;
            } 
            n-=k;
            prev=curr;
        }
        return dummy->next;
    }
};

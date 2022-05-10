// T.C=O(N)
// S.C=O(N)




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head->next;
        head->next=NULL;
        while(temp!=NULL)
        {
            ListNode* p=temp->next;
            temp->next=head;
            head=temp;
            temp=p;
        }
        return head;
    }
};

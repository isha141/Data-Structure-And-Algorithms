class Solution { 
    ListNode*  reverse(ListNode* head)
    {
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
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=reverse(slow->next); 
        while(temp!=NULL)
        {
            if(head->val!=temp->val)
                return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};

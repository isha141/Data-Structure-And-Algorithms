
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) { 
        ListNode *head1=l1;
        ListNode *head2=l2;
        while(l1!=l2)
        {
            if(l1==NULL)
                l1=head2;
            else
            l1=l1->next;
            if(l2==NULL)
                l2=head1;
            else
             l2=l2->next;
        }
        return l1;
    }
};

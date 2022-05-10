// T.C=O(N/2)
// S.C=O(1)



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow && head && head->next)
        {
            slow=slow->next;
            head=head->next->next;
        }
        return slow;
    }
};

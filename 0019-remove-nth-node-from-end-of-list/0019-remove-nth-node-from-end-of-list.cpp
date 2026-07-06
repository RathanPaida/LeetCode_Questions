class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0, head);
        ListNode* dummy = temp;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
        return temp->next;
    }
};
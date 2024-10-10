class Solution {
public:
    ListNode* slow = NULL;
    ListNode* fast = NULL;

    ListNode* solve(ListNode* head) {
        slow = head;
        fast = head;
        
        if (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return nullptr;
    }

    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        return solve(head);
    }
};

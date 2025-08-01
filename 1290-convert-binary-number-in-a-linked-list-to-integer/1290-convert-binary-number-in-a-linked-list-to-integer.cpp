/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string bin = "";
        while(temp!=NULL){
            int val = temp->val;
            bin+=to_string(val);
            temp = temp->next;
        }

        int value = stoi(bin, nullptr, 2);

        return value;
    }
};
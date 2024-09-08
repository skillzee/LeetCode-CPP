/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* nextNode = temp->next;
        ListNode* prev = NULL;
        while(nextNode!=NULL){
            temp->val = nextNode->val;
            prev = temp;
            temp = temp->next;
            nextNode = nextNode->next;
        }
        prev->next = NULL;
    }
};
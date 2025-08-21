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
    int solve(string bin){
        int len = bin.length();
        int num=0;
        int p2 = 1;
        for(int i = len-1; i>=0; i--){
            if(bin[i] == '1'){
                num = num+p2;
            }
            p2 = p2*2;
        }
        return num;
    }

    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string bin = "";
        while(temp!=NULL){
            int val = temp->val;
            bin+=to_string(val);
            temp = temp->next;
        }

        int value = solve(bin);

        return value;
    }
};
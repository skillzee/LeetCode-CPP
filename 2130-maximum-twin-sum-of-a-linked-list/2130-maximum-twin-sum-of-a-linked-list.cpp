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
    int pairSum(ListNode* head) {
        
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();

        int sum = INT_MIN;
        for(int i = 0; i<(n/2); i++){
            int one = arr[i];
            int two = arr[n-1-i];

            sum = max(sum, one+two);

        }

        return sum;
    }
};
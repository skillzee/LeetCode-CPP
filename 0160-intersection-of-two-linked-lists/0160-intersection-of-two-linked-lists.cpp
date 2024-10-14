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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* temp = headA;
        ListNode* temp2 = headB;
        if(headA == headB){
            return headA;
        }
        while(temp!=NULL){
            sizeA++;
            temp = temp->next;
        }
        while(temp2!=NULL){
            sizeB++;
            temp2 = temp2->next;
        }
        temp = headA;
        temp2 = headB;
        if(sizeA>sizeB){
            int cnt = sizeA-sizeB;
            while(cnt){
                temp = temp->next;
                cnt--;
            }
        }else if(sizeB>sizeA){
            int cnt = sizeB-sizeA;
            while(cnt){
                temp2 = temp2->next;
                cnt--;
            }
        }

        while(temp!=NULL || temp2!=NULL){
            if(temp == temp2){
                return temp;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return NULL;
        
    }
};
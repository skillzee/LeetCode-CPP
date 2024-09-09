class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int row = m;
        int col = n;
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;

        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* temp = head;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right && temp != nullptr; i++) {
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            for (int i = top; i <= bottom && temp != nullptr; i++) {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left && temp != nullptr; i--) {
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top && temp != nullptr; i--) {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }
        return ans;
    }
};

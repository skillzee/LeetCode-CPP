class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i = 0 ; i<n; i++){
            while(!st.empty() and heights[st.top()]>heights[i]){
                int idx = st.top();
                st.pop();
                int width = st.empty()? i: i-st.top()-1;
                int newArea = heights[idx] * width;
                area = max(area, newArea);
            }
            st.push(i); 
            
        }

        while (!st.empty()) {
            int idx = st.top(); st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            int newArea = heights[idx] * width;
            area = max(area, newArea);
        }

        return area;
    }
};
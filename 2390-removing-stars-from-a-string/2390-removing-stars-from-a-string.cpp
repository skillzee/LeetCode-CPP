class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<int> st;
        string res = "";
        for(auto it: s){
            if(it!='*'){
                st.push(it);
            }
            if(it == '*' and !st.empty()){
                st.pop();
            }
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
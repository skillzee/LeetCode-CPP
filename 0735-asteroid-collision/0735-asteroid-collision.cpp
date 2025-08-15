class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &a: asteroids){
            // collison
            while(!st.empty() and a < 0 and st.top()>0){
                int sum = a+st.top();
                if(sum<0){
                    st.pop();
                }else if(sum >0){
                    a = 0;
                }else{
                    st.pop();
                    a = 0;
                }
            }

            if(a!=0){
                st.push(a);
            }
        }

        int s = st.size();
        vector<int> res(s);

        int i = s-1;

        while(!st.empty()){
            res[i] = st.top();
            st.pop();
            i--;
        }

        return res;
    }
};
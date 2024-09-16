class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int sizeCnt = 0;

        while(sizeCnt<s.size() and count<g.size()){
            if(g[count]<= s[sizeCnt]){
                count++;
            }else{

            sizeCnt++;
            }
        }

        return count;
    }
};
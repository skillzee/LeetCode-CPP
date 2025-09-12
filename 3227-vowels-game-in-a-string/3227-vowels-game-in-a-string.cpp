class Solution {
public:
    

    bool doesAliceWin(string s) {
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        
        for(auto it: s){
            char temp = tolower(it);
            if(st.find(temp) != st.end()){
                return true;
            }
        }

        return false;


    }
};
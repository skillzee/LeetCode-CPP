class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int n = chars.size();
        int count = 1;
        int i = 1;
        s+=chars[0];
        while(i<n){
            char ele = chars[i];
            if(ele == chars[i-1]){
                count++;
            }else{
                if(count!=1){
                    cout<<"count = "<<count<<endl;
                    s+=to_string(count);
                    count = 1;
                }
                s+=chars[i];
            }
            i++;
        }

        if(count!=1) {
            s+=to_string(count);
        }
        
        chars.clear();
        for(char c:s){
            chars.push_back(c);
        }
        return chars.size();

    }
};
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 0; i<n; i++){

            // A -> Upar wala
            int x1 = points[i][0];
            int y1 = points[i][1];


            // Finding B -> Neeche wala
            for(int j = 0; j<n; j++){
                if(i ==j) continue;

                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x1<=x2 and y1>=y2){

                    bool hasPointInside = false;
                    for(int k = 0; k<n; k++){
                        if(k == i || k == j){
                            continue;
                        }

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if(x3>=x1 and x3<=x2 and y3<=y1 and y3>=y2){
                            hasPointInside = true;
                            break;
                        }
                    }

                    if(!hasPointInside){
                        res++;
                    }

                }
            }

        }
        return res;
    }
};
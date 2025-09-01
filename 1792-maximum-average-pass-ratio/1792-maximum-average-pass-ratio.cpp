class Solution {
public:
     //double = maxDelta value and int -> index
    #define P pair<double, int>


    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P> pq; //max_heap -->{maxDelta, idx}

        // vector<double> PR(n);

        for(int i = 0; i<n; i++){
            // double ratio = (double)classes[i][0] / (double)classes[i][1];
            // PR[i] = ratio;
            double currentPR = (double)classes[i][0] / (double)classes[i][1];
            double newPR = (double)(classes[i][0]+1)/ (double)(classes[i][1]+1);
            double delta = newPR - currentPR;
            pq.push({delta, i});

        }

        while(extraStudents--){
            
            auto current = pq.top();
            pq.pop();

            double delta = current.first;
            int idx = current.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double currentPR = (double)classes[idx][0] / (double)classes[idx][1];
            double newPR = (double)(classes[idx][0]+1)/ (double)(classes[idx][1]+1);
            double deltaNew = newPR - currentPR;
            pq.push({deltaNew, idx});

            // vector<double> updatedPR(n);

            // for(int i = 0; i<n; i++){
            //     double newRatio=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            //     updatedPR[i] = newRatio;
            // }

            // int bestClassIdx = 0;
            // double bestDelta = 0.0;

            // for(int i = 0; i<n; i++){
            //     double delta = updatedPR[i] - PR[i];
            //     if(delta>bestDelta){
            //         bestDelta = delta;
            //         bestClassIdx = i;
            //     }
            // }

            // PR[bestClassIdx] += bestDelta;

            // classes[bestClassIdx][0]++;
            // classes[bestClassIdx][1]++;

        }


        double res = 0.0;


        for(int i = 0; i<n; i++){
            res+=(double)(classes[i][0]) / (double)(classes[i][1]);
        }

        return res/n;

    }
};
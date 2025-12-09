class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // get the minimum and maximum possible answers
        int min = *max_element(weights.begin(), weights.end());
        int max = (weights.size() * min * 2) / days + 1;

        // initialize weight answer var
        int weight = 0;

        // initialize pointer for binary search 
        int lp = min;
        int rp = max;
        int mp = 0;

        while(lp <= rp){
            mp = (lp + rp) / 2;

            int tDays = 0;
            long int currShip = 0;

            cout << mp << endl;

            for(int w : weights){
                if(currShip + w <= mp){
                    currShip += w;
                }
                else{
                    currShip = w;
                    tDays += 1;
                }
            }

            tDays += 1;
            

            if(tDays <= days){
                weight = mp;
                rp = mp - 1;
            }
            else{
                lp = mp + 1;
            }
        }

        return weight;
    }
};
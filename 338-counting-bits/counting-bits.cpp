class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n + 1);
        int powTwo = 1;
        int count = 0;
        for(int i = 0; i <= n; i++){
            if(i == 0){
                ones[i] == 0;
                continue;
            }
            else if(i == powTwo){
                powTwo *= 2;
                count = 0;
            }
            ones[i] = 1 + ones[count];
            count++;
        }

        return ones;
    }
};
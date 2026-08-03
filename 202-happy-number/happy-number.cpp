class Solution {
public:
    bool isHappy(int n) {
        std::set<int> seen;
        int happyNum = 0;

        while(!seen.contains(n)){
            seen.insert(n);
            happyNum = 0;

            while(n > 0){
                int lastDig = n % 10; 
                n = n / 10;
                happyNum += lastDig * lastDig;
            }

            if(happyNum == 1) return true;

            n = happyNum;
        }

        return false;
    }
};
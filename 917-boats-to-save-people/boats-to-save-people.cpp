class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int lp = 0;
        int rp = people.size() - 1; 
        int count = 0;

        std::sort(people.begin(), people.end());

        while(lp <= rp){
            if(people[lp] + people[rp] <= limit){
                lp++;
                rp--;
            }
            else{
                rp--;
            }
            count++;
        }

        return count;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // create a possible answer range
        // we know that k must be at minumum 1 banana
        // we also know that the maximum required would be k = max(piles)
        // because at minimum h == piles.length (will always find an answer) 
        // so we must at max eat one pile per hour to complete the bananas 
        int max = *max_element(piles.begin(), piles.end()); 
                
        // initialize k above the maximum possible answer 
        int k = max;

        // initialize pointers for searching the answer array using binary search
        int lp = 1;
        int rp = max;
        int mp = 0;

        // start at the middle of the array and test if we can eat all bananas
        // if we cannot eat all bananas then k must be larger than the middle
        // so we check the right side of the array by incrementing L to M + 1
        // if we can eat all the bananas then k must be less than or equal to the middle
        // so we save it as the current k then search the left side by decrementing R to M - 1
        // if we find a point where L is greater than R then we cannot find a smaller K
        // so we end the search as smaller values of k have already been searched
        while(lp <= rp){
            mp = (lp + rp) /2;

            // need to use a long int to prevent integer overflow
            long int hours = 0;

            for(int pile : piles){
                // always round up formula (divide pile by eating rate to get number of hours needed per pile)
                int result = (pile + mp - 1) / mp;
                hours += result;
            }

            if(hours <= h){
                k = mp;
                rp = mp - 1;
            }
            else{
                lp = mp + 1;
            }
            
        }

        return k;
    }
};
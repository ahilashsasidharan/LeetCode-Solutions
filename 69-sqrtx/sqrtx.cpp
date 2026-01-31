class Solution {
public:
    int mySqrt(int x) {
        int currSquare {0};

        // Return x for x < 2 (Binary search does not work for x = 1)

        if(x < 2) return x; 
        
        // Perform Binary Search on the Potential Answer Space
        // Which is inclusive between 0 and x/2 for x > 2

        int left = 0;
        int right = x / 2;
        int middle = right / 2;

        while(left <= right){
            
            // Cast middle * middle to long long guaranteed to be at least 64 bits.
            // Prevents overflow when you do an operation that goes above the size of an integer
            
            if(1LL * middle * middle > x){ 
                right = middle - 1;
            }
            else{
                currSquare = middle;
                left = middle + 1;
            }

            middle = (left + right) / 2;
        
        }

        return currSquare;
    }
};
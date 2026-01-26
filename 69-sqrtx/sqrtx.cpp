class Solution {
public:
    int mySqrt(int x) {
        int currSquare = 0;
        for(int i = 0; i <= x; i++){
        // Cast i * i to long long guaranteed to be at least 64 bits.
        // Prevents overflow when you do an operation that goes above the size of an integer
        if(1LL * i * i > x){ 
            break;
        }
        currSquare = i;
        }
        return currSquare;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorRes = 0;

        for(int n : nums){
            xorRes ^= n;
        }

        // This strategy to get the LSB for the xorRes result does not work
        // i.e. to get a bit that both unique elements differ at
        // it doesn't work since mod and division don't work as expected on neg numbers
        // to solve this we could use absolute values but that leaves an edge case that doesn't work
        // if you -2^31 this would overflow if you tried to get the absolute value of this
        // since it can't be represented as a positive number in a default 32 bit integer
        // due to the way two's complements works

        // int shift = 0, bit = 0;
        
        // while(bit == 0){
        //     bit = xorRes % 2;
        //     xorRes /= 2;
        //     if(bit == 0) shift++;
        // }

        // bit = bit << shift;

        // Need to convert to unsigned int for the edge case mentioned above
        // Since the value of -2^31 turned positive couldn't be held by an int (signed)
        // Based on compiler implementation this might cause issues when you have 2^31
        // being the LSB because it needs to be converted back to int which is not 
        // defined in the C++ standard 
        // now that the left side has an implicit conversion to unsigned int 
        // during the & between the two numbers

        int lsb = 0;

        lsb = xorRes & -(unsigned int)xorRes;

        vector<int> res = {0,0};

        for(int n : nums){
            if(n & lsb){
                res[0] ^= n;
            }
            else{
                res[1] ^= n;
            }
        }

        return res;
    }
};
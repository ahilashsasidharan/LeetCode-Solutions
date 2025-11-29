class Solution {
public:
    int getSum(int a, int b) {
                
        int xSum = a ^ b;
        int carry = a & b;

        while(carry != 0){
            int temp = xSum; 
            xSum = xSum ^ (carry << 1);
            carry = temp & (carry << 1);
        }
        return xSum;
    }
};
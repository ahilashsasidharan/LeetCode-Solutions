class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Algorithm:
        // Have an algorithm that tracks the current product and cutoff at each 0
        // Use it to track the product and negative numbers
        // Since neg products can turn postive if this ever happens need to handle it
        // Have a seperate variable then to keep track of positive products when they occur
        // Have the same idea cutoff at 0 & start tracking at a positive integer and cutoff at 0 or neg nums
        // Keep track of the highest value achieved 

        int posProd = 0;
        // int prod = 1;
        int negProd = 0;
        int highProd = nums[0];

        for(auto it = nums.begin(); it != nums.end(); it++){
            if(*it == 0){
                posProd = 0;
                negProd = 0;
            }

            if(*it < 0){
                if(posProd == 0){
                    if(negProd == 0) negProd = *it;
                    else{
                        posProd = *it * negProd;
                        negProd = *it;
                    }
                }
                else if(negProd == 0){
                    negProd = posProd * (*it);
                    posProd = 0;
                }
                else{
                    int temp = negProd;
                    negProd = posProd * (*it);
                    posProd = temp * (*it);
                }
            }

            if(*it > 0){
                negProd *= *it;
                if(posProd == 0){
                    posProd = *it;
                }
                else{
                    posProd *= *it;
                }
            }

            if(posProd != 0 && highProd < posProd){
                highProd = posProd;
            }
            else if(*it > highProd){
                highProd = *it;
            }

        }

        return highProd;

    }
};
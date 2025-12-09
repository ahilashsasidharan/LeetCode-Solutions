class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // CASES:
        // 1. you have a peak left & right of element < element  
        // 2. you don't have a peak either:
        // 2.1. both left & right are larger than element
        // 2.2. one of left or right is larger than element
        // since nums[i] != nums[i + 1] you won't have other cases

        // Based on these cases 
        // and the idea that neighbours outside of the array 
        // of an element are less than the element
        // we are guranteed a solution because
        // if there is no peak on an element we check
        // then one side has a greater element based on Case 2 above
        // because this the next element (beside the > element) 
        // will be increasing so no peak or be decreasing which means there is a peak 
        // this can continue but by the time we get to the end of the array
        // we are guranteed to have a decreasing element
        // so if every element increases we find an element at the end or
        // at some point to the element next to the increasing element we find a decreasing element
        // meaning we find a peak there are no cases where we don't find a peak
        
        // The above idea can be used to do a binary search as the side with an element larger than the left
        // will always have a peak element so we can choose that side of the middle element to search for one
        // shrinking the array by half each time as we search... the middle element that eliminate from the array
        // will always be smaller than the element next to it that we pick to move the lp/rp to 

        // set up binary search variables
        int lp = 0;
        int rp = nums.size() - 1;
        int mp = 0;

        while(lp <= rp /* doesn't matter we should always find an answer and return */){
            mp = (lp + rp) / 2;

            if((mp + 1 > rp or nums[mp] > nums[mp+1]) and (mp - 1 < lp or nums[mp] > nums[mp - 1])){
                return mp;
            }
            else if(mp + 1 <= rp and nums[mp + 1] > nums[mp]){
                lp = mp + 1;
            }
            else if(mp - 1 >= lp and nums[mp - 1] > nums[mp]){
                rp = mp - 1;
            }
        }

        return -1; // should never reach this
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // sort them from the end of the 
        int mp = m - 1;
        int np = n - 1;
        int p = m + n - 1;

        while(np >= 0){
            if(mp < 0 or nums1[mp] < nums2[np]){
                nums1[p] = nums2[np];
                np--;
            }
            else{
                nums1[p] = nums1[mp];
                mp--;
            }
            p--;
        }
    }
};
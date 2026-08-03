class Solution {
public:
    int trap(vector<int>& height) {
        // Past both the left and write bound no water can be held (i.e. consider it 0)
        // Because of this we can move the bounds for where water can be trapped in
        // Till when going inward from each bound you see a decreasing height 
        // Because if height keeps increasing water could in a sense pour out of the bounds
        // So those areas don't need to be considered

        int leftBound = 0;
        int rightBound = height.size() - 1;

        while(leftBound < height.size() - 1 && height[leftBound] <= height[leftBound + 1]){
            leftBound++;
        } 

        while(rightBound > 0 && height[rightBound] <= height[rightBound - 1]){
            rightBound--;
        }

        cout << "rb: " << rightBound << endl;
        cout << "lb: " << leftBound << endl; 

        // Scan between the calculate bounds to find pockets of water

        int lp = leftBound;
        int rp = leftBound;
        int maxL = 0;
        int water = 0;
        
        while(rp < rightBound && lp < rightBound){
            if(height[lp] <= height[lp + 1]){
                lp++;
            }
            else{
                if(rp <= lp) rp = lp + 1;

                int maxR = 0;

                while(rp < rightBound){
                    if(height[rp] > maxR) maxR = height[rp];
                    if(height[rp] >= height[lp]) break;
                    rp++;
                }

                if(rp == rightBound){
                    while(rp > 0 && height[rp] < maxR) rp--;
                }

                maxL = height[lp];
                lp++;

                cout << maxL << endl;
                cout << height[rp] << endl;
                cout << "RP: " << rp << endl;

                while(lp < rp){
                    if(height[lp] > std::min(maxL, height[rp])){
                        lp++;
                        continue;
                    }
                    cout << water << endl;
                    cout << "LP: " << lp << endl;
                    cout << "RP: " << rp << endl;
                    water += std::min(maxL, height[rp]) - height[lp];
                    lp++;
                }
            }
        }

        return water;
    }
};
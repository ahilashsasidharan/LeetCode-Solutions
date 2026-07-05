class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // create result vector
        vector<int> res;

        // hash map to count frequency numbers
        unordered_map<int, int> freqs;

        // buckets to hold numbers of certain numbers of frequencies (0 to n frequencies possible so need n + 1 buckets)
        vector<vector<int>> bucket(nums.size() + 1);

        // count occurences using the hash maps
        for(int n : nums){
            freqs[n]++;
        }

        // loop through hash map keys and place them in the correct bucket
        for(const auto& [key, value] : freqs){
            bucket[value].push_back(key);
        }

        cout << "got here" << endl;

        // pull from the largest bucket for k number of elements
        for(int i = nums.size(); (i >= 0) && res.size() < k; i--){
            for(int j = 0; (j < bucket[i].size()) && res.size() < k; j++){
                res.push_back(bucket[i][j]);
            }
        }        

        return res;
    }
};
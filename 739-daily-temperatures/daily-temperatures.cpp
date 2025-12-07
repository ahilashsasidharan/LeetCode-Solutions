class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // index, value
        stack<int> prevs;
        vector<int> result(temperatures.size(), 0);
        int prev = temperatures[0];
        prevs.push(0);

        for(int i = 1; i < temperatures.size(); i++){
            if(prev < temperatures[i]){
                while(!prevs.empty() and temperatures[prevs.top()] < temperatures[i]){
                    int ind = prevs.top();
                    prevs.pop();
                    result[ind] = i - ind;
                }
            }
            prevs.push(i);
            prev = temperatures[i];
        }

        return result;

    }
};
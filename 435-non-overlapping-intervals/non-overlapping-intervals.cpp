class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
          [](const vector<int>& a, const vector<int>& b) {
              return a[0] < b[0];
          });

          int removals = 0;
          int end = intervals[0][1];

          for(int i = 1; i < intervals.size(); i++){
            if(end > intervals[i][0]){
                removals++;
                end = std::min(end, intervals[i][1]);
            }
            else{
                end = intervals[i][1];
            }
          }

          return removals;
    }
};
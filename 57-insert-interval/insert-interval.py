class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        # Cases:
        # 1. the end of the interval before the start of the interval  
        # 2. the start of the interval after the end of the interval
        # 3. the interval is between other interval without overlap 
        # 4. the interval overlaps with one or more intervals

        mergeintervals = []

        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                mergeintervals.append(newInterval)
                return mergeintervals + intervals[i:] 
            elif newInterval[0] > intervals[i][1]:
                mergeintervals.append(intervals[i])
            else:
                newInterval = [min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])]

        mergeintervals.append(newInterval) 

        return mergeintervals   

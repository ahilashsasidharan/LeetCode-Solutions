class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        mergedintervals = []

        # Sort the list by first element simplifies the problem for the following reasons:
        # 1. Removes the case where there is no overlap due to second interval being before the first since start
        #    of the interval of the second will always be equal or larger then the first due to sorting
        # 2. Makes it so if you discover no overlap for an interval then all future intervals will not have overlap
        #    in the list since the start will be after the interval due to sorting
        intervals.sort(key=lambda x: x[0])

        prev = intervals[0]
        curr = 1

        while curr < len(intervals):
            if intervals[curr][0] <= prev[1]:
                prev = [prev[0], max(prev[1], intervals[curr][1])]
                curr += 1
            else:
                mergedintervals.append(prev)
                prev = intervals[curr]
                curr += 1

        mergedintervals.append(prev)

        return mergedintervals


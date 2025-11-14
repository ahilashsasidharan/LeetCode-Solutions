class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        a = 0 
        b = 1
        while a < len(intervals) - 1:
            # case 1: intervals a & b do not overlap
            if intervals[a][1] < intervals[b][0] or intervals[b][1] < intervals[a][0]:
                b += 1 
            # case 2: a overlaps b where a starts before b
            elif intervals[a][0] < intervals[b][0] and intervals[a][1] < intervals[b][1]:
                newInt = [intervals[a][0], intervals[b][1]]
                intervals[a] = newInt
                intervals.pop(b) 
                b = a + 1 # removing index b so do not increment
            # case 3: b overlap a where b starts before a
            elif intervals[b][0] < intervals[a][0] and intervals[b][1] < intervals[a][1]:
                newInt = [intervals[b][0], intervals[a][1]]
                intervals[a] = newInt
                intervals.pop(b) 
                b = a + 1 # removing index b so do not increment
            # case 4: a engulfs b
            elif intervals[a][0] <= intervals[b][0] and intervals[a][1] >= intervals[b][1]:
                intervals.pop(b) 
                # if a engulfs b there will be no new overlap for previously check intervals
                b = b # removing index b so do not increment
            # case 5 b engulfs a
            else:
                newInt = intervals[b]
                intervals[a] = newInt
                intervals.pop(b) 
                b = a + 1 # removing index b so do not increment

            if b >= len(intervals):
                a += 1
                b = a + 1

        return intervals
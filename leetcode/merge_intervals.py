class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        for i in sorted(intervals, key=lambda x: x[0]):    # 시작 시간을 기준으로 정렬
            if merged and i[0] <= merged[-1][1]:           # 겹치는가?
                merged[-1][1] = max(merged[-1][1], i[1])
            else:
                merged += i,

        return merged
        

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        arr = []
        for x in points:
            arr.append(x[0])
        arr.sort()
        ans = 0
        for i in range (len(arr)-1):
            ans = max(ans, arr[i+1]-arr[i])
        return ans
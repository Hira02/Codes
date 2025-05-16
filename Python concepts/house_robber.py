from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [0] * (n+1)
        arr[0] = nums[0]
        if n == 0:
            return 0
        if n == 1:
            return arr[0]
        arr[1] = max(arr[0], nums[1])
        if n == 2:
            return arr[1]
        for i in range(2, n):
            arr[i] = max(arr[i-1], nums[i]+arr[i-2])
        
        return max(arr[n-1], arr[n-2])
        
if __name__ == "__main__":
    nums = [2,7,9,3,1]
    s = Solution()
    print(s.rob(nums))
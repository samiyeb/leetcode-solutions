from typing import List


class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res, cur = nums[0], nums[0]

        for i in range(1, len(nums)):
            cur = cur + nums[i] if nums[i-1] < nums[i] else nums[i]
            res = max(res, cur)
        
        return res
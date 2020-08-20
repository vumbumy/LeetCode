from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ret = []

        sum = 0
        for n in nums:
            sum += n

            ret.append(sum)

        return ret


s = Solution()
nums = [1,2,3,4]

print(s.runningSum(nums))
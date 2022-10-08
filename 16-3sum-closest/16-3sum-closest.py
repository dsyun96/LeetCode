# 호두마루님 코드

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = float("inf")

        for i in range(len(nums)-2):
            l,r = i+1, len(nums) - 1
            
            while l < r and (target - closest):
                v = nums[i] + nums[l] + nums[r]
                closest = closest if (abs(target - closest) < abs(target - v)) else v
                

                if v > target: r-= 1
                else: l += 1
        return closest


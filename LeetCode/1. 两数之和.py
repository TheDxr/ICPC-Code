class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_table = dict()
        for i in range(0, len(nums)):
            nums_table[nums[i]] = i
        for i in range(0, len(nums)):
            if ((target - nums[i]) in nums_table) and i != nums_table.get(target - nums[i]):
                return [i, nums_table.get(target - nums[i])]
        return []

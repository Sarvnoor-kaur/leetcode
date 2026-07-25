/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    nums=[...new Set(nums)];
    nums.sort((a,b)=>b-a);
    return nums.length>=3?nums[2]:nums[0];
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {

    let n=nums.length;
    if (n == 1)
    return 0;
    for(let i=0;i<nums.length;i++){
        let left=(i===0 || nums[i]>nums[i-1]);
        let right=(i===nums.length-1 || nums[i]>nums[i+1]);
        if(left && right){
            return i;
        }
    }
    return -1;
};
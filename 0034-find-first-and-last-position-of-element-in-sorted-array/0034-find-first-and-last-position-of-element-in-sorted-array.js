/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let an=[-1,-1];
    for(let i=0;i<nums.length;i++){
        if(nums[i]==target){
            an[0]=i;
            break;
        }
    }
    if(an[0]==-1){
        return an;
    }
    for(let i=nums.length;i>=0;i--){
        if(nums[i]==target){
            an[1]=i;
            break;
        }
    }
    return an;
};
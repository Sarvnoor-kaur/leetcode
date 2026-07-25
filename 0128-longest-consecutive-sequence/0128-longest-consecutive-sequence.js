/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
     if(nums.length===0){
            return 0;
        }
        nums.sort((a,b)=>a-b);

        let maxi=1;
        let len=1;
        for(let i=1;i<nums.length;i++){
            if(nums[i]===nums[i-1]+1){
                len++;
                maxi=Math.max(len,maxi);
            }else if(nums[i]!==nums[i-1]){
                len=1;
            }
        }
        return maxi;
};
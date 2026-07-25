/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let re=[];
    let mp=new Map();
    for(let i=0;i<nums.length;i++){
        mp.set(nums[i],(mp.get(nums[i])||0)+1);
    }
    for(let [k,v] of mp){
        if(v==2){
            re.push(k);
        }
    }
    return re;
};
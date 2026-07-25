/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let et=new Set(nums1);
    let two=new Set();
    for(let i=0;i<nums2.length;i++){
        if(et.has(nums2[i])){
            two.add(nums2[i]);
        }
    } 
    return [...two];
};
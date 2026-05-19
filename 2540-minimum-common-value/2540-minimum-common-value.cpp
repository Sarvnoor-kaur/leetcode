class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // int mini=-1;
        // for(int i=0;i<nums1.size();i++){
        //      if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
        //         mini=nums1[i];
        //         break;
        //     }
        // }
        // return mini;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return -1;
    }
};
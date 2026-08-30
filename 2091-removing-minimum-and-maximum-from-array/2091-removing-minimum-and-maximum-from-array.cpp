class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        //s1
        // int mminf=0,mminb=0;
        // int mmaxf=0,mmaxb=0;
        // bool fominf=fomaxf=fominb=fomaxb=false;
        // for(int i=0;i<nums.size();i++){
        //     mminf++;
        //     mmaxf++;
        //     if(nums[i]==mini && fominf==false){
        //         fominf=true;
        //     }
        //      if(nums[i]==maxi && fomaxf==false){
        //         fomaxf=true;
        //     }
        // }

        // //s-2
        // for(int i=n-1;i>0;i--){
        //     mminb++;
        //     mmaxb++;
        //     if(nums[i]==mini && fominb==false){
        //         fominb=true;
        //     }
        //      if(nums[i]==maxi && fomaxb==false){
        //         fomaxb=true;
        //     }
        // }

        // //s-3

        // for(int)
      
   
        // int n = nums.size();

        // int mini = *min_element(nums.begin(), nums.end());
        // int maxi = *max_element(nums.begin(), nums.end());

        int minPos=0, maxPos = 0;

        // Find positions of min and max
        for (int i = 0; i < n; i++) {
            if (nums[i] == mini)
                minPos = i;

            if (nums[i] == maxi)
                maxPos = i;
        }

        // From front
        int minFront = minPos + 1;
        int maxFront = maxPos + 1;

        // From back
        int minBack = n - minPos;
        int maxBack = n - maxPos;

        // Both from front
        int s1 = max(minFront, maxFront);

        // Both from back
        int s2 = max(minBack, maxBack);

        // Min from front, max from back
        int s3 = minFront + maxBack;

        // Max from front, min from back
        int s4 = maxFront + minBack;

        return min({s1, s2, s3, s4});
    

    }
};
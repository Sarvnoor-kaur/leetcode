class Solution {
public:
    int count(vector<int>&num,int mid){
        int n=num.size();
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            while(num[i]-num[l]>mid){
                l++;
            }
            cnt+=i-l;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums.back()-nums.front();
        while(l<h){
            int mid=l+(h-l)/2;
            int cnt=count(nums,mid);
            if(cnt>=k){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
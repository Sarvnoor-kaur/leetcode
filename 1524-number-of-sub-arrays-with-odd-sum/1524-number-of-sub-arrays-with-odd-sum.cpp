class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long e=1e9+7;
        long long odd=0;
        long long even=1;
        long long c=0;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                c+=odd;
                even++;
            }else{
                c+=even;
                odd++;
            }
            c%=e;
        }
        return c;
    }
};
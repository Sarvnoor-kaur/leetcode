class Solution {
public:
    int maximumGap(string skill, string station) {

        int n=skill.size();
        int m=station.size();
        int i=0,j=0;
        vector<int>left(n);
        while(i<n && j<m){
            if(skill[i]==station[j]){
                left[i]=j;
                i++;
                j++;

            }else{
                j++;
            }
        }
        vector<int>right(n);
        i=n-1,j=m-1;
        while(i>=0 && j>=0){
            if(skill[i]==station[j]){
                right[i]=j;
                i--;
                j--;
            }else{
                j--;
            }
        }
        int maxi=0;
        for(int k=1;k<n;k++){
            maxi=max(maxi,right[k]-left[k-1]);
        }
        return maxi;
    }
};
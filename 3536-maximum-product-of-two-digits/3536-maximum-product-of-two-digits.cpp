class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n>0){
            int dig=n%10;
            v.push_back(dig);
            n/=10;
        }
        sort(v.begin(),v.end());
        int l=v.size()-1;
        int lt=v.size()-2;
        return v[l]*v[lt];
    }
};
class Solution {
public:
    static bool custom(string&a,string&b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>ti;
        for(int i=0;i<nums.size();i++){
            ti.push_back(to_string(nums[i]));
        }
        sort(ti.begin(),ti.end(),custom);
        if(ti[0]=="0"){
            return "0";
        }
        string re="";
        for(int i=0;i<ti.size();i++){
            re+=ti[i];
        }
        return re;
    }
    
};
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>re;
        if(num%3!=0){
            return re;
        }
        long long nu=num/3;
        
        re.push_back(nu-1);
        re.push_back(nu);
        re.push_back(nu+1);
        return re;
    }
};
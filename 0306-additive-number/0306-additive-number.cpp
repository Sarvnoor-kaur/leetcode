class Solution {
public:
    string stringadd(string x,string y){
        string res;
        int i=x.size()-1,j=y.size()-1,carry=0;
        while(i>=0 ||j>=0||carry){
            int sum=carry;
            if(i>=0) sum+=x[i--]-'0';
            if(j>=0) sum+=y[j--]-'0';
            res.push_back(sum%10+'0');
            carry=sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    bool isvalid(string a ,string b,string rest){
        while(!rest.empty()){
            string sum=stringadd(a,b);
            if(rest.find(sum)!=0) return false;
            rest=rest.substr(sum.size());
            a=b;
            b=sum;
        }
        return true;
    }
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<=n/2;i++){
            for(int j=i+1;j<n;j++){
                string a =num.substr(0,i);
                string b=num.substr(i,j-i);
                if((a.size()>1 && a[0]=='0')|| (b.size()>1 && b[0]=='0')) continue;
                if(isvalid(a,b,num.substr(j))) return true;
            }
        }
        return false;
    }

};
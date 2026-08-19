class Solution {
public:
    int minMovesToMakePalindrome(string m) {
        int mo=0;
        int i=0,j=m.size()-1;
        while(i<=j){
            if(m[i]==m[j]){
                i++;
                j--;
                
            }else{
                int k=j;
                while(k>=i && m[i]!=m[k]){
                    k--;
                }

                if(i==k){
                    swap(m[k],m[k+1]);
                    mo++;
                    
                }else{
                    while(k<j){
                        swap(m[k],m[k+1]);
                        mo++;
                        k++;
                    }
                }
                
                // i++;
                // j--;
            }
        }
        return mo;
    }
};
class Solution {
public:
    vector<string> fullJustify(vector<string>& word, int maxWidth) {
        
        int i=0;
        vector<string>wo;
        while(i<word.size()){
            int j=i;
            int lenw=0;
            while(j<word.size() && lenw+word[j].length()+(j-i)<=maxWidth){
                lenw+=word[j].length();
                j++;
            }

            string line = "";
            int noofword=j-i;
            if(j==word.size()|| noofword == 1){

                for(int k=i;k<j;k++){
                    line+=word[k];
                    if(k<j-1){
                        line+=" ";
                    }
                }
                while(line.length()<maxWidth){
                    line+=" ";
                }

            }else{
                int noofgaps=noofword-1;
                int rem=maxWidth-lenw;
                int each=rem/noofgaps;
                int extra=rem%noofgaps;
                for(int k=i;k<j;k++){
                    line+=word[k];
                    if(k<j-1){
                        for(int a=0;a<each;a++){
                            line+=" ";
                        }
                        if(extra>0){
                            line+=" ";
                            extra--;
                        }
                    }
                }
            }
            wo.push_back(line);
            i=j;
        }
        return wo;
    }
};
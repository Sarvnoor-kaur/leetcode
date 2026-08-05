class Solution {
    public String multiply(String num1, String num2) {
        
        int n=num1.length();
        int m=num2.length();
        int [] fi=new int[n+m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int dig1=num1.charAt(i)-'0';
                int dig2=num2.charAt(j)-'0';
                int mu=dig1*dig2;
                int po1=i+j;
                int po2=i+j+1;
                int um=mu+fi[po2];
                // po2=um%10;
                // po1=um/10;
                fi[po1]+=um/10;
                fi[po2]=um%10;
            }
        }
        StringBuilder re=new StringBuilder();
        for(int i=0;i<fi.length;i++){
            if(!(re.length()==0 && fi[i]==0)){
                re.append((char)(fi[i]+'0'));
            }
        }
        return re.length()==0?"0":re.toString();
    }
}
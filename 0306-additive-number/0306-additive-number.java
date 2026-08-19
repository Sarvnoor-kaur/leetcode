class Solution {
    String add(String a,String b){
       StringBuilder re = new StringBuilder();

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {

            int sum = carry;

            if (i >= 0) {
                sum += a.charAt(i--) - '0';
            }

            if (j >= 0) {
                sum += b.charAt(j--) - '0';
            }

            re.append((char)(sum % 10 + '0'));

            carry = sum / 10;
        }

        return re.reverse().toString();
    }
    boolean valid(String a,String b,String ret){
        while(!ret.isEmpty()){
            String um= add(a,b);
            if (!ret.startsWith(um)) {
                return false;
            }
            ret=ret.substring(um.length());
            a=b;
            b=um;
        }
        return true;
    }
    public boolean isAdditiveNumber(String num) {
        int n=num.length();
        for(int i=1;i<=n/2;i++){
            for(int j=i+1;j<n;j++){
                String a=num.substring(0,i);
                String b=num.substring(i,j);
                if((a.length()>1 && a.charAt(0)=='0')||(b.length()>1 && b.charAt(0)=='0')){
                    continue;
                }
                if(valid(a,b,num.substring(j))) return true;
            }
        }
        return false;
    }
}
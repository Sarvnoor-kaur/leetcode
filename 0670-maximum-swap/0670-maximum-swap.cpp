class Solution {
public:
    int maximumSwap(int num) {
    string numstr=to_string(num);
    auto maxdIt=max_element(numstr.begin(),numstr.end());
    int maxdi=distance(numstr.begin(),maxdIt);
    swap(numstr[0],numstr[maxdi]);
    return stoi(numstr);


        // string numstr=to_string(num);
        // int n=numstr.size();
        // int maxIdx=n-1;
        // int leftIdx=-1,rightIdx=-1;
        // for(int i=n-2;i>=0;--i){
        //     if(numstr[i]>numstr[maxIdx]){
        //         maxIdx=i;
        //     }else if(numstr[i]<numstr[maxIdx]){
        //         leftIdx=i;
        //         rightIdx=maxIdx;

        //     }
        // }
        // if(leftIdx!=-1){
        //     swap(numstr[leftIdx],numstr[rightIdx]);
        // }
        // return stoi(numstr);


        
    }
};
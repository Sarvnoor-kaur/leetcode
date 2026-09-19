class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<double,pair<int,int>>>item;
        for(int i=0;i<boxTypes.size();i++){
            int val=boxTypes[i][0];
            int wt=boxTypes[i][1];
            // double ratio=(double)(val*wt)/wt;
            double ratio = wt;

            item.push_back({ratio,{val,wt}});
        }
        sort(item.rbegin(), item.rend());
        int an=0;
        for(auto &i:item){
            double ra=i.first;
            int va=i.second.first;
            int wt=i.second.second;
            if(truckSize>=va){
                an+=va*wt;
                truckSize-=va;
            }else{
                an+=truckSize*wt;
                break;
            }
        }
        return an;
    }
};









// class Solution {
// public:
//     int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
//         vector<pair<double, pair<int, int>>> item;

//         for (int i = 0; i < boxTypes.size(); i++) {
//             int val = boxTypes[i][0]; // number of boxes
//             int wt = boxTypes[i][1];  // units per box

//             double ratio = wt;

//             item.push_back({ratio, {val, wt}});
//         }

//         sort(item.rbegin(), item.rend());

//         int an = 0;

//         for (auto &i : item) {
//             double ra = i.first;
//             int va = i.second.first; // number of boxes
//             int wt = i.second.second; // units per box

//             if (truckSize >= va) {
//                 an += va * wt;
//                 truckSize -= va;
//             }
//             else {
//                 an += truckSize * wt;
//                 truckSize = 0;
//                 break;
//             }
//         }

//         return an;
//     }
// };
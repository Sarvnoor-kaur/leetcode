class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int>avserver;
        vector<int>totalserver(k,0);
        for(int i=0;i<k;i++){
            avserver.insert(i);
        }
        priority_queue<pair<long long,int>, 
        vector<pair<long long,int>>, greater<pair<long long,int>>> ocserver;
        for(int i=0;i<arrival.size();i++){
            long long start=arrival[i];
            long long end=start+load[i];
            while(!ocserver.empty() && ocserver.top().first<=start){
                avserver.insert(ocserver.top().second);
                ocserver.pop();
            }
            if (avserver.empty()) continue; 
            int server=i%k;
        //    bool assigned=false;
        //     while(server<k){
        //         if(avserver.find(server)!=avserver.end()){
        //             ocserver.push({end,server});
        //             totalserver[server]++;
        //             avserver.erase(server);
        //             assigned=true;
        //             break;
        //         }
        //     server++;;
        //     }
        //     if(!assigned){
        //         server=0;
        //         while(server<i%k){
        //             if(avserver.find(server)!=avserver.end()){
        //                 ocserver.push({end,server});
        //                 totalserver[server]++;
        //                 avserver.erase(server);
        //                 break;
        //             }
        //             server++;
        //         }
        //     }

            auto it = avserver.lower_bound(server);
            if(it==avserver.end()) it=avserver.begin();
            int chosen=*it;
            ocserver.push({end,chosen});
            totalserver[chosen]++;
            avserver.erase(it);
        
        }
        int maxi=*max_element(totalserver.begin(),totalserver.end());
        vector<int>ans;
        for(int i=0;i<totalserver.size();i++){

            if(totalserver[i]==maxi){
                ans.push_back(i);
            }
        }
        return ans;

    }
};
int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int,int>mp;
        for(int i=0;i<lines.size();i++){
            int a=lines[i][0],b=lines[i][1];
            mp[a]++;
            mp[b+1]--;
        }
        int ans=INT_MIN,presum=0;
        for(auto i:mp){
            presum+=i.second;
            ans=max(ans,presum);
        }
        return ans;
    }

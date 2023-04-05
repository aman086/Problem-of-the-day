#define fi first
#define se second
class Solution {
  public:
    int countSpecialNumbers(int n, vector<int>&a) {
      int mx=0;
      for(auto &it:a)
          mx=max(mx,it);
      vector<int>vis(mx+1),mp(mx+1);
      map<int,int>freq;
      for(auto &it:a){mp[it]++;freq[it]++;}
     int cnt=0;
     for(auto &it:freq){
         if(it.se>1){
             cnt+=it.se;
             vis[it.fi]=1;
         }
     }
   
     for(auto &it:freq){
         for(int j=2*it.fi;j<=mx;j+=it.fi){
             if(vis[j])continue;
             else{
                 if(mp[j]){vis[j]=1;
                 cnt+=mp[j];}
             }
         }
     }
     return cnt;
    }
};

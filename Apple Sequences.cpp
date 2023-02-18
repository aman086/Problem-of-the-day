class Solution{   
public:
    int appleSequences(int n, int m, string s){
        int i = 0, j = 0, cnt = 0, ans = 0;
        while(j<=n)
        {
            if(cnt > m) cnt -= s[i]=='O', ++i;
            else 
            {
                ans = max(ans, j-i);
                cnt += j<n?s[j]=='O':0;
                ++j;
            }
        }
        return ans;
    }
};

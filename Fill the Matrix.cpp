class Solution{   
public:
    int dist(int i, int j, int x, int y) {
        return abs(i-x)+abs(j-y);
    }
    
    int minIteration(int n, int m, int x, int y){
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                ans = max(ans,dist(i,j,x,y));
            }
        }
        
        return ans;
    }
};

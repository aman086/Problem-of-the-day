vector<int> getDistinctDifference(int n, vector<int> &arr) {
        vector<int> v1(n), v2(n), ans(n);
        set<int> s1, s2;
        
        for(int i=0; i<n; i++) {
            int sz1 = s1.size(), sz2 = s2.size();;
            s1.insert(arr[i]);
            if(sz1==s1.size()) v1[i] = v1[i-1];
            else v1[i] = (i==0) ? 1 : v1[i-1]+1;
            
            s2.insert(arr[n-1-i]);
            if(sz2==s2.size()) v2[n-1-i] = v2[n-i];
            else v2[n-1-i] = (i==0) ? 1 : v2[n-i]+1;
        }
        
        for(int i=0; i<n; i++) {
            int a = 0, b=0;
            a = (i==0) ? 0 : v1[i-1];
            b = (i==n-1) ? 0 : v2[i+1];
            ans[i] =  a-b;
        }
        return ans;    
    }

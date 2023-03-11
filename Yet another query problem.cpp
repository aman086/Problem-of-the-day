vector<int> solveQueries(int n, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                }
            }
            v.push_back(count);
        }
        vector<int >ans;
        int m=Q.size();
        for(int i=0;i<m;i++)
        {   int cou=0;
            for(int j=Q[i][0];j<=Q[i][1];j++)
            {
                if(v[j]==Q[i][2])
                {
                    cou++;
                }
            }
            ans.push_back(cou);
        }
        return ans;
    }

int dominantPairs(int n,vector<int> &arr)
    {
        // Code here
        vector<int>v1,v2;
        
        for(int i=0; i<n/2; i++)
        {
            v1.push_back(arr[i]);
        }
        for(int i=n/2; i<n; i++)
        {
            v2.push_back(arr[i]*5);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int i=0, j=0, ans=0;
        
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]>=v2[j])
            {
                ans+= ((n/2)-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }  

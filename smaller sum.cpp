vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int>arr2(arr);
        sort(arr2.begin(),arr2.end());
        vector<long long>pre(n);
        pre[0]=arr2[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+arr2[i];
        }
        vector<long long>ans(n);
        for(int i=0;i<n;i++){
            int ind=lower_bound(arr2.begin(),arr2.end(),arr[i])-arr2.begin();
            if(ind<n && ind>0 && arr2[ind]==arr[i]){
                ans[i]=pre[ind-1];
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }

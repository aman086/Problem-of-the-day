int solve(int a, int b, int c) 
    {
        vector<int> x = {a, b, c};
        sort(x.begin(), x.end());
        
        if(x[2]<= 2*(x[0]+x[1]-1)+4 )
        {
            return a+b+c;
        }
        else
        {
            return -1;
        }
    }

int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>>st;
        st.push({color[0],radius[0]});
        int i=1;
        while(i<color.size())
        {
            if(st.size()>0 && st.top().first==color[i] && st.top().second==radius[i])
            {
                st.pop();
            }
            else{
                st.push({color[i],radius[i]});
            }
            i++;
        }
        return st.size();
    }

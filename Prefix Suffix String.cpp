struct Node
    {
        char c;
        Node* adj[26] = {NULL};
        Node(char ch)
        {
            c = ch;
        }
    };
    
    void insert_st(Node* head, string& s)
    {
        int n = s.length();
        Node* temp = head;
        int i = 0;
        while(i < n)
        {
            if(temp->adj[s[i] - 'a'] == NULL)
                temp->adj[s[i] - 'a'] = new Node(s[i]);
                
            temp = temp->adj[s[i] - 'a'];
            i++;
        }
        return;
    }
    
    bool trav(Node* head, string& s)
    {
        int n = s.length();
        int i = 0;
        Node* temp = head;
        while(i < n)
        {
            if(temp->adj[s[i] - 'a'] == NULL)
                return false;
                
            temp = temp->adj[s[i] - 'a'];
            i++;
        }
        return true;
    }

    int prefixSuffixString(vector<string> &s1,vector<string>& s2){
        Node* head = new Node('0');
        Node* tail = new Node('0');
        for(int i = 0;i<s1.size();i++)
            insert_st(head, s1[i]);
        for(int i = 0;i<s1.size();i++)
        {
            string temp = s1[i];
            reverse(temp.begin(), temp.end());
            insert_st(head, s1[i]);
            insert_st(tail, temp);
        }
        int ans = 0;
        for(int i = 0;i<s2.size();i++)
        {
            string temp = s2[i];
            reverse(temp.begin(), temp.end());
            if(trav(head, s2[i]) || trav(tail, temp))
                ans++;
        }
        return ans;
    }

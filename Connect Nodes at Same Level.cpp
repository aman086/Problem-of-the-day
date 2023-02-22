void connect(Node *root) {
        queue<pair<Node*,int>>q;
        pair<Node*,int>prev = {NULL, -1};
        q.push({root,0});
        while (!q.empty()) {
            Node * a = q.front().first;
            int lev = q.front().second;
            q.pop();
            if (prev.second==lev) {
                prev.first->nextRight = a;
            }
            prev = {a,lev};
            if (a->left) q.push({a->left, lev+1});
            if (a->right) q.push({a->right, lev+1});
        }
    } 

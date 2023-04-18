int mini;
    
    bool checkBST(Node *root, long long minVal, long long maxVal) {
        if(!root) return true;
        
        if(root->data <= minVal or root->data >= maxVal)
            return false;
        
        return checkBST(root->left, minVal, root->data) and checkBST(root->right, root->data, maxVal);
    }
    
    int sum(Node *root, int &count) {
        if(!root) return 0;
        count++;
        return root->data + sum(root->left, count) + sum(root->right, count);
    }
    
    void solve(Node *root, int k) {
        if(!root) return;
        
        if(!root->left and !root->right) {
            if(root->data == k) {
                mini = 1;
                return;
            }
        }
        
        if(checkBST(root, INT_MIN, INT_MAX)) {
            int count = 0;
            int s = sum(root, count);
            if(s == k)
                mini = min(mini, count);
        }
        
        solve(root->left, k);
        solve(root->right, k);
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        mini = INT_MAX;
        solve(root, target);
        return mini == INT_MAX ? -1 : mini;
    }

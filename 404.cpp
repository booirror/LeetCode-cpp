  
    int sumOfLeftLeaves(TreeNode* root) {  
        if (root == nullptr) return 0;  
        if (root->left) {  
            if (root->left->left == nullptr && root->left->right == nullptr) {  
                return root->left->val + sumOfLeftLeaves(root->right);  
            } else {  
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);  
            }  
        } else {  
            return sumOfLeftLeaves(root->right);  
        }  
    }  

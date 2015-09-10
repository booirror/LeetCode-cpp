class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    vector<int> vi;


    vector<TreeNode*> vtn;
  if (root == NULL) return vi;
  vtn.push_back(root);
  while (vtn.size() > 0) {
  TreeNode * node= vtn.back();
  vi.push_back(node->val);
  vtn = getNextDeep(vtn);
  }
  return vi;
    } 


    vector<TreeNode*> getNextDeep(vector<TreeNode*>& vec) {
    std::vector<TreeNode*> v;
    for (int i = 0; i < vec.size(); i++) {
    if (vec[i]->left) {
    v.push_back(vec[i]->left);
    }
    if (vec[i]->right) {
    v.push_back(vec[i]->right);
    }
    }
    return v;
    }
};
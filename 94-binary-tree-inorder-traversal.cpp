#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> val;
	vector<TreeNode*> record;
	vector<TreeNode*> traverse;
	if (root == NULL) return val;
	record.push_back(root);

	while (record.size() > 0)
	{
		TreeNode *node = record.back();
		if ((node->left && std::find(traverse.begin(), traverse.end(), node->left) != traverse.end()) || node->left == NULL) {
			val.push_back(node->val);
			record.pop_back();
			traverse.push_back(node);
			if (node->right) {
				record.push_back(node->right);
			}
		}
		else if (node->left)
		{
			record.push_back(node->left);
			continue;
		}
	}
	return val;
}
void inorderTraversalTest()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);

	node1->right = node2;
	node2->left = node3;

	vector<int> v = inorderTraversal(node1);

	for (int i : v)
	{
		cout << i << endl;
	}
}
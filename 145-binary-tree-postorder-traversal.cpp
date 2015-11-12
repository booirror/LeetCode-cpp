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
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> val;
	vector<TreeNode*> record;
	vector<TreeNode*> traverse;
	if (root == NULL) return val;
	record.push_back(root);

	while (record.size() > 0)
	{
		TreeNode *node = record.back();
		if ((node->left && std::find(traverse.begin(), traverse.end(), node->left) != traverse.end()) || node->left == NULL)
		{

			if ((node->right && std::find(traverse.begin(), traverse.end(), node->right) != traverse.end()) || node->right == NULL)
			{
				val.push_back(node->val);
				record.pop_back();
				traverse.push_back(node);
			}
			else {
				record.push_back(node->right);
			}
		}
		else {
			record.push_back(node->left);
		}

	}
	return val;
}

void postorderTraversalTest()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);

	node1->right = node2;
	node2->left = node3;

	vector<int> v = postorderTraversal(node1);

	for (int i : v)
	{
		cout << i << endl;
	}
}
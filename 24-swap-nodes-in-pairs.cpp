#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		int first;
		ListNode* phead = head;
		while (head != nullptr && head->next != nullptr) {
			first = head->val;
			head->val = head->next->val;
			head->next->val = first;
			head = head->next->next;
		}
		return phead;
	}
};

#include <iostream>
#include <string>
using namespace std;
struct TrieNode
{
	bool hasValue = false;
	TrieNode *children[26];
	TrieNode() {
		memset(children, 0, sizeof(children));
	}
	~ TrieNode() {
	}
};

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}
	~WordDictionary() {
		delTrie(root);
	}

	void delTrie(TrieNode* node) {
		for (int i = 0; i < 26; i++) {
			if (node->children[i]) {
				delTrie(node->children[i]);
			}
		}
		delete node;
	}

	void addWord(const string& word)
	{
		TrieNode* node = root;
		for (int i = 0; i < word.size(); i++) {
			auto ch = node->children[word[i] - 'a'];
			if (ch == nullptr) {
				node->children[word[i] - 'a'] = new TrieNode();
			}
			node = node->children[word[i] - 'a'];
		}
		node->hasValue = true;
	}

	bool search(const string& word) {
		bool s = search(root, word);
		cout << s << endl;
		return s;
	}

private:
	bool search(TrieNode* rootNode, const string& word) {
		TrieNode* node = rootNode;
		if (node == nullptr) {
			return false;
		}
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == '.') {
				for (int j = 0; j < 26; j++) {
					if (node->children[j]) {
						if (i == word.size() - 1)
						{
							if (node->children[j]->hasValue) {
								return true;
							}
							else {
								continue;
							}
						}
						else if (search(node->children[j], word.substr(i + 1))) {
							return true;
						}
					}
				}
				return false;
			}
			else {
				if (node->children[word[i] - 'a'] == nullptr) {
					return false;
				}
				else {
					node = node->children[word[i] - 'a'];
				}
			}
		}
		return node->hasValue;
	}
	TrieNode *root;
};

void main_test_word() {
	WordDictionary t;
	t.addWord("at");
	t.addWord("and");
	t.addWord("an");
	t.addWord("add");
	t.search("a");
	t.search(".at");
	t.addWord("bat");
	t.search(".at");
	t.search("an.");
	t.search("a.d.");
	t.search("b.");
	t.search("a.d");
	t.search(".");
}
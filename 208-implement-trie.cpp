#include <iostream>

using namespace std;

class TrieNode {
public:
	bool hasValue = false;
	TrieNode** children;
	// Initialize your data structure here.
	TrieNode() {
		children = new TrieNode*[26]();
	}
	~TrieNode() {
		for (int i = 0; i < 26; i++) {
			delete children[i];
		}
		delete children;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		findNode(word, true)->hasValue = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		auto node = findNode(word, false);
		return (node != nullptr && node->hasValue);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return findNode(prefix, false) != nullptr;
	}

private:
	TrieNode* findNode(const string &word, bool create) {
		auto node = root;
		int idx = 0;
		for (int i = 0; i < word.size(); i++) {
			idx = word[i] - 'a';
			if (node->children[idx] == nullptr) {
				if (create) {
					node->children[idx] = new TrieNode();
				}
				else {
					return nullptr;
				}
			}
			node = node->children[idx];
		}
		return node;
	}
	TrieNode* root;
};
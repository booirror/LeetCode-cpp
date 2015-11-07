#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int getNextWord(string& out, const string& str, int begin)
{
	while (str[begin] == ' ')
	{
		begin++;
		if (begin >= str.length()) {
			return begin;
		}
	}
	int idx = begin;
	while (str[begin] != ' ' && str.length() > begin) {
		begin++;
	}
	out = str.substr(idx, begin - idx);
	return begin;
}

bool wordPattern(string pattern, string str) {
	int start = 0;
	string word;
	map<char, string> smap;
	map<string, char> cmap;
	for (int i = 0; i < pattern.size(); ++i)
	{
		if (start >= str.length()) return false;
		start = getNextWord(word, str, start);
		auto pos = smap.find(pattern[i]);
		auto iter = cmap.find(word);
		if (pos != smap.end()) {
			if (pos->second.compare(word) != 0)
				return false;
		}
		else if (iter != cmap.end()){
			return false;
		}else{
			smap[pattern[i]] = word;
			cmap[word] = pattern[i];
		}
	}
	return start == str.length();
}

void wordPatternTest()
{
	vector<string> pattern;
	vector<string> str;
	pattern.push_back("abba");
	pattern.push_back("abba");
	pattern.push_back("aaaa");
	pattern.push_back("abba");

	str.push_back("dog cat cat dog");
	str.push_back("dog cat cat fish");
	str.push_back("dog cat cat dog");
	str.push_back("dog dog dog dog");

	for (int i = 0; i < str.size(); ++i) {
		bool res = wordPattern(pattern[i], str[i]);
		cout << res << endl;
	}
}
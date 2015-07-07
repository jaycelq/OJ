#include <iostream>
using namespace std;

class TrieTree {
public:
	class Node {
	public:
		bool endofword;
		int freq;
		Node *children[26];

		Node() {
			for(int i = 0; i < 26; i++) {
				children[i] = NULL;
			}
			freq = 0;
			endofword = false;
		}
	}* root;

	TrieTree(){
		root = new Node();
	}

	void insert(string word){
		Node *n = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'a';
			if(n->children[index] == NULL) 
				n->children[index] = new Node();
			n->children[index]->freq += 1;
			if(i == word.length() - 1)
				n->children[index]->endofword = true;
			n = n->children[index];
		}
	}

	int prefix_frequency(string prefix) {
		Node *n = root;
		for (int i = 0; i < prefix.length(); i++) {
			int index = prefix[i] - 'a';
			if(n->children[index] == NULL) 
				return 0;
			else
				n = n->children[index];
		}
		return n->freq;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	int N, M;
	TrieTree t;

	cin >> N;
	string tmp;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		t.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp;
		cout << t.prefix_frequency(tmp) << endl;
	}

	//system("read");

	return 0;
}
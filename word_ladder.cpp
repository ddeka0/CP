class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if(find(wordList.begin(), wordList.end(),endWord) == wordList.end()) return 0;
		map<string,int> visited;
		visited[beginWord] = 1;
		queue<pair<string,int>> Q; // one vertex = < word , dist >
		Q.push(make_pair(beginWord,1));
		while(!Q.empty()) {
			auto v = Q.front();
			Q.pop();
			string this_word = v.first;
			int this_dist = v.second;
			if(this_word == endWord) return this_dist;
			for(string word:wordList) {
				if(is_adjacent(this_word,word) && !visited[word]) {
					Q.push( make_pair( word , this_dist + 1) );
					visited[word] = 1;
				}
			}
		}
		return 0;
	}
	bool is_adjacent(string a,string b) {
		int diff = 0;
		int n = a.length();
		for(int i = 0;i<n;i++) {
			if(a[i] != b[i] ) diff_count++;
			if(diff_count > 1) return false;
		}
		return diff_count == 1;
	}
};
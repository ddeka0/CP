#include <bits/stdc++.h>
using namespace std;
int lsp[100000];
int main() {
	string pat = "anc";
	string text = "lanndlksnanclsac";
	text = pat + "#" + text;
	for(int i = 1;i < (int)(text.length());i++) {
		int j = lsp[i - 1];
		while(j > 0 && text[i] != text[j]) {
			j = lsp[j - 1];
		}
		if(text[i] == text[j]) {
			j++;
		}
		lsp[i] = j;
	}
	for(int i = 0;i<(int)(text.length());i++) {
		if(lsp[i] == (int)(pat.length())) {
			cout <<"found at index"<<i - 5<<endl;
		}
	}
}
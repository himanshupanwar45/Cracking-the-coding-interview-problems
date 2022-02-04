#include<bits/stdc++.h>
using namespace std;

int isUniqueCharsMap(string s) {

	//using hashmap
	//time complexity : O(n)
	//space complexity  : O(n)

	unordered_map<char, int> mp;

	for (int i = 0 ; i < s.length() ; i++) {

		if (mp[s[i]] > 0) return 0;
		mp[s[i]]++;
	}

	return 1;
}

int isUniqueChars(string s) {

	//using bit-vector [ assuming that string will only contain lowercase characters ]
	//Time Complexity : O(n) [n is length of string]
	//Space Complexity : O(1)

	int checker = 0;

	for (int i = 0 ; i < s.length() ; i++) {

		int ind = s[i] - 'a';

		if (checker & (1 << ind)) {
			return 0;
		}

		checker = checker | (1 << ind);
	}

	return 1;


}

int main() {

	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);

	string s;
	cin >> s;


	isUniqueCharsMap(s) ? cout << "YES" : cout << "NO";
}
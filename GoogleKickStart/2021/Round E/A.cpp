#include <iostream>
#include <string> 
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

char answer[10001];

bool sortbysec(const pair<char, int>& a,
	const pair<char, int>& b)
{
	return (a.second < b.second);
}

bool sortbyfirst(const pair<int, char>& a,
	const pair<int, char>& b)
{
	return (a.first< b.first);
}

string solution(string s)
{
	int alphabet[26] = { 0 };
	memset(answer, '\0', sizeof(answer));
	for (int i = 0; i < s.length(); i++) {
		alphabet[s[i] - 'a']++;
	}

	vector<pair<int, char>> sorted_ch;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
	
			sorted_ch.push_back(pair<int, char>(alphabet[i], 'a' + i));
		}
	}

	sort(sorted_ch.begin(), sorted_ch.end(), greater<pair<int, char>>());
	
	int sum = 0;
	for (int i = 1; i < sorted_ch.size(); i++) {
		sum += sorted_ch[i].first;
	}
	if (sorted_ch[0].first > sum) {
		return "IMPOSSIBLE";
	}

	stringstream ss;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != sorted_ch[0].second) {
			sorted_ch[0].first--;
			ss << sorted_ch[0].second;
			if (sorted_ch[0].first == 0) {
				sorted_ch.erase(sorted_ch.begin());
			}
		}
		else
		{
			sorted_ch[1].first--;
			ss << sorted_ch[1].second;
			if (sorted_ch[1].first == 0) {
				sorted_ch.erase(std::next(sorted_ch.begin()));
			}
		}
	}

	return ss.str();
}

int main()
{
	//FILE *input;
	//FILE *output;
	//freopen_s(&input, "A-large.in", "r", stdin);
	//freopen_s(&output, "A-large.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
				
		string s;
		cin >> s;

		cout << "Case #" << i << ": " << solution(s) << endl;
	}
}
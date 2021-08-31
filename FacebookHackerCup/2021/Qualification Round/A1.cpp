#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int solution(string S)
{
	//max number of vowel
	//max number of consonant

	//if there are two vowels, then those vowels should turn into consonants
	//if there is only one kind of vowel, and the number of that vowel in the string is the biggest, the other vowel needs to take 2 second to change to it, and other consonants take once

	//so we need to consider the case of biggest number of vowel and the biggest number of consonants
	//the biggest number of vowel or consonant maybe is zero
	
	map<char, int> vowels;
	map<char, int> consonants;

	int count_v = 0;
	int count_c = 0;
	for (int i = 0; i < S.length(); i++) {
		char ch = S[i];
		if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
			if (vowels.find(S[i]) != vowels.end()) {
				vowels[ch]++;
			}
			else {
				vowels.insert(pair<char, int>(ch, 1));
			}
			count_v++;
		}
		else {
			if (consonants.find(S[i]) != consonants.end()) {
				consonants[ch]++;
			}
			else {
				consonants.insert(pair<char, int>(ch, 1));
			}
			count_c++;
		}
	}

	int max_v = 0;
	int max_c = 0;

	std::map<char, int>::iterator it;
	for (it = vowels.begin(); it != vowels.end(); ++it){
		if (it->second > max_v) {
			max_v = it->second;
		}
	}

	for (it = consonants.begin(); it != consonants.end(); ++it) {
		if (it->second > max_c) {
			max_c = it->second;
		}
	}

	//case of vowels
	int answer1 = (count_v - max_v) * 2 + count_c;
	int answer2 = (count_c - max_c) * 2 + count_v;

	return std::min(answer1, answer2);

}

int main()
{
	int T = 0;
	std::ifstream in("consistency_chapter_1_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("consistency_chapter_1_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		string S;
		cin >> S;
		
		cout << "Case #" << i+1 << ":";
		cout << solution(S) << endl;
	}
}
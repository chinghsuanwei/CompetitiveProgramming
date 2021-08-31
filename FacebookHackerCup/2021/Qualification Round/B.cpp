#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


void solution(int N, int& minimum, int& ways)
{
	//So we only need to scan every horizontal line and vertical line

	//just remember the answers of N*N array
	//and minimun number is the answer

	//we need to consider an extra case that when the minimun is 1, then need to check is it's horizontal and vertical is the same
	//so just check all rows, check if cross is all X then minus 1

	string S[50];
	int answer[2][50] = { 0 };
	
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	
	
	//for rows
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (S[i][j] == 'O') {
				count = -1;
				break; //impossible
			}
			else if (S[i][j] == '.') count++;
		}
		
		answer[0][i] = count;
		if (count > 0 && count < minimum) {
			minimum = count;
		}
	}
	
	//for cols
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (S[j][i] == 'O') {
				count = -1;
				break; //impossible
			}
			else if (S[j][i] == '.') count++;
		}

		answer[1][i] = count;
		if (count > 0 && count < minimum) {
			minimum = count;
		}
	}

	if (minimum == 0) {
		ways = 0;
		return;
	} else {
		ways = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				if (answer[i][j] == minimum) ways++;
			}
		}

		if (minimum == 1) {
			for (int i = 0; i < N; i++) {
				if (answer[0][i] == 1) {
					int index = S[i].find(".");
					// X.X
					// XXX
					// XXX
					if (answer[1][index] == 1) {
						ways--;
					}
				}
			}
		}

		return;
	}
}

int main()
{
	int T = 0;
	std::ifstream in("xs_and_os_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("xs_and_os_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		int N;
		cin >> N;
		
		int minimum = INT_MAX;
		int ways = 0;
		solution(N, minimum, ways);

		cout << "Case #" << i + 1 << ": ";
		if (ways == 0) {
			cout << "Impossible";
		}
		else {
			cout << minimum << " " << ways;
		}
		cout << endl;
	}
}
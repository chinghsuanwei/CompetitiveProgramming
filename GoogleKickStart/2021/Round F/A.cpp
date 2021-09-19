#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


long long solution(int N, string S)
{
	int * distance = new int[N];
	int d = 5000000;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			d = 0;
		}
		else {
			d++;
		}

		distance[i] = d;
	}
	
	d = 5000000;
	long long sum = 0;
	for (int i = N-1; i >= 0; i--) {
		if (S[i] == '1') {
			d = 0;
		}
		else {
			d++;
		}

		distance[i] = min(d, distance[i]);
		sum += distance[i];
	}


	delete[] distance;
	return sum;
}

int main()
{
	int T = 0;
	//std::ifstream in("weak_typing_chapter_2_input.txt");
	//std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	//std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	//std::ofstream out("weak_typing_chapter_2_output.txt");
	//std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	//std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		int N;
		cin >> N;

		string S;
		cin >> S;
		
		cout << "Case #" << i+1 << ": ";
		cout << solution(N, S) << endl;
	}
}
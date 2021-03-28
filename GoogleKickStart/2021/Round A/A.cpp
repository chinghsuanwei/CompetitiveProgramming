#include <iostream>
#include <string> 
#include <math.h>

using namespace std;

int current_score(string S)
{
	unsigned int size = S.length();
	int score = 0;
	for (int i = 0; i < size / 2; i++) {
		if (S[i] != S[size - i - 1])
		{
			score++;
		}
	}

	return score;
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
		int N, K;
        string S;
        cin >> N;
		cin >> K;
		cin >> S;

		int score = current_score(S);
		cout << "Case #" << i << ": " << abs(K - score) << endl;
	}
}
#include <iostream>
#include <string> 
#include <math.h>
#include <algorithm>

using namespace std;
int matrix[3][3];

int is_arithmetic_progression(int a, int b, int c)
{
	if ((c - b) == (b - a)) return 1;
	else return 0;
}

int cal(int number)
{
	int answer = 0;
	matrix[1][1] = number;

	for (int i = 0; i < 3; i++)
	{
		answer += is_arithmetic_progression(matrix[0][i], matrix[1][i], matrix[2][i]); // |
		answer += is_arithmetic_progression(matrix[i][0], matrix[i][1], matrix[i][2]); //---
	}

	answer += is_arithmetic_progression(matrix[0][0], matrix[1][1], matrix[2][2]);
	answer += is_arithmetic_progression(matrix[0][2], matrix[1][1], matrix[2][0]);

	return answer;
}

bool possible_number(int a, int b, int& number)
{
	if (a == b) {
		number = a;
		return true;
	}
	else {
		int big = max(a, b);
		int small = min(a, b);
		
		if ((big - small) % 2 == 0) {
			number = small + (big - small) / 2;
			return true;
		}
		else return false;
	}
}

int route(int a, int b)
{
	int number;
	if (possible_number(a, b, number)) {
		return cal(number);
	}
	return 0;
}

int solution()
{
	int answer = 0;
	
	int r = route(matrix[0][0], matrix[2][2]);

	if (r > answer){
		answer = r;
	}
	r = route(matrix[0][2], matrix[2][0]);

	if (r > answer) {
		answer = r;
	}

	r = route(matrix[0][1], matrix[2][1]);

	if (r > answer) {
		answer = r;
	}

	r = route(matrix[1][0], matrix[1][2]);
	
	if (r > answer) {
		answer = r;
	}

	return answer;
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
		
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if (j == 1 && k == 1) continue;
				cin >> matrix[j][k];
			}

		cout << "Case #" << i << ": " << solution() << endl;
	}
}
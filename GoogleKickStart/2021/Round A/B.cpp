#include <iostream>
#include <string> 
#include <math.h>
#include <memory.h>

using namespace std;

int segment[1001][1001][4];

const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;

long long solution(int row, int col)
{
	int sum = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			for (int d = LEFT; d <= RIGHT; d++) {
				if (segment[r][c][d] >= 2) {
					if (segment[r][c][UP] >= 4) {
						int n = segment[r][c][UP] >= (segment[r][c][d] * 2) ? segment[r][c][d] - 1 : (segment[r][c][UP] / 2) - 1;
						sum += n;
					}

					if (segment[r][c][DOWN] >= 4) {
						int n = segment[r][c][DOWN] >= (segment[r][c][d] * 2) ? segment[r][c][d] - 1 : (segment[r][c][DOWN] / 2) - 1;
						sum += n;
					}
				}
			}
			
			for (int d = UP; d <= DOWN; d++) {
				if (segment[r][c][d] >= 2) {
					if (segment[r][c][LEFT] >= 4) {
						int n = segment[r][c][LEFT] >= (segment[r][c][d] * 2) ? segment[r][c][d] - 1 : (segment[r][c][LEFT] / 2) - 1;
						sum += n;
					}

					if (segment[r][c][RIGHT] >= 4) {
						int n = segment[r][c][RIGHT] >= (segment[r][c][d] * 2) ? segment[r][c][d] - 1 : (segment[r][c][RIGHT] / 2) - 1;
						sum += n;
					}
				}
			}
		}
	}

	return sum;
}


int main()
{
	//FILE *input;
	//FILE *output;
	//freopen_s(&input, "C-sample.in", "r", stdin);
	//freopen_s(&output, "A-large.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		int row, col;
		string vs[1001];
        cin >> row;
		cin >> col;

		for (int r = 0; r < row; r++) {
			int l = 0;
			
			for (int c = 0; c < col; c++) {
				char ch;
				cin >> ch;
				
				if (ch == '1') {
					l++;
				}
				else {
					l = 0;
				}
				segment[r][c][LEFT] = l;
				vs[c] += ch;
			}
			
			for (int c = col-1; c >=0 ;) {
				if (segment[r][c][LEFT] >= 1) {
					int size = segment[r][c][LEFT];
					for (l = 1; l <= size; l++, c--) {
						segment[r][c][RIGHT] = l;
					}
				}
				else
				{
					segment[r][c][RIGHT] = 0;
					c--;
				}
			}
			
			
		}

		for (int c = 0; c < col; c++) {
			int l = 0;
			for (int r = 0; r < row; r++) {
				if (vs[c][r] == '1') {
					l++;
				}
				else {
					l = 0;
				}
				segment[r][c][UP] = l;
			}

			for (int r = row - 1; r >= 0;) {
				if (segment[r][c][UP] >= 1) {
					int size = segment[r][c][UP];
					for (l = 1; l <= size; l++, r--) {
						segment[r][c][DOWN] = l;
					}
				}
				else
				{
					segment[r][c][DOWN] = 0;
					r--;
				}
			}
		}

		cout << "Case #" << i << ": " << solution(row, col) << endl;
	}
}
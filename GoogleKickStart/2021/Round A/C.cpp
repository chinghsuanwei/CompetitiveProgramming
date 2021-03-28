#include <iostream>
#include <string> 
#include <math.h>
#include <memory.h>

using namespace std;

int matrix[301][301];


long long solution(int row, int col, int max)
{
	int answer[301][301] = { 0 };
	memcpy(answer, matrix, sizeof(matrix));

	bool changed = true;
	while(max > 0 && changed)
	{
		changed = false;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {

				if (answer[r][c] == max) {

					//up
					if (r - 1 >= 0 && answer[r - 1][c] < max)
					{
						answer[r - 1][c] = max-1;
						changed = true;
					}
					//down
					if (r + 1 < row && answer[r + 1][c] < max)
					{
						answer[r + 1][c] = max-1;
						changed = true;
					}
					//left
					if (c - 1 >= 0 && answer[r][c - 1] < max)
					{
						answer[r][c - 1] = max-1;
						changed = true;
					}
					//right
					if (c + 1 < col && answer[r][c + 1] < max)
					{
						answer[r][c + 1] = max-1;
						changed = true;
					}
				}
				else if (answer[r][c] == max - 1)
				{
					changed = true;
				}
			}
		}

		max--;
	}
	
	long long sum = 0;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			//cout << answer[r][c] << " ";
			sum += answer[r][c] - matrix[r][c];
		}
		//cout << endl;
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
        string S;
        cin >> row;
		cin >> col;

		int max = 0;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				cin >> matrix[r][c];
				if (matrix[r][c] > max) {
					max = matrix[r][c];
				}
			}
		}

		cout << "Case #" << i << ": " << solution(row, col, max) << endl;
	}
}
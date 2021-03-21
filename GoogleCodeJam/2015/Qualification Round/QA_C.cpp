#include <iostream>

using namespace std;
int main()
{
	FILE *input;
	FILE *output;
	freopen_s(&input, "C-large-practice.in", "r", stdin);
	freopen_s(&output, "C-large-practice.out", "w", stdout);

	int T;
	cin >> T;

	char valueTable[3][3] = { { 'x', 'k', 'j' }, { 'k', 'x', 'i' }, { 'j', 'i', 'x' } };
	int signTable[3][3] = { { -1, 1, -1 }, { -1, -1, 1 }, { 1, -1, -1 } };
	char task[3] = { 'i', 'j', 'k' };

	for (int i = 1; i <= T; i++){
		int n;
		cin >> n;

		long long repeat;
		cin >> repeat;

		char str[10001];
		cin >> str;

		char value = 'x';
		int sign = 1;
		int taskProgress = 0;
		int count = 0;
		bool firsttime = true;

		for (long long j = 0; j < repeat; j++){
			for (int k = 0; k < n; k++){
				if (value == 'x') value = str[k];
				else {
					int row = (int)(value - 'i');
					int col = (int)(str[k] - 'i');
					
					value = valueTable[row][col];
					sign *= signTable[row][col];
				}

				if (taskProgress < 2 && task[taskProgress] == value && sign == 1 ){
					taskProgress++;
					value = 'x';
					count = 0;
				}
			}


			//1 , -1, i, -i, j, -j, k, -k
			count++;
			if (count >= 8) break;
			if (taskProgress == 2 && value == 'k' && sign == 1 && count > 0){
				if (firsttime){
					count = 0;
					firsttime = false;
				} else {
					if ((repeat - j - 1) % count != 0) value = 'x';
					break;
				}
			}
		}

		cout << "Case #" << i << ": ";

		if (taskProgress == 2 && value == 'k' && sign == 1){
			cout << "YES";
		} else cout << "NO";

		cout << endl;
	}

	//system("pause");
}

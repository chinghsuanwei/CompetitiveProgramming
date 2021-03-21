#include <iostream>

using namespace std;

//int main()
//{
//	FILE *input;
//	FILE *output;
//	freopen_s(&input, "A-large.in", "r", stdin);
//	freopen_s(&output, "A-large.out", "w", stdout);
//
//	int T;
//	cin >> T;
//
//	for (int i = 1; i <= T; i++){
//		int maxLevel;
//		cin >> maxLevel;
//		char str[1001];
//		cin >> str;
//
//		int len = strlen(str);
//		int sum = 0;
//		int result = 0;
//		for (int j = 0; j <= maxLevel; j++) {
//			
//			if (sum < j){
//				int diff = j - sum;
//				sum += diff;
//				result += diff;
//			}
//
//			int n = str[j] - '0';
//			sum += n;
//		}
//
//		cout << "Case #" << i << ": " << result << endl;
//	}
//
//
//}
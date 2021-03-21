#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int numbers[1000];

//int main()
//{
//	FILE *input;
//	FILE *output;
//	freopen_s(&input, "B-small-attempt4.in", "r", stdin);
//	freopen_s(&output, "B-small-attempt4.out", "w", stdout);
//
//	int T;
//	cin >> T;
//
//	for (int i = 1; i <= T; i++){
//
//		int size;
//		cin >> size;
//
//		for (int j = 0; j < size; j++) cin >> numbers[size];
//
//		std::sort(std::begin(numbers), std::end(numbers));
//		
//		int penalty = 0;
//		int cur;
//		int p = 0;
//		int answer = 0;
//
//		while ( p < size ){
//
//			cur = numbers[p];
//			p++;
//			int n = 1; // n's same number
//			while (p < size && numbers[p] == cur ){
//				n++;
//			}
//
//			if (min <= 3) answer = min;
//			else {
//				int lastValue = min + penalty;
//				int p = 1;
//				for (int d = 2;; d++, p++){
//					int value = min / d + min % d + p*n + penalty; // the max value
//
//					int m = max(answer + p*n, value);
//					if (lastValue > m){
//						lastValue = m;
//					}
//					else break;
//				}
//				penalty += (p - 1)*n;
//				answer = lastValue;
//			}
//		}
//
//		cout << "Case #" << i << ": " << answer << endl;
//	}
//
//	//system("pause");
//}
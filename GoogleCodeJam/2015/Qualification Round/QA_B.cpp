#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

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
//		int k;
//		cin >> k;
//
//		list<int> array;
//
//		for (int j = 0; j < k; j++) {
//			int number;
//			cin >> number;
//			array.push_back(number);
//		}
//
//		array.sort();
//
//		int penalty = 0;
//		int min;
//		int answer = 0;
//
//		while (array.size() > 0){
//			
//			min = array.front();
//			array.pop_front();
//			int n = 1; // n's same number
//			while (array.size() > 0 && min == array.front()){
//				array.pop_front();
//				n++;
//			}
//
//			if (min <= 3) answer = min;
//			else {
//				int lastValue = min + penalty;
//				int p = 1;
//				for (int d=2;; d++, p++){
//					int value = min / d + min % d + p*n + penalty; // the max value
//
//					int m = max(answer + p*n, value);
//					if ( lastValue > m ){
//						lastValue = m;
//					} else break;
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
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	
int M = 0;
int N = 0;
int K = 0;
int count = 0;
int ans = 0;
cin >> N >> M >> K;
int arr[500][500] = { 0 };
for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		cin >> arr[N][M];
	}
}
int m = 0;
int n = 0;
while (n < N) {
	while (m < M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int p = 0; p < m; p++) {
					if (p + m <= M) {
						count += arr[N][M+p];
					}
				}
				for(int q =0;q<n;q++)
					if (q + n <= N) {
						count += arr[N + q][M];
					}
				count += arr[N][M];
				if (count <= K) {
					ans++;
				}
				count = 0;
			}

		}
		m++;
	}
	n++;
}
cout << ans << endl;

	system("pause");
	return 0;
}

//#include<algorithm>
//int a = 0;
//int b = 0;
//int day = 0;
//int count = 0;
//long long n = 0;
//cin >> a >> b >> n;
//while (count < n) {
//	if (day % 6 == 0 || day % 7 == 0) {
//		count += b;
//	}
//	else {
//		count += a;
//	}
//	day++;
//}
//cout << day << endl;


//int N = 0;
//cin >> N;
//int arr[10000] = { 0 };
//for (int i = 0; i < N; i++) {
//	int _max = max(i, N - i - 1);
//	arr[i] = 2 * _max;
//}
//for (int i = 0; i < N; i++) {
//	cout << arr[i] << endl;
//}
//*/


//int M = 0;
//int N = 0;
//int K = 0;
//int count = 0;
//int ans = 0;
//cin >> N >> M >> K;
//int arr[500][500] = { 0 };
//for (int i = 0; i < N; i++) {
//	for (int j = 0; j < M; j++) {
//		cin >> arr[N][M];
//	}
//}
//
//for (int i = 0; i < N; i++) {
//	for (int j = 0; j < M; j++) {
//		for (int m = 0; m < M; m++) {
//			for (int n = 0; n < N; n++) {
//				int a = m
//					while (m) {
//						count += arr[N][M];
//					}
//			}
//		}
//	}
//}

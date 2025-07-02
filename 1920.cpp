#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, M;
int n;
int arr[100000];

int solve(int n) {
	int st = 0;
	int ed = N - 1;
	while (st <= ed) {	
		int mid = (st + ed) / 2;
		if (arr[mid] == n) return 1;
		else if (n < arr[mid]) ed = mid - 1;
		else st = mid + 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n;
		cout << solve(n) << "\n";
	}
}
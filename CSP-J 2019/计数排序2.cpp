#include <iostream>
using namespace std;

int a[1001], cnts[1001], results[1001] ,n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnts[a[i]]++;
	}


	for (int i = 0; i < n; i++)
		cnts[i+1] += cnts[i];

	/*for (int i = 1; i <= n; i++)
		cout << cnts[i] << " ";*/

	for (int i = n-1; i >= 0; i--) {
		results[--cnts[a[i]]] = i;
	}

	for (int i = 0; i < n; i++)
		cout << a[results[i]] << " ";
	return 0;
}

/*
6
3 2 3 1 5 6
*/
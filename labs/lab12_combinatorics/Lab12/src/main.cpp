#include <iostream>
#include <cmath>
// Lab 12
int c1 = 0;
int c2 = 0;

void sp1(int** D1, int str, int stl, int n) {
	if (str == n) {
		c1++;
		print();
		return;
	}
	for (stl = 0; stl < n; stl++) {
		if (lob()) {
			D1[str][stl] = 1;
		}

	}
}

int main(){
	int n;
	std::cin >> n;
	if (n <= 0) return 0;
	int** D1 = new int* [n];
	for (int i = 0; i < n; i++) {
		D1[i] = new int[n];
		for (int j = 0; j < n; j++) {
			D1[i][j] = 0;
		}
	}
	int* D2 = new int[n];


}
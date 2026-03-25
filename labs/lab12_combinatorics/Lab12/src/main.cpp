#include <iostream>
#include <cmath>
// Lab 12
int c1 = 0;
int c2 = 0;
void print1(int** D1, int n) {
	std::cout << "[";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (D1[i][j] == 1) {
				std::cout << j + 1;
				if (i < n - 1) { std::cout << ","; }
				break;
			}
		}
	}
	std::cout << "]" << std::endl;
}

void print2(int* D2, int n) {
	std::cout << "[";
	for (int i = 0; i < n; i++) {
		std::cout << D2[i] + 1;
		if (i < n - 1) std::cout << ",";
	}
	std::cout << "]";
}



bool lob(int** D1, int str, int stl, int n) {
	for (int i = 0; i < str; i++) {
		if (D1[i][stl] == 1) return false;
	}
	for (int i = str, j = stl; i >= 0 and j >= 0; i--, j--) {
		if (D1[i][j] == 1) return false;
	}

	for (int i = str, j = stl; i >= 0 and j < n; i--, j++) {
		if (D1[i][j] == 1) return false;
	}
	return true;
}

void sp1(int** D1, int str, int n) {
	if (str == n) {
		c1++;
		print1(D1, n);
		return;
	}
	for (int stl = 0; stl < n; stl++) {
		if (lob(D1, str, stl, n)) {
			D1[str][stl] = 1;
			sp1(D1, str + 1, n);
			D1[str][stl] = 0;
		}
	}
}


bool obh(int* D2, int str, int stl) {
	for (int i = 0; i < str; i++) {
		if (D2[i] == stl or abs(D2[i] - stl) == abs(str - i)) {
			return false;
		}
	}
	return true;
}

void sp2(int* D2, int str, int n) {
	if (str == n) {
		c2++;
		print2(D2, n);
		printf("\n");
		return;
	}
	for (int stl = 0; stl < n; stl++) {
		if (obh(D2, str, stl)) {
			D2[str] = stl;
			sp2(D2, str + 1, n);
		}
	}
}

int main(){
	int n=4;
	//std::cin >> n;
	if (n <= 0) return 0;
	int** D1 = new int* [n];
	for (int i = 0; i < n; i++) {
		D1[i] = new int[n];
		for (int j = 0; j < n; j++) {
			D1[i][j] = 0;
		}
	}
	int* D2 = new int[n];

	sp1(D1, 0, n);
	std::cout << c1 << std::endl;

	sp2(D2, 0, n);
	std::cout << c2 << std::endl;
}
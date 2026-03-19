#include <iostream>
using namespace std;

int main(){
	//Çàäàíèå 1
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> arr[i];
	}
	if (arr[0] < arr[9]) {
		cout << "Error" << endl;
	}
	else {
		for (int i=0; i<9; ++i) {
			for (int j = i+1; j < 10; ++j) {
				if (arr[i] > arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << endl;
	}

	//Çàäàíèå 2
	const int x = 3, y = 4;
	int matrix[x][y];
	cout << "Enter the elements of the matrix " << x << "x" << y << ":" << endl;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << "Enter the number that stands still " << i << " " << j << " : ";
			cin >> matrix[i][j];
		}
	}
	
	// ñòîëáåö ñ ìàêñèìàëüíîé ñóììîé ÷èñåë
	int max_y = 0;
	int maxsm = -1;
	for (int j = 0; j < y; ++j) {
		int sm = 0;
		for (int i = 0; i < x; ++i) {
			sm += matrix[i][j];
		}
		if (sm > maxsm) {
			max_y = j;
			maxsm = sm;
		}
	}
	cout << "Y: " << max_y +1 << " MaxSum: " << maxsm << endl;

	for (int i = 0; i < x; ++i) {
		matrix[i][max_y] = 0;
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sum(const int x, const int y, const int z = 0, const int t = 0);
double sum(const double x, const double y);
int arbitrarySum(const int length, int totalNums[]);
void Program_PI();
void printArray(const int numbers[], const int totalLength);
void reverseArray(int numbers[], const int totalLength);

int main() {

	//Program_PI();

	const int length = 7;
	int num[length] = { 1,2,3,4,5,6,7 };

	//printArray(num, length);
	reverseArray(num, length);

	system("PAUSE");
	return 0;
}

void Program_PI() {

	srand(time(0));

	long numberOfSuccess = 0;
	long numberOfCounts = 500000;

	for (long i = 0; i < numberOfCounts; i++) {
		double randNumX = (double)rand()/RAND_MAX;
		double randNumY = (double)rand()/RAND_MAX;
		double functionCircle = sqrt(1 - randNumX*randNumX);

		if (randNumY < functionCircle) {
			numberOfSuccess++;
			cout << i << ": Success: " << numberOfSuccess << endl;
		}
	}

	cout << "El valor del numero PI es: " << (double)numberOfSuccess / numberOfCounts * 4 << endl;

}

int sum(const int x, const int y, const int z, const int t) {
	return x + y + z + t;
}

double sum(const double x, const double y) {
	return x + y;
}

int arbitrarySum(const int length, const int totalNums[]) {

	return length == 0 ? 0 : totalNums[0] + arbitrarySum(length - 1, totalNums + 1);
}

void printArray(const int numbers[], const int totalLength ) {

	for (int i = 0; i < totalLength-1; i++) {
		cout << numbers[i] << ", ";
	}
	cout << numbers[totalLength - 1] << "." << endl;
}

void reverseArray(int numbers[], const int totalLength){
	
	int fooVar;
	for (int i = 0; i < totalLength/2; i++) {
		fooVar = numbers[i];
		numbers[i] = numbers[totalLength - i - 1];
		numbers[totalLength - i - 1] = fooVar;
	}

	printArray(numbers, totalLength);
}
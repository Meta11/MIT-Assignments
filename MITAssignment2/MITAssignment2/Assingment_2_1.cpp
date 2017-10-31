#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LENGTH = 2;
const int WIDTH = 3;
//Parte 4
int sum(const int x, const int y, const int z = 0, const int t = 0);
double sum(const double x, const double y);
int arbitrarySum(const int length, int totalNums[]);
//Parte 5
void Program_PI();
//Parte 6
void printArray(const int numbers[], const int totalLength);
void reverseArray(int numbers[], const int totalLength);
void transpose(const int input[][LENGTH], int output[][WIDTH]);
void reverseArrayPointer(int *numbers, const int totalLength);
//Parte 7
int stringLength(char* strToCalc);
void swap1(int &x, int &y);
void swap2(int *x, int *y);
void swap3(int **ptr1, int **ptr2);

void Program5();

int main() {

	//Program_PI();
	//Ejercicio 6
	/*int num[WIDTH][LENGTH];
	int numOut[LENGTH][WIDTH];

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			num[i][j] = i + j * 2;
			cout << num[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	transpose(num, numOut);

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << numOut[i][j] << " ";
		}
		cout << endl;
	}

	printArray(num, length);
	reverseArray(num, length);*/

	/*int x = 1, y = 2;
	swap1(x, y);
	cout << x << " " << y << endl;
	swap2(&x, &y);
	cout << x << " " << y << endl;

	int z = 5;
	int t = 6;
	int *ptr1 = &z;
	int *ptr2 = &t;
	swap3(&ptr1, &ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;*/

	Program5();

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

void transpose(const int input[][LENGTH], int output[][WIDTH]) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			output[i][j] = input[j][i];
		}
	}
}

void reverseArrayPointer(int *numbers, const int totalLength) {
	int fooVar;

	for (int i = 0; i < totalLength / 2; i++) {
		fooVar = *(numbers + i);
		*(numbers + i) = *(numbers + totalLength - i - 1);
		*(numbers + totalLength - i - 1) = fooVar;
	}
}

int stringLength(const char* strToCalc) {

	int counter = 0;

	while (*(strToCalc + counter) != '\0') {
		counter++;
	}
	return counter;
}

void swap1(int &x, int &y) {
	int fooVar = x;
	x = y;
	y = fooVar;
}

void swap2(int *x, int *y){
	int fooVar = *x;
	*x = *y;
	*y = fooVar;
}

void swap3(int **ptr1, int **ptr2) {
	int *fooPtr = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = fooPtr;
}

//7.5
void Program5() {
	char *oddOrEven = "Never odd or even ";
	char *nthCharPtr = &oddOrEven[5];
	nthCharPtr -=2;
	char **pointerPtr = &nthCharPtr;
	cout << pointerPtr << endl;
	cout << **pointerPtr << endl;
	nthCharPtr++;
	cout << nthCharPtr - oddOrEven << endl;;
}

#include <iostream>

using namespace std;

void Programa1_1();
void Programa1_2();
void Programa1_3();

int main() {

	//Programa1_1();
	//Programa1_2();
	Programa1_3();

	system("PAUSE");
	return 0;
}

void Programa1_1() {
	float notas;
	float suma = 0;
	float fooNota;

	float max = -1;
	float min = 1000;

	cout << "Introduce el numero de notas: ";
	cin >> notas;

	cout << "\nIntroduce las notas: " << endl;

	for (int i = 0; i < notas; i++) {
		cin >> fooNota;
		suma += fooNota;

		if (fooNota < min) {
			min = fooNota;
		}
		else if (fooNota > max) {
			max = fooNota;
		}
	}

	cout << "Media: " << suma / notas << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Rango: " << max - min << endl;
}
void Programa1_2() {

	int number;
	bool isPrime;

	cout << "Introduce el numero hasta el que quieres encontrar los primos: ";
	cin >> number;
	cout << "Los numeros primos son: " << endl;

	for (int i = 1; i <= number; i++) {
		isPrime = true;

		for (int j = 1; j < i; j++) {
			if (j != 1 && i%j == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {
			cout << i << endl;
		}
	}
}
void Programa1_3() {
	//Versión 1
	/*int num;
	cout << "Introduce los enteros: " << endl;
	while (cin >> num) {
		(num % 5 == 0 && num > 0) ? (cout << num / 5 << endl) : cout << "-1" << endl;
	}*/

	//Versión 2
	/*int num;
	cout << "Introduce los enteros: " << endl;
	while (cin >> num) {
		if (num % 5 == 0 && num > 0) {
			cout << num / 5 << endl;
		}
		else {
			continue;
		}
	}*/

	//Versión 3

	int num;
	cout << "Introduce los enteros: " << endl;
	while (cin >> num) {
		if (num % 5 == 0 && num > 0) {
			cout << num / 5 << endl;
		}
		else if (num < 0) {
			cout << "Goodbye!" << endl;
			break;
		}
		else {
			continue;
		}
	}
}
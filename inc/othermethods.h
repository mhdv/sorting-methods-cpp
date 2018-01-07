#ifndef OTHERMETHODS_H
#define OTHERMETHODS_H

#include <iostream>
#include <cstdlib>

// tworzenie 100 tablic z losowymi liczbami od 0 do 10 000
template <typename T>
T** randomArray(int size){
	T **array = new T *[100];
	for(int i=0; i<100; ++i){
		array[i] = new T[size];
		for(int j=0; j<size; ++j){
			array[i][j]=rand()%10000;
		}
	}
	return array;
}

// sprawdzenie czy tablica jest posortowana
template <typename T>
bool isSorted(T* arr, int size){
	for(int i=0; i<size-1; ++i){
		if(arr[i]>arr[i+1]){
			std::cout << "\n NIE JEST POSORTOWANA \n";
			return false;
		}
	}
	std::cout << "\n JEST POSORTOWANA \n";
	return true;
}

// wyswietlanie tablicy
template <typename T>
void displayArray(T* arr, int size){
	for(int i=0; i<size; ++i){
		std::cout << arr[i] << " ";
	}
}


// uzupelnianie tablic z danym posortowaniem
template <typename T>
T** percentageRandomArray(int size, float percentage){
	T **array = new T *[100];
	if(percentage>100) percentage = 100;
	if(percentage<0) percentage = 0;
	float real_max = 0.01*percentage*size;
	int max = static_cast<int>(real_max);
	for(int i=0; i<100; ++i){
		array[i] = new T[size];
		for(int j=0; j<size; ++j){
			if(j<max) array[i][j] = j;
			else array[i][j] = rand()%10000;
		}
	}
	return array;
}

// uzupelnianie tablic z odwrotnym posortowaniem
template <typename T>
T** invertedRandomArray(int size){
	T **array = new T *[100];
	for(int i=0; i<100; ++i){
		array[i] = new T[size];
		for(int j=0; j<size; ++j){
			array[i][j] = size-j;
		}
	}
	return array;
}


#endif
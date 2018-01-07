#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

// naglowek z innymi metodami
#include "othermethods.h"
#include "sortingmethods.h"

void timeMeasure(time_t beginning, time_t ending);


int main(){
	srand(time(NULL));

//######################################
//KONFIGURACJA PROGRAMU
//######################################

	//UWAGA!
	//wybor wielkosci tablicy w pliku sortingmethods.h
	//~~~~~~

	int **x; 						// inicjacja zmiennej na tablice
	float arrcreate = 0;			// procent posortowania tablic poczatkowych
	char sorting = 'q';				// wybor typu sortowania: q-quicksort; m-mergesort, s-shellsort, i-introsort(?)
	bool invertedarray = false;		// czy tablica ma byc odwrotnie posortowana na starcie?
	bool onearray = false;			// czy testy wykonac dla tylko jednej ze 100 tablic

	bool displaysamplelist = false;	// czy na koncu wyswietlic pierwsza tablice po sortowaniu (do testow)

//######################################

	if(invertedarray) x = invertedRandomArray<int>(ARRAY_SIZE);
	else x = percentageRandomArray<int>(ARRAY_SIZE, arrcreate);



	switch(sorting){
		case 'q':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) quicksort(x[0], 0, ARRAY_SIZE);
			else
				for(int i=0; i<100; ++i)
					quicksort(x[i], 0, ARRAY_SIZE);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		case 'm':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) mergesort(x[0], 0, ARRAY_SIZE-1);
			else
				for(int i=0; i<100; ++i)
					mergesort(x[i], 0, ARRAY_SIZE-1);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		case 's':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) shellsort(x[0], ARRAY_SIZE);
			else
				for(int i=0; i<100; ++i)
					shellsort(x[i], ARRAY_SIZE);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		case 'i':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) Hybrid_Introspective_Sort(x[0], ARRAY_SIZE);
			else
				for(int i=0; i<100; ++i)
					Hybrid_Introspective_Sort(x[i], ARRAY_SIZE);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		case 'b':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) bubblesort(x[0], ARRAY_SIZE);
			else
				for(int i=0; i<100; ++i)
					bubblesort(x[i], ARRAY_SIZE);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		case 'z':
		{
			isSorted(x[0], ARRAY_SIZE);
			time_t start = clock();
			if(onearray) quicksortmid(x[0], 0, ARRAY_SIZE);
			else
				for(int i=0; i<100; ++i)
					quicksortmid(x[i], 0, ARRAY_SIZE);
			time_t stop = clock();
			timeMeasure(start, stop);
			isSorted(x[0], ARRAY_SIZE);
		}
		break;
		default:
		break;
	}


	if(displaysamplelist) displayArray(x[0], ARRAY_SIZE);
	return 0;
}


void timeMeasure(time_t beginning, time_t ending){
    std::cout << "\nCZAS WYKONANIA: " << (ending-beginning)/(CLOCKS_PER_SEC/1000) << "\n";
}
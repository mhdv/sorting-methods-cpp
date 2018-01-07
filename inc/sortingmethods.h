#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H
#include <cmath>


// stala definiujaca wielkosc tablic
static int ARRAY_SIZE = 1000000;



//####################################################
// SORTOWANIE QUICKSORT Z PIVOTEM LOSOWYM
//####################################################

template <typename T>
void quicksort(T *arr, int left, int right){

	// zadeklarowanie zmiennych
    int l = left;
    int r = right - 1;
    int size = right - left;
    T temp;

    // warunek wykonania sortowania (wiecej niz jeden element)
    if (size > 1){
        T pivot = arr[rand() % size + l];			// ustawienie pivota jako losowego elementu tablicy
        while (l < r){								// petla wykonujaca sie dopoki index prawy > index lewy
            while (arr[r] > pivot && r > l){		// petla dla prawego elementu
                r--;
            }
            while (arr[l] < pivot && l <= r){		// petla dla lewego elementu
                l++;
            }
            if (l < r) {							// warunek wykonania zamiany elementow
                // std::swap(arr[l], arr[r]);
                temp = arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
                l++;
			}
        }

        // rekurencyjne wywolywanie quicksort'a dla otrzymanych granic r oraz l
        quicksort(arr, left, l);
        quicksort(arr, r, right);
    }
}

//####################################################
// SORTOWANIE QUICKSORT Z PIVOTEM PO SRODKU
//####################################################

template <typename T>
void quicksortmid(T *arr, int left, int right){

	// zadeklarowanie zmiennych
    int l = left;
    int r = right - 1;
    int size = right - left;
    T temp;

    // warunek wykonania sortowania (wiecej niz jeden element)
    if (size > 1){
        T pivot = arr[(size/2)+left];			// ustawienie pivota jako losowego elementu tablicy
        while (l < r){								// petla wykonujaca sie dopoki index prawy > index lewy
            while (arr[r] > pivot && r > l){		// petla dla prawego elementu
                r--;
            }
            while (arr[l] < pivot && l <= r){		// petla dla lewego elementu
                l++;
            }
            if (l < r) {							// warunek wykonania zamiany elementow
                // std::swap(array[l], array[r]);
                temp = arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
                l++;
			}
        }

        // rekurencyjne wywolywanie quicksort'a dla otrzymanych granic r oraz l
        quicksortmid(arr, left, l);
        quicksortmid(arr, r, right);
    }
}

// #############################################
// SORTOWANIE PRZEZ SCALANIE
// #############################################

// funkcja scalajaca merge
template <typename T>
void merge(T *arr, int left, int mid, int right){

	static T *tmp = new T[ARRAY_SIZE]; // tablica tymczasowa/pomocnicza
	int l = left;				// przypisanie wartosci lewego elementu i srodkowego
	int m = mid + 1;			// do zmiennych, dla uproszczenia kodu
 
	for(int k = left; k<=right; ++k) // kopiowanie do tablicy tymczasowej
		tmp[k] = arr[k];  

	for(int k=left; k<=right; ++k){	// scalanie tablic tymczasowych 
		if(l<=mid){
			if(m <= right){
				if(tmp[m]<tmp[l]){
					arr[k] = tmp[m++];
				}
				else
					arr[k] = tmp[l++];
			}
			else
				arr[k] = tmp[l++];
		}
		else
			arr[k] = tmp[m++];
	}
}

// sortowanie przez scalanie - funkcja rekurencyjna
template <typename T>
void mergesort(T *arr,int left, int right){

	if(right<=left) return; // warunek konca rekurencji

	int mid = (right+left)/2; // srodek podtablicy

	//dzielenie rekurencyjnie tablicy na dwie czesci
	mergesort(arr, left, mid); 
	mergesort(arr, mid+1, right);

	merge(arr, left, mid, right); // scalenie tablic
}

//#########################################################
// SORTOWANIE SHELLA
//#########################################################

template <typename T>
void shellsort(T *arr, int size){

    int gap;		// deklaracja tzw. gap'a oraz zmiennej tymczasowej
    T temp;

    for (gap = size/2; gap > 0; gap /= 2)	// gap poczatkowy to polowa rozmiaru, potem dzielony na pol, dopoki > 0
        for (int i = gap; i < size; ++i)	// dla otrzymanego powyzej gap'a, petla wykonujaca sie size-gap razy
            for (int j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap) {
                //std::swap(arr[j], arr[j+gap]);
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
}

//########################################################
// SORTOWANIE INTROSPEKTYWNE
//########################################################

template <typename T>
int partition(T *arr, int left, int right){

	int x = arr[left];
	int i = left, j = right;
	T w;

	while (true){
		while (arr[j] > x)
			j--;
		while (arr[i] < x)
			i++;
		if (i < j){
			w = arr[i];
			arr[i] = arr[j];
			arr[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}

template <class Item>
void IntroSort (Item *Array, int N, int M)
{
  long i;
  if (M<=0)
  {
    mergesort(Array,0,N);
    return;
  }
  i=partition(Array,0,N);
  if (i>9)
    IntroSort(Array,i,M-1);
  if (N-1-i>9)
    IntroSort(Array+i+1,N-1-i,M-1);
}

template <class Item>
void Hybrid_Introspective_Sort (Item *Array, int N)
{
  IntroSort(Array,N,(int)floor(2*log(N)/M_LN2));
  mergesort(Array,0,N);
}

//##################################################
// SORTOWANIE BABELKOWE
//##################################################

template <typename T>
void bubblesort(T* arr, int size){
	for(int i=1; i<size; i++){
		for(int j=size-1; j>=1; j--){
			if(arr[j]<arr[j-1]){
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


#endif
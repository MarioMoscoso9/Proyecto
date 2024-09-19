#ifndef ORD_H_
#define ORD_H_
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> mergeSort(const std::vector<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for( int i= low; i <= high; i++){
		A[i] = B[i];
	}

}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {

	//El índice de B que va a contener los valores ordenados
	int i_ordenado = low;

	//El índice de la primera mitad
	int i_izquierda = low;

	//El índice de la segunda mitad
	int i_derecha = mid + 1;

	//Ordena ambas mitades
	while (i_izquierda <= mid && i_derecha <= high) {
		
		if(A[i_izquierda] <= A[i_derecha]) {
			B[i_ordenado] = A[i_izquierda];
			i_izquierda++;
		} else {
			B[i_ordenado] = A[i_derecha];
			i_derecha++;
		}

		i_ordenado++;
	}

	//Ordena lo que queda de la parte izquierda
	while (i_izquierda <= mid) {
		B[i_ordenado] = A[i_izquierda];
		i_izquierda++;
		i_ordenado++;
	}

	//Ordena lo que queda de la parte derecha
	while (i_derecha <= high) {
		B[i_ordenado] = A[i_derecha];
		i_derecha++;
		i_ordenado++;
	}

	//Copia B que ya está ordenado, en A que no está ordenado
	copyArray(A, B, low, high);
	
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	//caso base
	if(low < high){

		int mitad = (high + low)/2;
		//primera mitad
		mergeSplit(A,B, low, mitad);
		// segunda mitad
		mergeSplit(A,B,mitad+1, high);
		// ambas partes
		mergeArray(A,B, low, mitad, high);
		copyArray(A,B,low, high);



	}
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size()-1);

	return v;
}

#endif
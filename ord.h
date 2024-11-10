// Mario Armando Moscoso Becerra A01712209
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
public:
	std::vector<T> insertionSort(const std::vector<T>&);
};

template <class T>
// Intercambia dos elementos en un std::vector.
// Complejidad: O(1) en el mejor, peor y caso promedio.
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
// Copia una parte de un arreglo B en otro arreglo A, entre los índices low y high.
// Complejidad: O(n) en el mejor, peor y caso promedio, ya que siempre se lleva a cabo el ciclo y depende de su tamaño.
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
// Fusiona dos mitades de un arreglo A en otro arreglo B, manteniendo el orden.
// Complejidad: O(n) en el mejor, peor y caso promedio, donde de igual manera depende totalmente de su tamaño.
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i_ordenado = low;
	int i_izquierda = low;
	int i_derecha = mid + 1;

	// Fusiona ambas mitades ordenadamente
	while (i_izquierda <= mid && i_derecha <= high) {
		if (A[i_izquierda] <= A[i_derecha]) {
			B[i_ordenado] = A[i_izquierda];
			i_izquierda++;
		} else {
			B[i_ordenado] = A[i_derecha];
			i_derecha++;
		}
		i_ordenado++;
	}

	// Copia los elementos restantes de la parte izquierda
	while (i_izquierda <= mid) {
		B[i_ordenado] = A[i_izquierda];
		i_izquierda++;
		i_ordenado++;
	}

	// Copia los elementos restantes de la parte derecha
	while (i_derecha <= high) {
		B[i_ordenado] = A[i_derecha];
		i_derecha++;
		i_ordenado++;
	}

	// Copia B que ya está ordenado en A
	copyArray(A, B, low, high);
}

template <class T>
// Divide recursivamente el arreglo en mitades hasta llegar a subarreglos de tamaño 1,
// y luego utiliza mergeArray para fusionar las mitades ordenadas.
// Complejidad:  Cada nivel de recursión requiere 𝑂(𝑛) operaciones para fusionar, y hay log n niveles de 
// recursión, lo que da una complejidad total de 𝑂(𝑛log⁡𝑛) en el mejor, peor y caso promedio.
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	if (low < high) {
		int mitad = (high + low) / 2;
		// Primera mitad
		mergeSplit(A, B, low, mitad);
		// Segunda mitad
		mergeSplit(A, B, mitad + 1, high);
		// Fusiona ambas partes
		mergeArray(A, B, low, mitad, high);
		copyArray(A, B, low, high);
	}
}

template <class T>
// Ordena el arreglo usando el método Merge Sort.
// Complejidad: O(n log n) en el mejor, peor y caso promedio ya que mantiene 
// esta misma complejidad en todos los casos porque divide y fusiona de forma constante.
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	return v;
}

#endif

#ifndef ORD_H_
#define ORD_H_
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
public:
	std::vector<T> insertionSort(const std::vector<T>&);

};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int i= 0; i < v.size(); i++){
		for (int j=i; v[j]< v[j-1] && j >0; j--){
			swap(v,j,j-1);
		
		}
	}
	

	return v;
}








#endif
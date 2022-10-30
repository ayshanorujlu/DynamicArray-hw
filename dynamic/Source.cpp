#include<iostream>
using namespace std;
template<class T>
class DynamicArray {
	T* arr = nullptr;
	int size = 0;
public:
	DynamicArray() = default;

	DynamicArray(const DynamicArray& da) {
		if (da.size == 0) {
			arr = nullptr;
			size = 0;
			return;
		}
		arr = new T[da.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = da.arr[i];
		}
	}

	DynamicArray& operator=(const DynamicArray& da) {
		delete[]arr;
		if (da.size == 0) {
			arr = nullptr;
			size = 0;
			return*this;
		}

		arr = new T[da.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = da.arr[i];
		}
		return*this;
	}

	T& operator[](int index) {
		assert(size > 0);
		return arr[index];
	}

	void AddElementToEnd(T value) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}temp[size] = value;
		delete[]arr;
		size++;
		arr = temp;
		temp = nullptr;
	}
	void AddElementToHead(T value) {
		T* temp = new T[sizze + 1];
		temp[0] = value;
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[]arr;
		size++;
		arr = temp;
		temp = nullptr;
	}
	void AddElementByIndex(T value) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = value;
		for (int i = 0; i < size; i++)
		{
			temp[i+1] = arr[i];
		}
		delete[]arr;
		size++;
		arr = temp;
		temp = nullptr;
	}

	friend ostream& operator<<(ostream& out, const DynamicArray& obj) {
		for (int i = 0; i < size; i++)
		{
			out << arr[i] << " ";
		}
		out << endl;
		return out;
	}
};

void main() {
	DynamicArray<int>arr;
	arr.AddElementToHead(1);
	arr.AddElementToHead(12);
	arr.AddElementToEnd(13412);
	arr.AddElementToHead(142);

	cout << arr;
}


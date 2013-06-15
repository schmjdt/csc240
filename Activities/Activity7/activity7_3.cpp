#include<iostream>

using namespace std;

class DynamicArray {
private:
	int array_size;
	int *user_array;

public:
	DynamicArray(void) {
		array_size = 1;
		user_array = new int[array_size];
	}

	DynamicArray(int n) {
		array_size = n;
		user_array = new int[array_size];
	}

	void printArray(void);
	void fillArray(void);

	~DynamicArray(void) {
		delete user_array;
		user_array = NULL;
	}
};

void DynamicArray::printArray(void) {
	int ii;
	cout << "Print The Array" << endl;
	for (int ii = 0; ii < array_size; ii++) {
		cout << user_array[ii] << endl;
	}
} 

void DynamicArray::fillArray(void) {
	int i;
	cout << "Fill The Array" << endl;
	for (i = 0; i < array_size; i++) {
		user_array[i] = i+1;
	}
}

int main() {
	DynamicArray MyArray, MyArray2(5);

	MyArray.fillArray();
	MyArray.printArray();
	cout << endl;
	MyArray2.fillArray();
	MyArray2.printArray();
	cout << "Done" << endl;
}

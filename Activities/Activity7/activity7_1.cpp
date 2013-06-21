#include<iostream>

using namespace std;

int main() {
	static int intStatic = 1, intStatic2 = 1, intStatic3 = 1;
	int intStack = 2, intStack2 = 2, intStack3 = 2;
	int *intHeap, *intHeap2, *intHeap3;

	intHeap = new int(3);
	intHeap2 = new int(3);
	intHeap3 = new int(3);

	cout << "Static1 Addr: " << &intStatic << endl;
	cout << "Static2 Addr: " << &intStatic2 << endl;
	cout << "Static3 Addr: " << &intStatic3 << endl;
	cout << "Stack   Addr: " << &intStack << endl;
	cout << "Stack2  Addr: " << &intStack2 << endl;
	cout << "Stack3  Addr: " << &intStack3 << endl;
	cout << "Heap    Addr: " << intHeap << endl;
	cout << "Heap2   Addr: " << intHeap2 << endl;
	cout << "Heap3   Addr: " << intHeap3 << endl;


	delete intHeap, intHeap2, intHeap3;
	intHeap = intHeap2 = intHeap3 = NULL;
	cout << "Done" << endl;
	return 0;
}

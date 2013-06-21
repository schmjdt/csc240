#include<iostream>
using namespace std;

class MyClass {
public:
    int DoubleNumber(int number);

};
int MyClass::DoubleNumber(int number) {
    return number*2;
}

int main() {
	MyClass mine();
	int i = 5;
	int n = mine.DoubleNumber(10);
	cout << i << " doubled = " << n << endl;

	return 0;
}

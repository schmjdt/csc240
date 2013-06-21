#include<iostream>
using namespace std;

class Animal {
public:
 virtual void speak() = 0;
 //void speak() { cout << "Hello\n"; }
};

class Dog : public Animal {
public:
 void speak() { cout << "Woof\n"; }
};

class Lion : public Animal {
public:
 void speak() { cout << "Roar\n"; }
};

class Snake : public Animal {
public:
 void speak() { cout << "Ssss\n"; }
};

int main()
{
	Animal *a1, *a2;

	Dog rover;
	Lion Leo;
	Snake Plissken;

        a2 = &rover;
	a2->speak();

}
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

class Narwhal : public Animal {
public:
 void speak() { cout << "It's not a f*#$! horn\n"; }
};

int main()
{
	Animal *a1, *a2;
	int ii;

	Dog rover;
	Lion Leo;
	Snake Plissken;
	Narwhal Buddy;

        a2 = &rover;
	a2->speak();

	//a[0] = &rover; a[1] = &Leo; a[2] = &Plissken; a[3] = &Buddy;
	Animal *an[] = {&rover, &Leo, &Plissken, &Buddy};
	int numAnimals = 4;

	for (ii = 0; ii < numAnimals; ii++) {
		an[ii]->speak();
	} 

}

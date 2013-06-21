#include<iostream>
using namespace std;


class Animal {
protected: 
	string type;
public:
 virtual void speak() = 0;
 virtual void SetType(string value) { type = value; }
 virtual string GetType() { return type; }
 //void speak() { cout << "Hello\n"; }
};

class Dog : public Animal {
public:
 Dog() { SetType("dog"); }
 void speak() { cout << "Woof\n"; }
};

class Lion : public Animal {
public:
 Lion() { SetType("lion"); }
 void speak() { cout << "Roar\n"; }
};

class Snake : public Animal {
public:
 Snake() { SetType("snake"); }
 void speak() { cout << "Ssss\n"; }
};

class Narwhal : public Animal {
public:
 Narwhal() { SetType("narwhal"); }
 void speak() { cout << "It's not a f*#$! horn\n"; }
};

int main()
{
	const int numAnimals = 4;
	Animal *a1, *a2, *an[numAnimals];
	int ii;

	Dog rover;
	Lion Leo;
	Snake Plissken;
	Narwhal Buddy;
	
	an[0] = &rover; an[1] = &Leo; an[2] = &Plissken; an[3] = &Buddy;
	
	for (ii = 0; ii < numAnimals; ii++) {
		cout << "a " << an[ii]->GetType() << " goes ";
		an[ii]->speak();
	} 
}

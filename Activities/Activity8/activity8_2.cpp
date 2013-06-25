#include<iostream>
using namespace std;

#define PI 3.14

class Shape {
private:
	int dimensions, sides;
	string name, color;

protected:
	double volume, surfaceArea;

public:
	Shape(int value1 = 1, int value2 = 1) {
		dimensions 	= value1;
		sides 	= value2;
		color 		= "white";
	}	
		
	int GetDimensions(void) 	{ return dimensions; 	}
	int GetSides(void) 		{ return sides; 		}
	double getVolume(void) 	{ return volume; 	}
	double getSurfaceArea(void){ return surfaceArea;	}
	string GetName(void) 		{ return name; 		}
	string GetColor(void) 		{ return color; 		}

	void SetDimensions(int value) 	{ dimensions 	= value; 	}
	void SetSides(int value) 		{ sides 		= value; 	}
	void SetName(string value) 		{ name 		= value;	}
	void SetColor(string value) 		{ color 		= value; 	}
	
	virtual void CalcVolume() 		= 0;
	virtual void CalcSurfaceArea() 	= 0;
	virtual void DisplayShape() 		= 0;
	void ShapeInfo();
};
void Shape::ShapeInfo() {
	cout << "Name: " 	<< name 		<< endl;
	cout << "Dimensions: " << dimensions 	<< endl;
	cout << "Sides: " 	<< sides 		<< endl;
	cout << "Color: " 	<< color 		<< endl;
}

class Sphere : public Shape {
private:
	double radius, circumference;

public:
	Sphere(double value = 1) : Shape(3, 1) {
		SetName("Sphere");
		radius = value;
		CalcSurfaceArea();
		CalcVolume();
		CalcCircumference();
	}

	void CalcVolume();
	void CalcSurfaceArea();
	void CalcCircumference(); 

	void DisplayShape();
};
void Sphere :: CalcVolume() 			{ volume 		= (surfaceArea / 3); 		} 
void Sphere :: CalcSurfaceArea() 		{ surfaceArea 	= (4 * PI * radius * radius); 	}
void Sphere :: CalcCircumference() 	{ circumference 	= (2 * PI * radius); 		}
void Sphere :: DisplayShape() {
	ShapeInfo();
	cout << "Radius: " 		<< radius 			<< endl;
	cout << "Volume: " 		<< volume 		<< endl;
	cout << "Surface Area: " 	<< surfaceArea 		<< endl;
	cout << "Circumference: " 	<< circumference	<< endl;
}

class Cube : public Shape {
private:
	double length;

public:
	Cube(double value = 1) : Shape(3, 6) {
		SetName("Cube");
		length = value;
		CalcSurfaceArea();
		CalcVolume();
	}

	void CalcVolume();
	void CalcSurfaceArea();

	void DisplayShape();
};
void Cube :: CalcVolume()		{ volume 		= (length * length * length); }
void Cube :: CalcSurfaceArea()	{ surfaceArea 	= (6 * length * length); 	}
void Cube :: DisplayShape() 		{
	ShapeInfo();
	cout << "Length: " 		<< length 		<< endl;
	cout << "Volume: " 		<< volume 	<< endl;
	cout << "Surface Area: " 	<< surfaceArea 	<< endl;
}


int main() {
	Sphere mySphere(2);
	Cube myCube(2);
	Shape *myShapes[] = {&mySphere, &myCube};
	const int numShapes = 2;
	
	myCube.SetColor("blue");

	for (int ii = 0; ii < numShapes; ii++) {
		myShapes[ii]->DisplayShape();
		cout << endl;
	}
	
	return 0;
}


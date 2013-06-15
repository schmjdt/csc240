#include<iostream>

using namespace std;

int global = 0;

void use_static() {
	int local = 0;
	static int mystatic = 0;

	if (mystatic == 0) 
		cout << "Local = " << &local << " Static = " << &mystatic <<  " Global = " << &global << endl;

	local++;
	mystatic++;
	global++;

	cout << "Local = " << local << " Static = " << mystatic <<  " Global = " << global << endl;
}

int main()
{
	int ii;

	for (ii = 0; ii<10; ii++) {
		use_static();
		global++;
		//mystatic++;  // Out of scope
	}
}

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString array2("ARRAY PLACEHOLDER");
	char a = 'A';
	MyString array("Pisor");
	//cout << array2.MyStrCmp(array) << endl;
	//cout << array.GetCount() << endl;
	//MyString array3 = 'b' + array;
	//array.Print();
	//array3.Print();
	//MyString array4 = array + 10;
	////MyString array4 = 10 + array; второй вариант
	//array4.Print();
	array.Print();
	array++;
	array.Print();
}
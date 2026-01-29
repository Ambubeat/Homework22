#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString array2("ARRAY PLACEHOLDER");
	array2.Print();
	MyString array("Pisor");
	MyString copyArray = move(array2);
	copyArray.Print();
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

	//MyString s1("Hello");
	//MyString s2("World");
	//cout << "s1: " << s1 << endl;
	//cout << "s2: " << s2 << endl;

	//cout << "Enter new word: ";
	//cin >> s1;
	//cout << "sq " << s1 << std::endl;

	MyString s1("Apple");
	cout << "create s2 from s1: " << endl;
	MyString s2 = std::move(s1);

	std::cout << "s2: " << s2 << std::endl;

	MyString s3("Banana");
	std::cout << "Steal s3 = move(s2)..." << std::endl;
	s3 = std::move(s2);
	std::cout << "s3: " << s3 << std::endl;
}
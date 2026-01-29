#include <iostream>
#include <cstdlib>
#include "MyString.h"
using namespace std;

MyString::MyString() : ptr(nullptr), size(80)
{
	count++;
}
MyString::MyString(int set_size)
{
	size = set_size;
	ptr = new char[size+1];
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = rand();
	}
	ptr[size] = '\0';
	count++;
}
void MyString::Print() const
{
	if (ptr == nullptr) {
		cout << "Object is empty" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i];
	}
	cout << endl;
}

MyString::MyString(const char* array)
{
	size_t newLength = strlen(array) + 1;
	size = newLength;
	ptr = new char[newLength];
	strcpy_s(ptr, newLength, array);
	count++;
}

MyString::~MyString() {
	delete[] ptr;
	cout << "Destruction" << endl;
	count--;
}

void MyString::Input()
{
	char buffer[1000];
	cout << "Enter string: ";
	cin.getline(buffer, 1000);

	delete[] ptr;

	size = strlen(buffer) + 1;
	ptr = new char[size];
	strcpy_s(ptr, size, buffer);
}

MyString::MyString(const MyString& other)
{
	this->size = other.size;

	if (other.ptr != nullptr) {
		size_t newLength = strlen(other.ptr) + 1;
		ptr = new char[newLength];
		strcpy_s(ptr, newLength, other.ptr);
	}
	else {
		ptr = nullptr;
	}
}

bool MyString::MyStrStr(const char* str)
{
	if (ptr == nullptr || str == nullptr) return false;
	if (str[0] == '\0') return true;

	for (int i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] == str[0])
		{
			int j = 0;
			while (str[j] != '\0' && ptr[i + j] != '\0' && ptr[i + j] == str[j])
			{
				j++;
			}
			if (str[j] == '\0')
			{
				return true;
			}
		}
	}
	return false;
}

int MyString::MyChr(char c)
{
	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	return size;
}

void MyString::MyStrCat(MyString& b)
{
	int newSize = this->size + b.size;
	char* newPtr = new char[newSize + 1];

	if (ptr != nullptr) {
		memcpy(newPtr, ptr, size);
	}
	if (b.ptr != nullptr) {
		memcpy(newPtr + size, b.ptr, b.size);
	}

	newPtr[newSize] = '\0';

	delete[] ptr;
	ptr = newPtr;
	size = newSize;
}

int MyString::MyStrCmp(MyString& b)
{
	if (size > b.size) {
		return 1;
	}
	else if (size < b.size) {
		return -1;
	}
	else {
		return 0;
	}
}

void MyString::MyDelChr(char c)
{
	if (ptr == nullptr) return;

	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] != c)
		{
			ptr[j] = ptr[i];
			j++;
		}
	}

	size = j;  
	ptr[size] = '\0';
}
int MyString::count = 0;


int MyString::GetCount() {
	return count;
}

int MyString::GetSize() const
{
	return size;
}

char* MyString::GetArray() 
{
	return ptr;
}

void MyString::SetSize(int set)
{
	this->size = set;
}

void MyString::UpdateData(const char* newData, int newSize)
{
	if (this->ptr != nullptr) {
		delete[] this->ptr;
	}

	this->size = newSize;

	this->ptr = new char[this->size + 1];

	for (int i = 0; i < this->size; i++) {
		this->ptr[i] = newData[i];
	}

	this->ptr[this->size] = '\0';
}

MyString::MyString(MyString&& other) noexcept {
	this->ptr = other.ptr;  
	this->size = other.size;

	other.ptr = nullptr; 
	other.size = 0;          
}



char MyString::operator[](int index) const {
	if (index >= 0 && index < size) {
		return ptr[index];
	}
	return '\0';
}
void MyString::operator()() {
	char buffer[1000];
	std::cout << "Enter string: ";
	std::cin.getline(buffer, 1000);

	delete[] ptr;

	size = (int)strlen(buffer);
	ptr = new char[size + 1];
	strcpy_s(ptr, size + 1, buffer);
}

MyString MyString::operator+(char c)
{
	int newSize = this->size + 1;

	MyString temp(newSize);

	for (int i = 0; i < this->size; i++) {
		temp.ptr[i] = this->ptr[i];
	}

	temp.ptr[this->size] = c;

	temp.ptr[newSize] = '\0';

	temp.size = newSize;

	return temp;

}

MyString MyString::operator+(int c)
{
	int newSize = size + c;

	MyString temp(newSize);

	for (int i = 0; i < this->size; i++) {
		temp.ptr[i] = this->ptr[i];
	}

	for (int i = 0; i < c; i++) {
		temp.ptr[size + i] = '!';
	}

	temp.ptr[newSize] = '\0';

	temp.SetSize(newSize);
	return temp;
}

MyString operator+(char c, MyString obj)
{
	int newSize = obj.GetSize() + 1;

	MyString temp(newSize);
	temp.GetArray()[0] = c;

	for (int i = 0; i < obj.GetSize(); i++) {
		temp.GetArray()[i + 1] = obj.GetArray()[i];
	}

	temp.GetArray()[newSize] = '\0';

	temp.SetSize(newSize);

	return temp;
}

MyString operator+(int c, MyString obj)
{

	int newSize = obj.GetSize() + c;

	MyString temp(newSize);

	for (int i = 0; i < obj.GetSize(); i++) {
		temp.GetArray()[i] = obj.GetArray()[i];
	}

	for (int i = 0; i < c; i++) {
		temp.GetArray()[obj.GetSize() + i] = '!'; 
	}

	temp.GetArray()[newSize] = '\0';

	temp.SetSize(newSize);
	return temp;



}

MyString operator++(MyString& obj, int)
{

		MyString oldState = obj;

		int newSize = obj.GetSize() + 1;
		char* newData = new char[newSize + 1]; 

		for (int i = 0; i < obj.GetSize(); i++) {
			newData[i] = obj.GetArray()[i];
		}
		newData[obj.GetSize()] = '!';
		newData[newSize] = '\0';

		obj.UpdateData(newData, newSize);

		return oldState;

}

std::ostream& operator<<(std::ostream& os, MyString& obj) {
	const char* data = obj.GetArray();
	if (data) {
		os << data;
	}
	return os;
}

std::istream& operator>>(std::istream& is, MyString& obj) {
	char buffer[1024];
	if (is >> buffer) {
		obj.UpdateData(buffer, (int)strlen(buffer));
	}
	return is;
}

MyString& MyString::operator=(MyString&& other) noexcept {
	if (this == &other) return *this;

	delete[] ptr;

	this->ptr = other.ptr;
	this->size = other.size;

	other.ptr = nullptr;
	other.size = 0;

	return *this;
}
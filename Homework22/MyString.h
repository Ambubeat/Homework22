#pragma once

class MyString {
	char* ptr;
	int size;
	static int count;
public:
	MyString();
	MyString(int set_size);
	void Print() const;
	MyString(const char* array);
	~MyString();
	void Input();
	MyString(const MyString& other);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	int MyStrCmp(MyString& b);
	void MyDelChr(char c);
	int GetCount();
	int GetSize() const;
	char* GetArray();
	void SetSize(int set);
	void UpdateData(const char* newData, int newSize);

	//operands
	char operator[](int index) const;
	void operator()();
	MyString operator+(char c);
	//MyString operator+(char );
	MyString operator+(int c);
};

MyString operator+(char c, const MyString obj);
MyString operator+(int c, const MyString obj);
MyString operator++(MyString& obj, int);
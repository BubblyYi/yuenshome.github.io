#include <iostream>
#include <cassert>
using namespace std;

class T {
public:
	T(int i = 0) :data(i) { cout << "T����\n"; }
	~T() { cout << "T����\n"; }
	void show()const { cout << data << endl; }
private:
	int data;
};

class SmartPointer {
public:
	SmartPointer(T* p = nullptr) :ptr(p) { }
	~SmartPointer() { delete ptr; }
	T& operator*() {
		assert(ptr);
		return *ptr;
	}
	T* operator->() {
		assert(ptr);
		return ptr;
	}
	operator bool()const {return ptr != nullptr;}
private:
	T * ptr;
};

int main() {
	T* p1 = new T(2);
	(*p1).show();
	p1->show();
	if (p1) cout << "p1 ok\n";
	delete p1;

	SmartPointer pd(new T(1));
	(*pd).show(); // *�����ò���
	pd->show();   // ->����
	if (pd) cout << "pd ok\n";
	return 0;
}
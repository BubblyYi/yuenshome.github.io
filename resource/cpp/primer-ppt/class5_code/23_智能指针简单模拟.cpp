#include <iostream>
using namespace std;

class T {
public:
	T(int i = 0) :data(i) { cout << "T����\n"; }
	~T() { cout << "T����\n"; }
private:
	int data;
};

class SmartPointer {
public:
	SmartPointer(T* p = nullptr) :ptr(p) { }
	~SmartPointer() { delete ptr; }
private:
	T * ptr;
};

int main() {
	T * pt1 = new T(1);
	SmartPointer spt1(pt1);
	T * pt2 = new T(2);
	SmartPointer spt2 = pt2;
	//��������ʱ��pt1,pt2��������� T ���󶼻�����
	cout << "------\n";
	return 0;
}
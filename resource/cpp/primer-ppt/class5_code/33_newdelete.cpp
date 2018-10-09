#include <iostream>
#include <cstdlib>
using namespace std;
void* operator new(std::size_t size) {
	if (void * p = malloc(size)) {
		cout << "my operator new\n";
		return p;
	}
	throw bad_alloc();
}
void operator delete(void* p) {
	cout << "my operator delete\n";
	free(p);
}
class A {
public:
	A(int i=0) :pi(new int(i)) {cout << "A����\n";}
	~A() { cout << "A������\n"; delete pi;  }
	//��ʽ��̬��Ա����
	/*static*/void* operator new(std::size_t size){
		if (void * p = malloc(size)) {
			cout << "A operator new\n"; 
		return p; 
		}
		throw bad_alloc(); //�����ڴ�ʧ�����쳣
	}
	/*static*/ void operator delete(void* p) {
		cout << "A operator delete\n";
		free(p);
	}
private:
	int* pi;
};
int main() {
	int *pi = new int(0);
	cout << "-----------------\n";
	delete pi;
	cout << "=================\n";
	A *pa = new A(1);
	cout << "-----------------\n";
	delete pa;
	return 0;	
}
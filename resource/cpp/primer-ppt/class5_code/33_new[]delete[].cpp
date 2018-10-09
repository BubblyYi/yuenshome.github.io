#include <iostream>
#include <cstdlib>
using namespace std;
class A {
public:
	A(int i=0) :pi(new int(i)) {cout << "A����\n";}
	~A() { cout << "A������\n"; delete pi;  }
	//��ʽ��̬��Ա����
	/*static*/void* operator new[](std::size_t size){
		if (void * p = malloc(size)) {
			cout << "-A operator new[]\n"; 
			return p; 
		}
		throw bad_alloc(); //�����ڴ�ʧ�����쳣
	}
	/*static*/ void operator delete[](void* p) {
		cout << "A operator delete[]\n";
		free(p);
	}
private:
	int* pi;
};
int main() {
	A *pa = new A[3];
	cout << "-----------------\n";
	delete[] pa;
	return 0;	
}
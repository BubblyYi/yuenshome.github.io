#include <iostream>
using namespace std;
struct Base {
	void f() { cout << "Base f()" << endl; }
};
struct D1: Base  {
	void f(int i) { cout<<"D1 f(int)"<<endl; }
};
int main() {
	Base b1;
	b1.f(); // Base f()
	//b1.f(1); //��,Base����û�� f(int)����
	D1 d1;
	d1.f(10); // D1 f(int)
	//d1.f(); //��,Base�̳�������f()������(shadow)
	d1.Base::f(); //Ҫ����Base��f(),Ҫ��Base::
	return 0;
}
#include <iostream>
using namespace std;
class A {
public:
	A() { cout << "A����\n"; }
	~A() noexcept(false) {
		throw 1; cout << "A����\n"; 
	} //�������������쳣����
};
void f() {
	A a1;
	A a2;
	throw 2;
}
int main() {
	try { f(); }
	catch (...) { }
	return 0;
}
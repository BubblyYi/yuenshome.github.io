#include <iostream>
using namespace std;
namespace A {
	void f1(int a, int b) {}
}
namespace B {
	void f1(int a) {}
}
using namespace A;
using namespace B;
int main() {
	//A�е�f1��B�е�f1����������?
	f1(10);
	f1(10, 20);
	return 0;
}


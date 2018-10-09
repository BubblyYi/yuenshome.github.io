#include <iostream>
#include <vector>
using namespace std;
class B {};
class A{
public:
	A(int i=0):data(i){ }					//int -> A   
	explicit A(const B&) { /*...*/ }		//B -->  A   
	operator int()const { return data; }    //A -->int  
	explicit operator B()const{return B();} //A -->  B 
	operator bool()const {	return data; }  //A --> bool
private:
	int data;
};

int main() {
	//1.1 û��explicit���εĹ��캯��,�������� ==> ��������
	A a1(1);   // int -> A
	A a2 = 2;  // int -> A
	//1.2 ��explicit���εĹ��캯��,�������� ==> ��������
	B b;
	A a3(b);   // B -> A
	//A a4 = b;  //��Ϊ explicit,��ʽת������
	A a5 = static_cast<A>(b); //��ʽת��ok

	//2.1 û��explicit���ε�����ת�������, �������� ==> ��������
	A a;
	int i1(a); // A -> int 
	int i2 = a;// A -> int
	//2.2 ��explicit���ε�����ת�������, �������� ==> ��������
	A aa;
	B b1(aa);    // A -> B
	//B b2 = aa; // ��Ϊexplicit,��ʽת������
	B b3 = static_cast<B>(aa); //��ʾת��ok

	//ת��Ϊbool����
	if ( A(1) ) cout << "true\n";
	if ( !A() ) cout << "false\n";

	return 0;
}
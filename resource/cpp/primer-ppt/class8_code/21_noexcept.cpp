#include <iostream>
using namespace std;

void f1() noexcept { } //�������쳣
void f2() noexcept(true){}//�������쳣
void f3() noexcept(false) {}//�������쳣
void f4() {} //�������쳣
void f5() throw() {} //�������쳣
void f6() throw(int,double){} //ֻ����int��double���͵��쳣
void f7() noexcept { //�������쳣
	throw 1; //ʵ��������,����ok,ʵ�ʵ���std::terminate
}
void f8() noexcept {
	try { throw 1; }
	catch (int e) { cout << "�쳣����\n"; }
	//�쳣�����ˣ�ok,û���⡣
}

int main() {
	f8(); //��������
	//noexcept��������������쳣����true,�����쳣����false
	cout << noexcept(f1()) << endl; //1
	cout << noexcept(f2()) << endl; //1
	cout << noexcept(f3()) << endl; //0
	cout << noexcept(f4()) << endl; //0
	cout << noexcept(f5()) << endl; //1
	cout << noexcept(f6()) << endl; //0
	cout << noexcept(f7()) << endl; //1
	cout << noexcept(f8()) << endl; //1
	return 0;
}
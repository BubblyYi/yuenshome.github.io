#include <iostream>
using namespace std;

struct Top { int x = 1; };
struct Base : public Top { int y = 2; };
struct D1 :virtual public Base { int i = 3; };
struct D2 :virtual public Base { int j = 4; };
struct M1 :public D1, public D2 { int k = 5; };
struct Ok :public M1, public Top { int n = 6; };

int main() {
	Ok ok;
	//1.д���������
	M1 *p_m1 = &ok;
	D1 *p_d1 = &ok;
	D2 *p_d2 = &ok;
	Base *p_base = &ok;
	//Top *p_top = &d; 
	//2.����Ϊʲô����?
	//(������Top,������)
	//3.��һ��������,���Ի���������µĶ����ڴ�ͼ

	return 0;
}



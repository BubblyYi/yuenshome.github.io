#include <iostream>
using namespace std;
class Base {
public:
	void f() {
		cout << "Base f()" << endl;
		cout <<"typeid: "<<typeid(*this).name()<<endl;  //Derived
		//������һЩ�麯������ǰ��׼������
		vf();
		//������һЩ�麯�����ú���ƺ���
	}
	virtual ~Base(){}
private:
	virtual void vf() { cout<<"Base vf(): "<<i<<endl; }
	//��������������Ҫ���ø�����麯��,���Խ�Ȩ�޸�Ϊprotected/public
	int i = 100;
};
class Derived :public Base {
private:
	virtual void vf()override { cout<<"Derived vf(): "<<j<< endl;}
	int j = 200;
};
int main() {
	Derived d;
	d.f();
	cout << "---------\n";
	Base *p = &d;
	p->f();
	return 0;
}
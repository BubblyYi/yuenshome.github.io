#include <iostream>
using namespace std;
class Base {
public:
	virtual void func() = 0;
	virtual void func(double) {
		cout << "Base(double)\n";
	}
	void func(int) {
		cout << "Base(int)\n";
	}
};
class D1 : public Base {
public:
	virtual void func() override {
		cout << "D1()\n";
	}
	void func(const char*) {
		cout << "D1(const char*)\n";
	}
};
class D2 :public D1 {
public:
	using Base::func;
	void func(bool) {
		cout << "D2(bool)\n";
	}
};

int main() {
	//Base b1;				//����1������,�д��麯��,��������޷���������
	D1 d1;
	d1.func();				//����2����ȷ, D1 override��func(), �����D1()
	//d1.func(1.2);			//����3������, D1���¶�����func,shadow�˻��������func����
	//d1.func(1);			//����4������, ͬ����3
	d1.func("abc");			//����5����ȷ D1(const char*)
	D2 d2;
	d2.func();				//����6��ok,using Base::func,��Base������func����������ʵ����ӵ�D2��������D1() [ע��]
	d2.func(1.2);			//����7��ͬ����6��Base(double)
	d2.func(1);				//����8��ͬ����6��Base(int)
	d2.func("123");			//����9��ok(ע��),D1�е�func(const char*)��shadow,��ʽת��ִ��func(bool) D2(bool)
	d2.func(true);			//����10��ok D2(bool)
	cout << "--------------------------\n";
	Base *p1 = new D1;
	p1->func();				//����11���麯������,��ʵ���͵ĵ��� D1()
	p1->func(1.2);			//����12���麯������,����D1û��override Base(double)
	p1->func(1);			//����13�����麯������,��̬���͵ĵ��� Base(int)
	//p1->func("123");		//����14: ����,��̬�������Ҳ��� func(const char*)
	p1->func(true);			//����15����ʽת�� Base(int)
	D1 *p2 = new D2;
	p2->func();				//����16���麯������,��ʵ���͵ĵ��� D1() (D2û��override func(),������D1�е�)
	//p2->func(1.2);		//����17������,��̬����D1��û�� func(double),Ҳû�п�����ʽת��ƥ���
	//p2->func(1);			//����18������,ͬ��
	p2->func("123");		//����19: D1(const char*)
	//p2->func(true);		//����20������,��̬����D1��û�� func(bool),Ҳû�п�����ʽת��ƥ���
	return 0;
}

#include <iostream>
using namespace std;
class Base {
public:
	Base() { 
		cout << "Base����\n"; 
		memset(this, 0, sizeof(*this)); 
		//����ʱ,ǿ�ƽ����������������Ϊ0
	}
	void func() { cout << "Base::func()\n"; }
	virtual void show()const { cout << "Base::show()\n"; }
private:
	int b;
};
class D1 :public Base {
public:
	D1() { cout << "D1����\n"; 	}
	virtual void show()const override {
		cout << "D1::show()\n"; 
	}
private:
	int d;
};
int main() {
	Base b1;
	b1.func(); //���麯������,ok
	b1.show(); //�麯������,ok
	//�����麯������ok,����Ϊͨ����������麯��,Ҳ�Ǳ���ʱȷ����,û��ͨ���麯����
	Base *pb1 = &b1;
	pb1->func(); //���麯������,ok
	//pb1->show(); //�������,ָ���麯�����ָ�뱻�ƻ���.
	//ͨ��ָ������õ����麯��,��ʹ���麯����,����ʱȷ����
	cout << "------------\n";
	D1 d;
	Base &rd = d;
	rd.func(); //ok,���麯������
	rd.show(); //ok,D1����ʱ,�ؽ���ָ���麯�����ָ��(��ΪBase��D1���麯����ͬ)
	return 0;
}
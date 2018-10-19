#include <iostream>
using namespace std;
class USB {
public:
	virtual void connect() = 0;
	virtual void dis_connect() = 0;
	virtual ~USB() {} //������
};
class UDisk : public USB {
public:
	virtual void connect() override {
		cout << "U connect" << endl;
	}
	virtual void dis_connect() override {
		cout << "U disconnect" << endl;
	}
};
class Mouse : public USB {
public:
	virtual void connect() override {
		cout << "M connect" << endl;
	}
	virtual void dis_connect()override {
		cout << "M disconnect" << endl;
	}
};
class Keyboard : public USB {
public:
	virtual void connect() override {
		cout << "K connect" << endl;
	}
	virtual void dis_connect() override {
		cout << "K disconnect" << endl;
	}
};
//void testU(UDisk *u){
//	u->connect();
//	u->dis_connect();
//}
//void testM(Mouse *m){
//	m->connect();
//	m->dis_connect();
//}
//void testK(Keyboard *k){
//	k->connect();
//	k->dis_connect();
//}

//������������Ϊ����������͵�ָ��
//�ɽ���������ָ��
//���ö�̬����ʵ�����͵�����Ӧ�ķ���
//����������Ĵ���
void test(USB *u) {
	u->connect();
	u->dis_connect();
}
int main() {
	UDisk *u = new UDisk;
	Mouse *m = new Mouse;
	Keyboard *k = new Keyboard;
	test(u); test(m); test(k);
	delete u; delete m;	delete k;
	cout << "----------------\n";
	USB *u1 = new UDisk;
	USB *m1 = new Mouse;
	USB *k1 = new Keyboard;
	test(u1); test(m1); test(k1);
	delete u1; delete m1; delete k1;
	return 0;
}

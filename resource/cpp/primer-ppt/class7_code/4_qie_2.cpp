#include <iostream>
using namespace std;
class Bird {
public:
	void eat() { cout << "��Զ���" << endl; }
};
class FlyingBird :public Bird {
public:
	void fly() { cout << "�����" << endl; }
};
class Qie :public Bird { //is-a
public:
	//somecode...
};
int main() {
	Qie q;
	//��첻��ɣ�����Ҳ���ܵ��ã�ok
	//q.fly(); //û��fly����
	//������ɵ��� ���� public�̳� FlyingBird
	return 0;
}
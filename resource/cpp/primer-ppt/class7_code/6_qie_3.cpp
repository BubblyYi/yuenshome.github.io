#include <iostream>
using namespace std;
class Bird {
public:
	void eat() { cout << "��Զ���" << endl; }
	void fly() { cout << "�����" << endl; }
};
class Qie { //����Birdʵ�ֳ�
public:
	void eat() { bird.eat(); }
private:
	Bird bird;
};
int main() {
	Qie q;
	q.eat();
	//q.fly(); //����
	return 0;
}
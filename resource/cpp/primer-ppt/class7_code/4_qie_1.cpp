#include <iostream>
using namespace std;
class Bird {
public:
	void eat() { cout << "��Զ���" << endl; }
	void fly() { cout << "�����" << endl; }
};
class Qie :public Bird { //is-a
public:
	//somecode...
};
int main() {
	Qie q;
	//��첻��ɣ�����ȴ���Ե��ã���Ʋ�����
	q.fly(); 
	return 0;
}
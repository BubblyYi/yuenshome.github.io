///������
#include <iostream>
using namespace std;

using Engine = int;
using Wheel = int;
using Propeller = int; 
class vehicle { //�� ��
public:
	void run() { cout << "������·����\n"; }
private:
	Engine engine; //����
	Wheel wheel;   //����
};
class ship { //�� ��
public:
	void swim() { cout << "����ˮ��Ư\n"; }
private:
	Engine engine;		 //����
	Propeller propeller; //������
};
class Carship :public vehicle, public ship {
private:
	int special;
};
int main() {
	Carship cs;
	cs.run();
	cs.swim();
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
class Person {//�� ��
public:
	void eat(const string& food) {//��
		cout << "�ҳ�" << food << endl;
	}
	void sleep(const string& addr) {//˯
		cout << "��˯��" << addr << endl;
	}
private:
	string name; //����
	int age;	 //����
};
class Student :public Person {//ѧ����
public:
	void study(const string& course) {//ѧϰ
		cout << "��ѧ" << course << endl;
	}
};
class Teacher :public Person  {//��ʦ��
public:
	void teach(const string& course) {//��ѧ
		cout << "�ҽ�" << course << endl;
	}
};
int main() {
	Student stu;
	stu.eat("���");
	stu.sleep("����");
	stu.study("c++");
	Teacher tea;
	tea.eat("С��");
	tea.sleep("����");
	tea.teach("C++");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
class Student {//ѧ����
public:
	void eat(const string& food) {//��
		cout << "�ҳ�" << food << endl;
	}
	void sleep(const string& addr) {//˯
		cout << "��˯��" << addr << endl;
	}
	void study(const string& course) {//ѧϰ
		cout << "��ѧ" << course << endl;
	}
private:
	string name; //����
	int age;	 //����
};
class Teacher {//��ʦ��
public:
	void eat(const string& food) {//��
		cout << "�ҳ�" << food << endl;
	}
	void sleep(const string& addr) {//˯
		cout << "��˯��" << addr << endl;
	}
	void teach(const string& course) {//��ѧ
		cout << "�ҽ�" << course << endl;
	}
private:
	string name; //����
	int age;	 //����
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
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	void eat() { cout << "�Է�" << endl; }
	void sleep() { cout << "˯��" << endl; }
};
class Teacher :public Person { //is-a
public:
	void teach() { cout << "����" << endl; }
};
class Student :private Person { //not is-a
public:
	void study() { cout << "ѧϰ" << endl; }
};
int main() {
	//Teacher public�̳���Person, Teacher is a Person
	Teacher t; //Teacher���������Person���κ�����
	t.eat();
	t.sleep();
	Person *pt = &t; //is-a ��ϵ ����������ֵ
	Person p;  //Person��������Teacher������
	//p.teach();//��,�޷�����

	//Student private�̳���Person,������is-a�Ĺ�ϵ
	Student s; //Student��������Person������
	//s.eat();	//��,�޷�����
	//s.sleep();//��,�޷����� 
	//Person *ps = &s; //������is-a��ϵ����������ֵ
	return 0;
}
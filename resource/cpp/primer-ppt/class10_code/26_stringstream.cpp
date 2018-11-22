///stringstream
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	//istringstream ��string�ж�ȡ����
	//ostringstream ��stringд������
	//stringstream �����Զ���Ҳ����д
	//����������ǰ�������(�̳���ϵ����)

	string str1("a:111111\nb:222222\nc:333333\n");
	stringstream ss1;
	stringstream ss2(str1); //����str1�Ŀ���

	ss1 << 1 << " " << 2 << " I like C++" << endl;
	int i1, i2;
	string tmps;
	ss1 >> i1 >> i2 >> tmps;
	cout <<i1<<" "<<i2<<" "<<tmps<<endl; //��fstreamһ����Ч��
	ss1.seekg(0, stringstream::beg);
	getline(ss1, tmps); //ok,�ַ���û�нض�
	cout << tmps << endl;
	cout << "1-------------\n";

	//��string���е����� ���Ƶ� string����
	string str2 = ss1.str(); //ss1���е����� ��������str2
	cout << str2; 
	cout << "2-------------\n";
	//�ı�string���е�����
	ss1.str(str1); //��str1�����ݿ����� ss1����
	ss1.seekg(0, stringstream::beg);
	while(getline(ss1, tmps)) 
		cout << tmps << endl;
	cout << "3-------------\n";
	//ss1.clear() ������������ݣ�������״̬��λ
	//Ҫ������ݣ���������д��
	ss1.str("");

	//�����Ƶ�read writeҲ���� 
	struct Student { char name[20];	int age; char sex; };
	Student stu[] = { { "����",10,'m' },{ "����",20,'f' },{ "����",0,'m' } };

	ostringstream  os1;
	os1.write((char*)stu, sizeof(stu));
	istringstream is1(os1.str());
	Student tmp;
	for (int i = 0; i < 3; ++i) {
		is1.read((char*)&tmp, sizeof(tmp));
		cout << tmp.name << ":" << tmp.age << ":" << tmp.sex << endl;
	}

	cout << "end--------------\n";
	return 0;
}

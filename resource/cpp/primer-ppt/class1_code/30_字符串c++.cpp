#include <iostream>
#include <string>
using namespace std;
int main() {
	//std::string
	std::string str1("abc"); //��ʼ��
	string str2 = "bcd";	 //��ʼ��
	str2 = "defg";			 //����ֱ�Ӹ�ֵ
	str2 = str1;			 //����ֱ�Ӹ�ֵ
	
	const char *pstr = str2.c_str(); //תc����ַ���
	str2[0] = 'X';		//����ֱ���±���ʲ���
	str2.at(1) = 'Y';	//���� at ���ʲ���
	cout <<"str2=" << str2 << endl; //XYc
	
	//���ַ�������
	cout << str2.size() << endl;
	cout << str2.length() << endl;
	//strlen(str1); ����
	cout << strlen(str2.c_str()) << endl; //��ȷ
	//�ַ�������
	str2 = str2 + str1 + "!!";
	cout << "str2=" << str2 << endl; //XYcabc!!
	//�ַ����Ƚ� (str1: abc)
	cout << str2.compare(str1) << endl; //-1
	cout << (str2 < str1) << endl;	    //1
	//�ַ�������
	cout << str2.find(str1) << endl;	//3
	//�ַ�����ȡ
	string str3 = str2.substr(3, 3);
	cout << str3 << endl;				//abc

	return 0;
}
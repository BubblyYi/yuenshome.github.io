#include <iostream>
using namespace std;
int main() {
	int a = 1, b = 1;
	(a = 0) && (b = 100); //&&�����ʽΪ�٣��Ҳ಻����
	cout << a << b << endl; // a=0 b=1
	int i = 1, j = 1;
	(i = 10) || (j = 100); //||�����ʽΪ�棬�Ҳ಻����
	cout << i << j << endl; //i=10 j=1

	//ע�����
	int c = 1;
	//a<b�ȱ�,����bool����,Ȼ��bool��������Ϊint(0��1)��c�Ƚ�
	bool b1 = a < b < c; 
	
	//ע�����ȼ�����b<c�Ƚϵõ�bool����,����Ϊint�ٺ�a==�ж�
	a == b < c;

	//ע��bool���ͣ�
	a = 10;
	while (a)  //ѭ��10��
		a--;
	a = 10;
	while (a == true)  //ѭ��0��
		a--;
	return 0;
}
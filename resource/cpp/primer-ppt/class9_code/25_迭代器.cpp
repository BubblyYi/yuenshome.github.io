///������ ����
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 1,2,3 };
	//������
	vector<int>::iterator it1 = v1.begin(); //end();
	//const������
	vector<int>::const_iterator it1_c = v1.cbegin(); //cend();
	//���������
	vector<int>::reverse_iterator it1_r = v1.rbegin(); //rend();
	//����const������
	vector<int>::const_reverse_iterator it1_cr = v1.crbegin(); //crend();

	//��Ա����begin/rbegin/end/rend�����ع���
	const vector<int> v2 = { 1,2,3 };
	auto it11 = v1.begin(); //it11 �� vector<int>::iterator
	auto it22 = v2.begin(); //it22 �� vector<int>::const_iterator
	*it11 = 11; //�����÷���
	//*it22 = 10; //��,const������ ֻ��
	cout << *it22 << endl; //�ܶ�����д

	//begin �� end
	//�����г�Ա����begin/end��...
	//Ҳ������std::begin(xx),����������Ҳ��ʹ�� end��Ӧ
	it1 = std::begin(v1);
	it1_c = std::cbegin(v1);
	it1_r = std::rbegin(v1);
	it1_cr = std::crbegin(v1);
	
	//��������Χ [begin, end) ����ҿ�
	while (it1_c != cend(v1)) {
		cout << *it1_c << " ";
		++it1_c;
	}
	cout << endl;
	//���������,++�ǴӺ�����ǰ
	while (it1_cr != crend(v1)) {
		cout << *it1_cr << " ";
		++it1_cr;
	}
	cout << endl;

	return 0;
}
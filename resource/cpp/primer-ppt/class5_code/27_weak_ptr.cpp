#include <iostream>
#include <memory>
using namespace std;

//weak_ptr�÷�(�ӿ�)
int main() {
	weak_ptr<int> wp1; //��ָ��
	shared_ptr<int> sp1 = make_shared<int>(100);
	cout << sp1.use_count() << endl; //1
 	wp1 = sp1; //�������� ���ü���
	cout << sp1.use_count() << endl; //1

	weak_ptr<int> wp2(sp1); //��shared_ptr����
	//use_count()��weak_ptr��Ӧ��shared_ptr�����ü���
	cout << wp2.use_count() << endl; //1

	//expired():��use_count()==0����true,����false
	if (!wp2.expired()) { //û�й���
		//lock():תΪshared_ptr
		shared_ptr<int> sp2 = wp2.lock();
		if (sp2) cout << "ת���ɹ���\n";
	}

	return 0;
}
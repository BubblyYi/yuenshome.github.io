#include <iostream>
#include <string>
using namespace std;
class List {
public:
	void push_back(const string& item){}	//��������
	bool find_item(const string& item)const{//��������
		return true; } 
	void remove(const string& item){}    //ɾ������Ԫ��
	int size()const {return 1;}          //������Ԫ�ظ���
	//�����ӿں���
private:
	//...
};

class Set {
public:
	bool is_member(const string& item)const;//item�Ƿ��ڼ�����
	void insert(const string& item);   //��item���뼯��
	void remove(const string& item);   //��item�Ӽ�����ɾ��
	int size()const;				   //�󼯺���Ԫ�ظ���
private:
	List LS;
};

bool Set::is_member(const string& item)const {
	return LS.find_item(item);
}
void Set::insert(const string& item) {
	if(is_member(item))
		LS.push_back(item);
}
void Set::remove(const string& item) {
	LS.remove(item);
}
int Set::size()const {
	return LS.size();
}
int main() {
	return 0;
}
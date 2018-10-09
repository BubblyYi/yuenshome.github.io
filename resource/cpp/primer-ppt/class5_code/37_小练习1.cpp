#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>* new_vector() {
	return new (nothrow) vector<int>;
}
void input_vector(vector<int>* pv) {
	int v;
	while (cin >> v)
		pv->push_back(v);
}
ostream& print(ostream& out, const int& v, char sep) {
	return out << v << sep;
}
int main() {
	vector<int> *pv = new_vector();
	if (!pv) { cout << "�ڴ治��!\n"; return -1;	}
	input_vector(pv);
	//�� '\t' ��Ϊ�ָ�����ӡ���
	for_each(pv->begin(), pv->end(), 
	  bind(print, ref(cout),std::placeholders::_1,'\t'));
	cout << endl;
	delete pv;
	pv = nullptr;
	return 0;
}
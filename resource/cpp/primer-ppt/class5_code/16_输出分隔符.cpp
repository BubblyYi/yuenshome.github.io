#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class PrintString {
public:
	PrintString(char c = ' ') :sep(c) {}
	void operator()(const string& s)const {
		cout << s << sep;
	}
private:
	char sep;
};
int main() {
	vector<string> vs = { "abc","as","a","aff" };
	//for_each ���� �ĵ��������� Ҳ��һ������ָ�룬ֻ������һ������
	for_each(vs.begin(), vs.end(), PrintString());//Ĭ�Ϸָ���
	cout << endl;
	for_each(vs.begin(), vs.end(), PrintString(','));//�ָ�����,
	cout << endl;
	PrintString fps1 = PrintString('|');
	for_each(vs.begin(), vs.end(), fps1); //�ָ�����|
	cout << endl;
	return 0;
}
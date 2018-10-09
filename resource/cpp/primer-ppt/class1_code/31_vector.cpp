#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	//std::vector�Ľṹ
	std::vector<int> vec11; // [ 1, 3, 9 ...]
	vector<string> vec22;   // [ "abc", "play", "C++" ]
	vector<vector<int>> vec33; // [ [1,3,9..],[2,3,4..], ... ]
	vector<vector<string>> vec44; // [ ["hello","C",..],["C++","abc",..],... ]

	//vector�ĳ�ʼ��
	vector<int> vec1 = { 1,2,3 };
	vector<int> vec2{ 1,2,3 };  //�б��ʼ��
	vector<int> vec3 = vec1;    //vec1������ vec3
	vector<int> vec4(10);		//��ʼ��10��Ԫ�أ�ÿ��Ԫ�ض���0
	vector<int> vec5(10, -1);	//��ʼ��10��Ԫ�أ�ÿ��Ԫ�ض���-1
	vector<string> vec6(10, "hi"); //��ʼ��10��Ԫ�أ�ÿ��Ԫ�ض��� "hi"

	//�ж��Ƿ�Ϊ��
	cout << vec1.empty() << endl; //0
	//Ԫ�ظ���
	cout << vec1.size() << endl;  //3
	//���Ԫ���������
	vec1.push_back(100);
	cout << vec1[vec1.size() - 1] << endl; //100
	//����Ԫ���������
	vec1.pop_back();
	cout << vec1[vec1.size() - 1] << endl; //3
	//ֱ���±����Ԫ��
	cout << vec1[1] << endl; //2
	vec1[1] = 10;
	cout << vec1[1] << endl; //10
	// vector<string> vec6(10, "hi")
	vec6[0][1] = 'X';
	cout << vec6[0] << endl; //hX

	//���������Ʊ������飩
	for (int i = 0; i < vec1.size(); i++) 
		cout << vec1[i] << " "; // 1 10 3
	cout << endl;

	return 0;
}

///vector
#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;
struct A {
	A(const string& ss1="",int i1=0):s1(ss1),d1(i1){}
	string s1;
	int d1;
};
int main() {
	//vector ��̬���� #include <vector>
	//β��ɾ������ӣ��ٶȿ졣	�����ǳ��졣�ڴ���գ�ʹ�õĿռ���١�

	//template<class _Ty, class _Alloc = allocator<_Ty>> class vector...
	//1����ʼ����
	vector<int> v1; //Ĭ�Ϲ���
	vector<double> v2{ 1.0,2.0,3.0 };		 //��ʼ���б�
	vector<string> v3 = { "abc","C++","C" }; //��ʼ���б�
	vector<double> v4(v2);  
	vector<string> v5 = v3; //��������
	vector<string> v6 = std::move(v3); //�ƶ�����
	vector<double> v7(v2.cbegin(), v2.cend()); //��������Χ����
	vector<int> v8(10); //10��Ԫ��,ÿ��Ԫ��Ϊ0��ֵ��ʼ����
	vector<int> v9(10, 1); //10��Ԫ��,ÿ��Ԫ��Ϊ1
	//2.��ֵ (����ԭ�ȵ�����)
	v8 = v1;
	v8 = { 1,2,3 }; //�ó�ʼ���б�ֵ
	v8.assign(v9.cbegin(), v9.cend()); //��������Χ��ֵ
	v8.assign({ 1,2,3 }); //��ʼֵ�б�ֵ
	initializer_list<int> il = { 1,2,3 };
	v8.assign(il);
	v8.assign(10, 2);  //��10��2��ֵ
	//3.swap ����,2��vector���� O(1)ʱ�临�Ӷ�
	vector<int> v10(20,1);  //20��Ԫ�ض���1
	vector<int> v11(10, 2); //10��Ԫ�ض���2
	v10.swap(v11);
	std::swap(v10, v11); //��ִ������ĺ���
	//4.�������
	v10.size(); //Ԫ�ظ���
	v10.empty(); //Ԫ�ظ���==0�򷵻�true
	v10.max_size(); //�ܴ洢�����Ԫ�ظ���
	v10.capacity(); //��ǰ�ܴ洢�����Ԫ�ظ���
	v10.reserve(100); //ֻ������,��������,���ı�Ԫ�ظ���
	cout << v10.size() << endl;
	v10.resize(25); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����ֵ��ʼ�����Ԫ��
	v10.resize(30, 2); //�ı�Ԫ�ظ���,ɾ������Ԫ��,����2���Ԫ��
	v10.shrink_to_fit(); //��������,���ǲ���ǿ���Ե�,ֻ��֪ͨstl���Խ�������
	//5.Ԫ�ط���
	v11[1]=2; //�±����,Ҫ��֤�±겻Խ��,����δ������
	v11.at(1)=20;//�±�Խ����out_of_range�쳣
	if(!v11.empty()) v11.front()=1; //��1��Ԫ�ص�����
	if (!v11.empty()) v11.back()=2; //���һ��Ԫ�ص�����
	//6.���������
	vector<int>::iterator it1 = v11.begin();
	vector<int>::const_iterator it2 = v11.cbegin();
	vector<int>::reverse_iterator it3 = v11.rbegin();
	vector<int>::const_reverse_iterator it4 = v11.crbegin();
	//end()Ҳ��һ��
	//7.����Ԫ��
	vector<A> v12;
	v12.push_back(A("123", 1)); //β�����Ԫ��
	A a1("abc", 2);
	v12.push_back(a1); //Ԫ�ش��������ǿ��� const A&, A&&
	v12.push_back(std::move(a1)); //push_back����ֵ,�ƶ�
	v12.emplace_back("abcd",3); //β�����Ԫ��,ֱ�ӵ���A�Ĺ���
	//�ڵ�����λ��ǰ�����Բ���"aac",9����� A����,����ָ���²���Ԫ�صĵ�����
	v12.emplace(v12.begin(), "aac", 9); 
	A a2("acc", 3);
	vector<A>::iterator it_insert =  v12.insert(v12.begin(), a2); 
	//�ڵ�����λ��ǰ����a2,����ָ���²���Ԫ�صĵ�����
	cout << (*it_insert).s1 << "--" << (*it_insert).d1 << endl;
	//�ڵ�����λ��ǰ����3��a2,����ָ���1����Ԫ�صĵ�����
	v12.insert(v12.begin(), 3, a2);
	vector<A> v13;
	//�ڵ�����λ��ǰ���� v12.begin()��v12.end()֮���Ԫ��,����ָ���1����Ԫ�صĵ�����
	//�� v12.begin() == v12.end() ��ʾ������һ��Ԫ��,���ػ���ԭ������λ��
	v13.insert(v13.begin(), v12.begin(), v12.end());
	v13.insert(v13.begin(), { {"aa",1},{"bb",2} }); //�ó�ʼֵ�б����
	//8.ɾ��Ԫ��
	v13.pop_back(); //ɾ�����1��Ԫ��
	//ɾ��������λ�õ�Ԫ��,����ָ��ɾԪ�غ���Ԫ�صĵ�����,����������end(),����Ϊδ����
	v13.erase(v13.begin()); 
	//ɾ����������Χ,�������1��ɾ��Ԫ��֮��Ԫ�صĵ�����
	v13.erase(v13.begin() + 1, v13.end()); 
	v13.clear(); //�������Ԫ��,�������������(capacity()����)
	//9.��ϵ����
	//����������֧�� == != �����,�����������ⶼ֧�� < > <= >=
	vector<int> v14 = { 1,2,3 };
	vector<int> v15 = { 1,2,4 };
	v14 < v15; //true ,ÿ��Ԫ�صıȽ�
	v14 == v15; //false 
	//10.��C�Ľӿ�
	vector<char> v16(10, '\0');
	strcpy(&v16[0], "abcd"); 
	printf("%s\n", &v16[0]); //abcd
	strcat(v16.data(), "1234");
	printf("%s\n", v16.data()); //abcd1234
	//printf("%s\n", v16.begin()); //��
	printf("%s\n", &(*v16.begin())); //OK
	//��Ϊ��ָ��,������ָ����ĵ�ַ�� &*������
	cout << "----\n";
	return 0;
}
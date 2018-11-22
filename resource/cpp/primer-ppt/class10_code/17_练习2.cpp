//��ϰ����һ���ļ��еĵ��ʰ��չ����ļ�Ҫ��ת�����
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
map<string, string> build_map(ifstream &map_file);
const string& trans_word(const string& word, 
			const map<string, string> &trans_map);

//��ת�������ļ�����map
map<string, string> build_map(ifstream &map_file) {
	map<string, string> trans_map;
	string key;   //Ҫ�滻�Ĺؼ���
	string value; //�滻�������
	char ch; //�м�ո�
	while (map_file >> key && 
		map_file.ignore(1),getline(map_file, value)) 
		trans_map[key] = value;
	return trans_map;
}

//����һ������word,��trans_map�в����Ƿ�Ҫ�滻,����ת�����string
const string& trans_word(const string& word, 
				const map<string, string> &trans_map) {
	auto it = trans_map.find(word);
	if (it != trans_map.end())  //�ҵ�,Ҫ�滻
		return (*it).second;
	else //û�ҵ�,���Ǵ���ԭ����word
		return word;
}

int main() {
	ifstream map_file("rules.txt"); //ת�������ļ�
	map<string, string> trans_map = build_map(map_file);
	for (auto& item : trans_map) //�������ת������
		cout << item.first << "-->"<< item.second << "\n";
	cout << endl;

	ifstream fs("need_trans.txt"); //����Ҫת�����ļ�
	string line; //ÿ�е�����
	while (getline(fs,line)) {
		istringstream ss(line);
		string word;
		bool flag=true;
		while (ss >> word) {
			if (flag) 
				flag = false;
			else 
				cout << " "; //������
			cout << trans_word(word, trans_map);
		}
		cout << endl;
	}
	return 0;
}
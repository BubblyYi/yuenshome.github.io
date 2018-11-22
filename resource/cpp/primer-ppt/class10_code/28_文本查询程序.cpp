//�ı���ѯ����: ��һ���������ļ��в�ѯ����
//��ѯ����Լ����:��ʾ���г��ָõ��ʵ��кź�������,�Լ������еĴ�����
//���һ��������һ���ж�γ���,��ô����ֻ��ʾһ��,Ҳֻ����һ�Ρ�
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

class QueryResult;
ostream& print(ostream& out, const QueryResult &qr);

class TextQuery { 
public:
	//�����ļ����������Ҫ������:���б����ļ���vector,�������ʵ��кż��ϵ�ӳ��
	TextQuery(ifstream& ifs):file(make_shared<vector<string>>()) { //�����ļ�,����
		string text;
		while (getline(ifs, text)) { //һ��һ�ж��� text��
			(*file).push_back(text); //����vector
			int n = (*file).size() - 1; //��ǰ�к�
			istringstream line(text); //׼�������е�ÿ������
			string word;
			while (line >> word) { //�����е�ÿ������,����map(wm��)
				transform(word.begin(), word.end(), word.begin(), ::tolower); //תСд
				shared_ptr<set<int>> &lines = wm[word]; //û�иõ���,Ҳ���Զ�����,���Ǵ�ʱvalue�ǿ�ָ��
				if (!lines)
					lines.reset(new set<int>); //����һ���µ� set<int>
				(*lines).insert(n); //�����кŲ��� set��
			}
		}
	}
	void show()const {
		int i = 1;
		for (const auto& item : *file) //��ʾvector:
			cout << "(" << i++ << ") " << item << endl;
		for (const auto& item : wm) { //��ʾmap:
			cout << item.first << "-->";
			for (const auto& item1 : *item.second) cout << item1 << " "; cout << endl;
		}
	}
	QueryResult query(const string& sought)const; 
private:
	shared_ptr<vector<string>> file; //�ļ�����,ÿ��Ԫ�ض���һ��,�����±���кŶ�Ӧ
	map<string, shared_ptr<set<int>>> wm; //���� --> �����кŵ�set ��ӳ��
};

class QueryResult { 
	friend ostream& print(ostream& out, const QueryResult &qr);
public:
	QueryResult(const string& s,
		const shared_ptr<vector<string>>& f,
		const shared_ptr<set<int>> &p):
				sought(s),file(f),lines(p){}
private:
	string sought; //��ѯ�ĵ���
	shared_ptr<vector<string>> file; //�ļ�����
	shared_ptr<set<int>> lines; //�кż���
};
//��ѯ����,���뵥��,����һ��QueryResult����
QueryResult TextQuery::query(const string& sought)const { 
	//���û���ҵ��õ���,�򷵻�������� ��set<int>
	static shared_ptr<set<int>> nodata = make_shared<set<int>>();
	auto it = wm.find(sought);
	if (it != wm.end()) //�ҵ���
		return{ sought,file, (*it).second };
	else
		return{ sought,file,nodata };
}
ostream& print(ostream& out, const QueryResult &qr) {
	out << qr.sought << " ���� " << (*qr.lines).size() << " ���г���:\n";
	for (const auto& item : *qr.lines) 
		cout << " (" << item + 1 << ") " << (*qr.file)[item] << endl;
	return out;
}

int main() {
	ifstream ifs("word_query.txt");
	if (!ifs) { cout << "open error!\n"; return -1; }
	
	TextQuery tq(ifs);
	tq.show();
	cout << "------------\n";
	while (true) {
		cout << "\n����Ҫ���ҵĵ��� (����q�˳�): ";
		string s;
		if (cin >> s && s != "q") {
			transform(s.begin(), s.end(), s.begin(), ::tolower); //תСд
			print(cout, tq.query(s));
		}
		else
			break;
	}
}
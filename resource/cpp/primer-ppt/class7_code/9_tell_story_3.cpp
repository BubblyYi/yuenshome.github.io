#include <iostream>
#include <string>
using namespace std;
class IReader {
public:
	//���麯�����ӿ�
	virtual string getContent()const = 0;
};
class Book:public IReader {
public:
	virtual string getContent()const override{
		return "�ܾúܾ���ǰ����һ��...";
	}
};
class Newspaper:public IReader {
public:
	virtual string getContent()const override{
		return "�����賿��̨��...";
	}
};
class Mother {
public:
	void tellStory(const IReader& b) {
		cout << "���迪ʼ������: " 
			<< b.getContent() << endl;
	}
};
int main() {
	Book book;
	Mother m;
	m.tellStory(book);
	Newspaper paper;
	m.tellStory(paper);
	return 0;
}
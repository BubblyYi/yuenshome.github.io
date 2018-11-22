///fstream
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream fs1("1.txt", fstream::in | fstream::out | fstream::app);
	//��д,׷��,ÿ��д���ݶ�д���ļ��������

	//�ж��ļ����Ƿ�����
	if (!fs1) { cout << "���ļ�ʧ��!\n"; return -1; }
	if (fs1) { cout << "�ļ���ok\n"; }

	cout << "fs1�ļ��Ƿ��: "<<fs1.is_open() << endl;
	fs1.close(); //��ʽ�ر�,���粻��ʽ�ر�,fs1����������ʱ���Զ��ر��ļ�
	
	fstream fs2;
	fs2.open("2.txt", fstream::in|fstream::out|fstream::trunc);//open���ļ�
	//��д���ض�(�ļ����������,�ļ������ڴ���)
	if (!fs2) { cout << "open error\n"; return - 1; }

	//�� operator<< ������ļ�
	fs2 << 1 << " " << 2 << "\n" << "You like c++" << endl;
	//�� operator>> ���ļ��ж�����
	int i1, i2; string s1;
	fs2.seekg(0, fstream::beg); //�ƶ���ָ�뵽�ļ�ͷ beg cur end
	fs2 >> i1 >> i2 >> s1;
	cout << i1 << " " << i2 << " " << s1 << endl; //��� 1 2 You
	//���⣺ << ������,�ڶ��ַ�����ʱ��,���� �ո� ��ض�
	//����<< >> ������ļ��ܷ��㣬���Ǵ��ļ������ܻ������⡿
	cout << "1--------------\n";

	fs2.seekg(0, fstream::beg);
	char ch;
	while ((ch = fs2.get()) != EOF) //��char get()�� ����һ���ַ�������
		cout.put(ch);
	fs2.clear(); //״̬λ��λ
	fs2.seekg(0, fstream::beg);
	while (fs2.get(ch))	 //��fstream& get(char&)�� 
		cout.put(ch);
	cout << "2--------------\n";

	fs2.clear(); //״̬λ��λ
	fs2.seekg(0, fstream::beg);
	char buf[1024];
	fs2 >> buf; cout << buf << endl; //���ַ���,�����ո�ض�
	fs2.seekg(0, fstream::beg);

	//��fstream& get(char*,int,char)���ַ�����/ָ��,����,��ֹ�ַ�
	//����,�ó�Ա�������Ὣ ��ֹ�ַ�ȡ��,���Ժ����ignore(1),����1���ַ�
	while (fs2.get(buf, 1024, '\n')) {
		cout << buf << endl;
		fs2.ignore(1);
	}
	cout << "3--------------\n";
	fs2.clear();
	fs2.seekg(0, fstream::beg);
	//��istream& getline(char*, int, char)���ַ�����/ָ��,����,��ֹ�ַ�
	//����,�ó�Ա�������Ὣ��ֹ�ַ�����char*,��������Խ���˽�ֹ��
	while (fs2.getline(buf, 1024, '\n')) 
		cout << buf << endl;
	cout << "4--------------\n";

	fs2.clear();
	fs2.seekg(0, fstream::beg);
	//������ģ�� ���ǳ�Ա������ stream& getline(stream&, string&)��
	string tmps;
	while (getline(fs2, tmps))
		cout << tmps << endl;
	cout << "5--------------\n";
	
	fs2.clear();
	fs2.seekg(0, fstream::beg);
	fs2.ignore(100, 'Y'); //������100���ַ�,��������'Y','Y'�ַ��ᱻ���Ե���
	fs2.putback('Y'); //���½�'Y'�Żص�����
	cout << "peek:" << (char)fs2.peek() << endl; //peek()����,���ǲ�ȡ����
	getline(fs2, tmps);
	cout << tmps << endl; 
	fs2.close();
	cout << "6--------------\n";

	ifstream ifs("2.txt",ifstream::in | ifstream::binary); 
	//ifstreamĬ�ϴ򿪷�ʽ: in 
	ofstream ofs("1.txt", ofstream::out| ofstream::trunc | ofstream::binary); 
	//ofstreamĬ�ϴ򿪷�ʽ: out | trunc
	ifs.read(buf, 1024);  //������read, ����1024�ֽ�
	int cnt = ifs.gcount(); //�ϴζ�ȡ���ֽ���
	ofs.write(buf, cnt); //��bufд����,�ֽ���Ϊ cnt

	struct Student { char name[20];	int age; char sex;	};
	Student stu[] = { {"����",10,'m'},{ "����",20,'f' },{ "����",30,'m' } };
	fstream fs_stu("stu.data",fstream::in|fstream::out|fstream::trunc|fstream::binary);
	fs_stu.write(reinterpret_cast<char*>(stu), sizeof(stu));
	fs_stu.seekg(0, fstream::beg);
	Student tmp_stu;
	for (int i = 0; i < 3; i++) {
		fs_stu.read(reinterpret_cast<char*>(&tmp_stu), sizeof(tmp_stu));
		cout << tmp_stu.name << ":" << tmp_stu.age << ":" << tmp_stu.sex << endl;
	}
	cout << "7--------------\n";

	ifstream fs("2.txt");
	if (!fs) { cout << "open error\n"; return -1; }
	//��״̬�жϣ�
	//fs.eof() ����β������true, ���� cin �������� ctrl+Z
	//fs.fail() �ϴ�IO����ʧ�ܷ���true
	//fs.bad() ����true��ʾ������
	//fs.good() ��������Ч״̬����true
	cout << "fs.eof(): " << fs.eof() << endl  //0
		<< "fs.fail(): " << fs.fail() << endl //0
		<< "fs.bad(): " << fs.bad() << endl   //0
		<< "fs.good(): " << fs.good() << endl;//1
	cout << "7.1-----\n";
	while (fs.get(ch)) cout << ch;
	//��ǰλ�����ļ�β��
	cout << "fs.eof(): " << fs.eof() << endl  //1
		<< "fs.fail(): " << fs.fail() << endl //1
		<< "fs.bad(): " << fs.bad() << endl   //0
		<< "fs.good(): " << fs.good() << endl;//0
	cout << "7.2-----\n";
	fs.clear(); //״̬��λ,����Ч
	fs.seekg(0, ifstream::beg);
	cout << "fs.eof(): " << fs.eof() << endl  //0
		<< "fs.fail(): " << fs.fail() << endl //0
		<< "fs.bad(): " << fs.bad() << endl   //0
		<< "fs.good(): " << fs.good() << endl;//1
	cout << "7.3-----\n";
	int a1, a2, a3;
	fs >> a1 >> a2 >> a3; //a3���,Ҫ�����int,����û��
	cout << "fs.eof(): " << fs.eof() << endl  //0
		<< "fs.fail(): " << fs.fail() << endl //1
		<< "fs.bad(): " << fs.bad() << endl   //0
		<< "fs.good(): " << fs.good() << endl;//0
	cout << "7.4-----\n";

	cout << "end--------------\n";
	return 0;
}
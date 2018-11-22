///�Լ���װ�ļ���MyFstream
#include <cstdio>
class MyFstream {
public:
	MyFstream(const char* path, const char* mode) { //���죬���ļ�
		fp = fopen(path, mode);
		if (!fp) throw "Open File error!";
	}
	~MyFstream() { 	if (fp) fclose(fp);	} //�������ر��ļ�
	MyFstream(const MyFstream&) = delete; //���ܿ���
	MyFstream& operator=(const MyFstream&) = delete; //���ܸ�ֵ
	int get() {	return fgetc(fp); } //��1���ַ� fp --> char
	void put(int ch) { fputc(ch, fp); } //д1���ַ� char --> fp
	char* getline(char* buf, int n) { return fgets(buf, n, fp);	} //��һ��fp->char*
	void seek(int offset, int where) { 	fseek(fp, offset, where); } //�ƶ��ļ�ָ��
	MyFstream & operator>> (int &val) { //��fp��һ��int, fp --> int
		fscanf(fp, "%d", &val); return *this;
	}
	MyFstream & operator>> (char* val) { //��fp��1���ַ���,fp --> char*
		fscanf(fp, "%s", val); return *this;
	}
	MyFstream & operator<<(const int& val) { //дһ��int���ļ� int --> fp
		fprintf(fp, "%d", val); return *this;
	}
	MyFstream &operator<<(const char* val) { //дһ���ַ������ļ� const char* --> fp
		fprintf(fp, "%s", val);  return *this;
	}
private:
	FILE * fp;
};

int main() {
	MyFstream fs("1.txt", "w+");
	
	//д���������� (�� cout << 123 ����)
	fs << 123 << " " << 234 << " " << 345 << "\n";
	//д���ַ���
	fs << "I like C++\n";
	fs << "We all like coding...\n";

	int a1=0, a2=0, a3=0;
	//�������� a1,a2,a3 (�� cin >> a1 ����)
	fs.seek(0, SEEK_SET);
	fs >> a1 >> a2 >> a3;
	printf("%d %d %d\n", a1, a2, a3); //��ӡ���

	char buf1[100],buf2[100],buf3[100];
	//���ַ����� buf1 (�� cin >> buf1 ����)
	fs >> buf1 >> buf2 >> buf3;
	printf("%s %s %s\n", buf1,buf2,buf3);
	//����Ľ������cin���ַ���һ��,�����ո�ض�

	fs.get();
	//��getline���ַ����� buf1
	fs.getline(buf1, sizeof(buf1));
	printf("%s", buf1);

	return 0;
}
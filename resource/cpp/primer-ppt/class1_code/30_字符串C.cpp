#include <stdio.h>
#include <string.h>
int main() {
	//�ַ�����
	char str1[20] = "abcde";		//��ʼ��
	char str2[20] = { 'a','b','c' };//��ʼ��
	//str2 = "abc";	����
	char str3[20];
	str3[0] = 'a'; str3[1] = 'b'; str3[2] = '\0';
	//�ַ�ָ��
	char *pstr = "bcd"; //�������ַ����ĵ�ַ����pstr
	pstr = "def";
	pstr = str1;
	pstr[0] = 'x';		//ͨ��ָ���޸�
	*(pstr + 1) = 'y';	//ͨ��ָ���޸�
	printf("str1=%s\n", str1); // ���xycde
	//�ַ�������
	printf("str1����= %d\n", strlen(str1));  //5
	//�ַ�������
	printf("str1=%s\n", strcpy(str1, "ddd"));//ddd
	//�ַ�������
	printf("str1=%s\n", strcat(str1, str2)); //dddabc
	//�ַ����Ƚ�
	if (strcmp(str2, str3) > 0)
		printf("%s > %s\n", str2, str3);
	else if(strcmp(str2, str3) == 0)
		printf("%s == %s\n", str2, str3);
	else
		printf("%s < %s\n", str2, str3);
	//�ַ�������
	strcpy(str2, "--ab=="); //str3: "ab"
	printf("%s\n", strstr(str2, str3)); //ab==
	return 0;
}
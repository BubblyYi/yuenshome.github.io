#include <iostream>
using namespace std;
int main() {
	//unsigned( int �� unsigned�Ƚϵ�ʱ��int����תΪunsigned,����ע��!)
	int j = -1;
	char arr[9] = { 1,2,3,4,5,6,7,8,9 };
	while (j < sizeof(arr)) {
		if (j == -1)
			cout << j << " ";
		else
			cout << arr[j] << " ";
		j++;
	}
	cout << endl;
	return 0;
}


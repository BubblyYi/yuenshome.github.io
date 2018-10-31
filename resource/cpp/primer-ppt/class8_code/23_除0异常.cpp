///��0
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "����2������: ";
	while (cin >> a >> b) {
		try {
			if (b == 0) throw runtime_error("divisor is 0");
			cout << static_cast<double>(a) / b << endl;
			cout << "����2������: ";
		}
		catch (runtime_error err) {
			cout << err.what();
			cout << "\nTry Again? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n' || c == 'N')
				break;
			else
				cout << "����2������: ";
		}
	}
	
	return 0;
}
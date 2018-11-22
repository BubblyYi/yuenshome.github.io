//��ϰ1��ɾ��vector���ض���Ԫ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//remove������ʵ��
template <typename ForwardIterator, typename T>
ForwardIterator my_remove(ForwardIterator first,
					ForwardIterator last, const T& val){

	ForwardIterator result = first;
	while (first != last) {
		if (!(*first == val)) {
			*result = move(*first);
			++result;
		}
		++first;
	}
	return result;
}
template<typename T>
void remove_all_same_value(std::vector<T>& vec, const T& value) {
	//����std::removeʵ��
	vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}
int main() {
	vector<int> v1 = { 1,2,3,2,2,1,4 };
	for (const auto& item : v1)	cout << item << " "; cout << endl;
	remove_all_same_value(v1, 2);
	for (const auto& item : v1)	cout << item << " "; cout << endl;
	return 0;
}
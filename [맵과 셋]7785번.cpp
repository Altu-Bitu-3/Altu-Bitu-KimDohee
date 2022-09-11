#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	string name;
	string n_log;
	set<string> s;

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> name >> n_log;  //�̸��� ���Ա�� ������� �Է�

		if (n_log == "enter") {  //enter�ԷµǸ� set�� �̸� �߰�
			s.insert(name);
			continue;
		}
		if (n_log == "leave") { //leave�ԷµǸ� set�� �̸� ����
			s.erase(name);
		}
	}
	
	vector<string> vec(s.begin(), s.end()); //vector�� ��ȯ�Ͽ� ���� ��� ����

	for (int i = vec.size()-1; i >=0; i--) {
		cout << vec[i] << '\n';
	}

	return 0;
}
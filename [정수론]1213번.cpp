#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ans = "";  //����� ������ string

void palindrome(vector<int>& v, int idx) {
	for (int i = 0; i < 26; i++) { //���ݺ� ���ĺ� ä���
		for (int j = 0; j < v[i] / 2; j++) { //�󵵼� ���ݸ�ŭ �տ� ä���, ������ ������ ��(�Ĺݺ�)�� ä���
			ans += (i + 'A');
		}
	}

	if (idx != -1) {  //����� Ȧ������ ���ĺ� �߰�
		ans += (idx + 'A');
	}

	for (int i = 25; i >= 0; i--) {  //�Ĺݺ� ���ĺ� ä���
		for (int j = 0; j < v[i] / 2; j++) {
			ans += (i + 'A');
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	//�Է�
	string s;
	cin >> s;

	int cnt = 0; //Ȧ������ ���ĺ� ���� ������ ����
	int odd_idx = -1; //Ȧ������ ���ĺ� index ������ ����
	vector<int> vec(26);

	for (int i = 0; i < s.size(); i++) { //���ĺ� ���� ����
		vec[s[i] - 'A']++;
	}


	for (int i = 0; i < 26; i++) {  //Ȧ������ ���ĺ� ���� ����
		if (vec[i] % 2 == 1) {
			cnt++;
			odd_idx = i;
		}
	}

	if (cnt >= 2) { //Ȧ������ ���ĺ��� �� �� �̻��̸� �Ӹ���� ���� �� ����(�߾ӿ��� 1���� �� �� �ֱ� ������)
		cout << "I'm Sorry Hansoo";
	}
	else {
		palindrome(vec, odd_idx);  //�󵵼� ����� vec�� Ȧ������ ���ĺ��� �ִ� ��츦 ���� odd_idx�� ���� input
	}

	return 0;
}
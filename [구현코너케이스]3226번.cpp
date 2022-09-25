#include <iostream>
#include <string>

using namespace std;

int callSum(string a, string b, int d) {
	int sum = 0; //��ȭ��� �հ� ����
	int h = stoi(a);  //string�� ������ ��ȯ
	int m = stoi(b); 
	int new_m = m;   //60���� �Ѿ �� ����ؼ� ���ο� ī�Ǻ� ����
	int new_h = h;   //24�ø� �Ѿ �� ����ؼ� ���ο� ī�Ǻ� ����

	if ((m + d) < 60) {  //60�� �� �Ѿ�� �׳� �����ֱ�
		new_m = m + d;
	}
	else {  //60�� �Ѿ�� 60���� ���� �������� ����, hour�� �Ȱ��� ������� �Ǵ�
		new_m = (m + d) % 60;
		if ((h + (m + d) / 60) < 24) {
			new_h = h + ((m + d) / 60);
		}
		else {
			new_h = (h + ((m + d) / 60)) % 24;
		}
	}

	if ((h == 6) && (new_h == 7)) { //��ȭ �� ��ħ 7�÷� �Ѿ��, ���� �ð� �� ��� �޶����Ƿ� ���� ���� ���ֱ�
		sum += 5 * (d - new_m) + 10 * new_m;
	}
	else if ((h == 18) && (new_h == 19)) { //���� ����
		sum += 10 * (d - new_m) + 5 * new_m;
	}
	else {
		if ((h > 6) && (h < 19)) {  //7��~19��: 1�п� 10��
			sum += 10 * d;
		}
		else {  //19��~7��: 1�п� 5��
			sum += 5 * d;
		}

	}
	return sum;

}


int main() {
	//�Է�
	int n; //����̰� �� ��ȭ�� ��
	cin >> n;

	int sum = 0;

	while (n--) {
		string s = "";
		cin >> s;

		string h = s.substr(0, 2);  //���ڿ� �� ĭ�� �ش��ϴ� ���ڸ� int�� ����
		string m = s.substr(3, 2);
		int d;
		cin >> d;   //DD �Է�

		sum = sum + callSum(h, m, d);
	}
	cout << sum << '\n';

	return 0;
}
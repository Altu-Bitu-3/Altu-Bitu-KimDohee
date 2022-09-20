#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector <int> A;
vector <int> B;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	int up_count = 0; //�ø� ���� ����
	int sum = 0; //���� �ڸ��� ���� ��
	string a_b_sum; //���� ��� ���� ���ڿ�

	cin >> a >> b;  //A, B�� string���� ���ʴ�� �Է¹ޱ�

	//a, b�ڸ��� ���̳���..? -> ���ڸ���ŭ 0���� ä���
	//������ ���� a>b�� ����

	if (a.size() < b.size()) {
		swap(a, b);
	}
	int diff = a.size() - b.size(); //�ڸ��� ���� ���

	for (int i = 0; i < a.size(); i++) {
		A.push_back(a[i] - '0');  //-'0': �ƽ�Ű�ڵ� �� ����
	}

	for (int i = 0; i < diff; i++) { //�ڸ��� ���̸�ŭ b�� ���ڸ��� 0���� ä���
		B.push_back(0);
	}

	for (int i = 0; i < b.size(); i++) {
		B.push_back(b[i] - '0');
	}


	//�����ڸ������� ���ʴ�� ���ϱ�
	for (int i = a.size() - 1; i >= 0; i--) {
		sum = A[i] + B[i];

		if (up_count == 1) { //�ø����������� ���� �̹� 1�̶��, sum�� 1�߰�
			sum++;
			up_count = 0;
		}

		if (sum > 9) {
			sum = sum % 10; //10���� ���� �������� ����, �ø� ���� ������ 1 ����
			up_count++;
		}

		a_b_sum.append(to_string(sum));
	}
	if (up_count == 1) {  //������ ������ ������ �ø� ����==1�̸� a_b_sum�� '1'�� ���ٿ���
		a_b_sum.append("1");
	}

	for (int i = a_b_sum.size() - 1; i >= 0; i--) {
		cout << a_b_sum[i];
	}

	return 0;
}
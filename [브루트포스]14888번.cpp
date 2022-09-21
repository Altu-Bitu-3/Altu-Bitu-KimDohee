#include <iostream>
#include <vector>

using namespace std;

int n;
int mx = -1000000000;
int mn = 1000000000;
int num[11];
int op[4];


void getResult(int result, int idx) {  //idx�� ���� ���� num�� �ε���
	

	if (idx == n) {  //��� ���� ����
		if (mn > result) {
			mn = result;
		}
		if (mx < result) {
			mx = result;
		}
		
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;  //������ �Ҹ������Ƿ� �ϳ� ����
			if (i == 0) { //���ϱ�
				getResult(result + num[idx], idx + 1);  //num�� ���� �ε������� ���� ����
			}
			else if (i == 1) {//����
				getResult(result - num[idx], idx + 1);
			}
			else if (i == 2) {  //���ϱ�
				getResult(result * num[idx], idx + 1);
			}
			else {				//������
			getResult(result / num[idx], idx + 1);
			}
		
			op[i]++;   //�ϳ� �ٽ� �ø�
		}
	}
}


int main() {
	//���� ���� �Է�
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	getResult(num[0], 1);

	cout << mx << '\n' << mn << '\n';


	return 0;
}
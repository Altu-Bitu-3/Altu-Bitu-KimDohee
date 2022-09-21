#include <iostream>
#include <vector>

using namespace std;

void sizeOfRoom(int r, int b, vector<int>& v) {
	//r, b�� ���� ����, ���� Ÿ���� ����, v�� ���� ���� ���� ������ ����
	int total_num = r+b;  //�� Ÿ���� ����

	for (int i = 1; i <= total_num; i++) {
		//���α��̰� i, ���α��̰� total_num/i�϶� ������, ���� Ÿ���� ���� ���� ���ϱ�
		if (total_num % i == 0) { //����i, ���� total_num/i�� �Ѵ� ������ �������������� �ݺ��� ������
			int r_temp = (i+(total_num/i))*2-4;  //(����+����)*2-4�� �����ڸ�(����) Ÿ���� ����
			if (r_temp == r) { //�־��� ���� Ÿ���� ����(�Է����� ����)�� ���ΰ� i�϶� ����Ÿ���� ���� ���ٸ� �������� �䱸�ϴ� L�� ���� i�� ��
				v[0] = i;
				v[1] = total_num / i;
				break;
			}
		}
	}
}

int main() {
	//�Է�
	int r, b;
	cin >> r >> b;

	vector<int> vec(2, 0); //vec[0]: L , vec[1] : W 
	
	sizeOfRoom(r, b, vec);

	cout << max(vec[0], vec[1]) << " "<< min(vec[0], vec[1]) << '\n';

	return 0;
}
//���̺��ڵ� 15649������ check ����(����)�� �̿��ؼ� üũ�ϴ� ������ �����Ͽ����ϴ�. 

#include <iostream> 

using namespace std; 

int cost[10][10];  //��� �Լ�
int n;   //���� ��
bool check[10] = { false };  //�湮���� ���� ����:false�� �ʱ�ȭ
int result=1e8; //10�� 6�� x 10 x 10 �� �ִ����� ����

void calculateCost(int i, int j, int cnt, int csum) {  //i: ���� ����, j: �ε���, cnt: �湮�� ���� Ƚ��, csum: ����� ���س��� ����
	if (cnt == n) { //��� ���� �湮������(��������)
		if (cost[j][i] == 0) { //��� ���� �湮�ߴµ�, ó������ ���ư� �� ���°���
			return;				// ��ȸ �Ұ�
		}
		if (cost[j][i]>0) {//�̵������ϸ�
			result = min(csum + cost[j][i], result); //�ּڰ� ���ؼ� ����������� ����
		}
		return;   //�Լ� ����
	}

	for (int k = 0; k < n; k++) {  //k=0~n���� ���鼭 ����� ��� �� üũ
		if ((check[k] == true) || (cost[j][k] == 0)) { //�湮�ߴ� ���̰ų� �̵��� �� ���� ���̸�(cost[j][k]==0) �ǳʶٱ�
			continue;
		}
		check[k] = true; //�湮�����Ƿ� true ����
		calculateCost(i, k, cnt + 1, csum + cost[j][k]); //���� �ε��� �־ ȣ��
		check[k] = false; // ���� ���·� ��������
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {   //���ʷ� nxn��� �Է¹���(��� �Է�) 
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	//����
	for (int i = 0; i < n; i++) {
		//���۵���: i, 0���� n���� �ٸ� �������� �����غ��鼭 ��� ���
		check[i] = true; //���۵���-true�� �ٲ�(�湮�ߴٴ� ��) 
		calculateCost(i, i, 1, 0); //���ʷ� ���۵���, ��ġ, �湮�� ������ ��, ���
		check[i] = false; //�ٽ� false�� �ʱ�ȭ(����(?) ����) 
	}

	cout << result << '\n';   //�ּҺ�� ȣ��
	return 0;
}
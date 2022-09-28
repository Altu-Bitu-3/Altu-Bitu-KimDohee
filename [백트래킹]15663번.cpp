//���̺��ڵ����� ������ �� ������ ������ �̿��Ͽ����ϴ�. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m; //n���� �ڿ��� �Է¹ޱ�, m�� ����

vector<int> v;  //�Է¹��� ����
vector<int> num(SIZE);  //����� ������ ����
vector<bool> check(SIZE); //�ߺ� Ȯ���� ����

void backtracking(int cnt) {  //cnt�� ������ �ε����� �ǹ�
	if (cnt == m) { //������ �ϴ� m�� �����Ҷ�(��������)
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int cnum=-1; //�ߺ� üũ�ϱ� ���� ����, �ٷ� ������ ���õ� ���� ����

	for (int i = 0; i < n; i++) {  //i: ������ ��
		if ((!check[i]) && (v[i] != cnum)) { 
			//check�� ���� üũ�ϴ� �Ϳ��� ��ġ�� �ʰ�
			//v[i]�� cnum�� ���ؼ� 2 4 4 ó�� �ߺ��Ǵ� ���ڰ� ��µ��� �ʰ� ����
			cnum = v[i]; 
			num[cnt] = v[i];
			check[i] = true;			
			backtracking(cnt + 1);
			check[i] = false; //�ٽ� ����ϱ� ���Ͽ� �������·� ��������
		}
	}

}

int main() {
	//�Է�
	cin >> n >> m;

	int k;

	for(int j=0;j<n;j++){
		cin >> k;  //0���� n-1�ε������� ���� �Է¹ޱ�
		v.push_back(k);
	}

	sort(v.begin(), v.end());  //�������� ����


	//����
	backtracking(0);

	return 0;
}
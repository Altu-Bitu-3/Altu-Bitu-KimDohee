#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

void max_tip(int left, int right) {
	int p1 = left;  //���ʺ��� ���������� ���鼭 ����ų ������
	int count = 1;
	int tip_sum = 0;

	while (p1 <= right) {
		if ((arr[p1] - (count - 1)) < 0) {  //���� ������ �ٷ� ���ǹ� ������������
			break;
		}
		else {
			tip_sum += arr[p1] - (count - 1);  //�� ���(���� ����)
			p1++;  //���� ĭ ����Ű����
			count++;   //�ε��� �� �ϳ� ����
		}
		
	}
	cout << tip_sum << "\n";
}

int main() {
	int n; // ��Ÿ�ڽ� �տ� �� �ִ� ����� �� 
	
	cin >> n;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());   //������������ ����

	max_tip(0, n-1);
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�Լ�-ī��ǥ���
long long maxTip(int left, int right, vector<int>& arr) {
	int p1 = left;  //���ʺ��� ���������� ���鼭 ����ų ������
	long long tip_sum = 0;

	while ((p1 <= right) && ((arr[p1] - p1) >= 0)) { //���� ������ �ٷ� Ż��
		
		tip_sum += (arr[p1] - p1);  //�� ���(���� ����)
		p1++;  //���� ĭ ����Ű����

	}

	return tip_sum;
}

int main() {
	int n; // ��Ÿ�ڽ� �տ� �� �ִ� ����� �� 
	vector<int> arr;  

	long long sum = 0;
	
	cin >> n;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());   //������������ ����

	sum = maxTip(0, n-1, arr);

	cout << sum << "\n";

	return 0;
}
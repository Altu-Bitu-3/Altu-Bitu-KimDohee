#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, h, t; //�α���, ��Ƽ�� Ű, �и�ġ Ƚ��

	//�Է�
	cin >> n >> h >> t;

	//�� �ʱ�ȭ
	priority_queue<int> magic_heap;

	int x;
	while (n--) { //nȽ����ŭ �� �Է�
		cin >> x;
		magic_heap.push(x);
	}

	int count = 0; //�и�ġ ��� Ƚ�� ������ ����

	while (t--) { //�и�ġ ���� Ƚ����ŭ �ݺ�
		if (magic_heap.top() >= h) { //top�� ��Ƽ���� Ŭ ���
			if (magic_heap.top() > 1) { 
				int k = magic_heap.top() / 2; //���� ���� �ִ� ���� ������ 2
				magic_heap.pop(); //������ 2�ϱ� ���� ���� ����
				magic_heap.push(k); //������ 2�� �� ����
				count++; //���Ƚ�� 1 ����
			}
		}
	}

	//�и�ġ ��� �� Ű�� ���� ū ������ Ű�� max�� �����ص�
	int max = magic_heap.top();

	int check = 0; //0�� ��Ƽ���� Ű ũ�ų� ���� ������ ���� ���

	for (int i = 0; i < magic_heap.size(); i++) {
		if (magic_heap.top() >= h) {
			//��Ƽ���� ũ�ų� ���� ������ ������
			check = 1; //1�� update
		}
		magic_heap.pop(); //top�� �ִ� �� ����
	}

	switch (check) {
	case 0: //���ε��� ��� ��Ƽ���� ������
		cout << "YES\n";  //YES, count ���
		cout << count << '\n';
		break;
	case 1: //���� �߿� ��Ƽ���� ũ�ų� ���� ������ ������
		cout << "NO\n";  //NO, max ���
		cout << max << '\n';
		break;
	}

	return 0;
}
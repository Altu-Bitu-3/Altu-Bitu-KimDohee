#include <iostream>

using namespace std;

//��Ŭ���� ȣ����
int gcdRecursion(int a, int b) {
	//a > b�϶� a, b�� �ִ������� ����
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}

int numOfTiles(int x, int y) {
	int num;

	//����+����-�ִ����� = �밢���� �׷��� Ÿ�� ����
	num = x + y - gcdRecursion(max(x, y), min(x, y));

	return num;
}

int main() {
	//�Է�
	int x, y;
	cin >> x >> y;

	cout << numOfTiles(x, y) << '\n';

	return 0;
}
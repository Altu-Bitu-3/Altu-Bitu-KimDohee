#include <iostream>

using namespace std;

//유클리드 호제법
int gcdRecursion(int a, int b) {
	//a > b일때 a, b의 최대공약수를 리턴
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}

int numOfTiles(int x, int y) {
	int num;

	//가로+세로-최대공약수 = 대각선이 그려진 타일 개수
	num = x + y - gcdRecursion(max(x, y), min(x, y));

	return num;
}

int main() {
	//입력
	int x, y;
	cin >> x >> y;

	cout << numOfTiles(x, y) << '\n';

	return 0;
}
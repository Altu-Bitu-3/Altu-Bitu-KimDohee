#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6; //�ִ� ���� ����

//�����佺�׳׽��� ü
void getPrime(vector<bool>& isPrime) { //1,000,000 ���� �Ҽ� �����ϴ� ����
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


void goldBach(int n, vector<bool>& isPrime) {  //������ ���� �ذ�

	bool answer = false;

	for (int i = 2; i <= n; i++) {
		if ((isPrime[i]) && (isPrime[n - i])) { //Ư�� �Ҽ��� �ֿ� ���ԵǷ���, n-Ư�� �Ҽ��� ���� ���;ȿ��� true���� �������Ѵ�(�Ҽ������Ѵ�)

			cout << n << " = " << i << " + " << n - i << '\n';

			answer = true; //���� n�� �����ϴ� ��찡 �����Ƿ� true����
			break;
		}
	}

	if (answer == false) { //���� n�� �����ϴ� ��찡 ������
		cout << "Goldbach's conjecture is wrong." << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> isPrime(MAX + 1, true);   //�Ҽ� �迭 �����ϴ� ����
	
	getPrime(isPrime);  //�Ҽ� üũ ���� ����

	//�Է�
	while (true) {
		int n;
		cin >> n;

		if (n == 0) //n==0�̸� �Է� ����
			break;

		goldBach(n, isPrime);
	}

	return 0;
}
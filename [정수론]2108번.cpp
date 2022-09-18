#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int avg(vector<int> &v) { //������ ���ϱ�
	double average;   //��հ� sum��� ������ �� ���� double�� ����
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	average = sum / v.size();
	return round(average);  //�ݿø��Լ� round()���
}

int middle(vector<int>& v) {  //�߾Ӱ� ���ϱ� 
	sort(v.begin(), v.end()); //����
	int midindx; //�߾Ӱ��� ��ġ�� �ε��� 
	midindx = (v.size()-1) / 2; //���ʹ� �ε��� 0���� �����ϹǷ� v.size()-1�������
	return v[midindx];
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) { //���Լ�
	if (a.second == b.second)
		return a.first < b.first;   //�󵵼� ���� ��� �ι�°�� ���� ���� ���ʿ� ��ġ��Ű��
	return a.second > b.second;  //�󵵼� �ٸ��� ������������ ����(�󵵼� ū������) 
}

int mode(int n, vector<int>& v) {  //�ֺ� ���ϱ�
	map<int, int> m; //(value, �󵵼�) ������ map

	for (int i = 0; i < n; i++) {
		if (m.find(v[i]) != m.end()) {  //map�� value�� �̹� �����ϸ� �󵵼� 1 ����
			m[v[i]]++;
		}
		else {   //���ο� value�� ������ �߰�, �󵵼� 1 ����
			m[v[i]] = 1;
		}
	}

	vector<pair<int, int>> vec(m.begin(), m.end()); //map�� vector�� �̵�
	
	sort(vec.begin(), vec.end(), cmp); //�󵵼� ���� ����
	
	if (vec.size() == 1) { //vec size�� 1�̸� �ؿ� else�������� ������ ���Ƿ� ���� ����
		return vec[0].first;
	}

	if (vec[0].second != vec[1].second) {
		return vec[0].first;
	}
	else {
		return vec[1].first;
	}
}

int range(int n, vector<int>& v) { //range���ϱ�
	sort(v.begin(), v.end());  //�������� ����
	return (v.back() - v.front());
}

int main() {
	//�Է�
	int n;
	cin >> n;  //n�� Ȧ��

	if (n % 2 == 1) {

		vector<int> vec(n, 0);

		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			vec[i] = k;
		}

		//���
		cout << avg(vec) << '\n';
		cout << middle(vec) << '\n';
		cout << mode(n, vec) << '\n';
		cout << range(n, vec) << '\n';
	}

	return 0;
}
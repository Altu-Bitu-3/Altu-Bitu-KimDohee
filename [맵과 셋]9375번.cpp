#include <iostream>
#include <map>

using namespace std;

int main() {
	int n; //�׽�Ʈ���̽� �� 

	//�ǻ� �� �Է�
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; //�ǻ� ��
		cin >> num; //�ǻ��� ����
		string name, type;
		map<string, int> clothes; //(�ǻ� ����, �ǻ� ����)

		for (int j = 0; j < num; j++) {
			cin >> name >> type;
			if (clothes.find(type) == clothes.end()) { //���ο� type�� map�� ������
				clothes[type] = 1;
			}
			else
				clothes[type] ++; //type����ÿ� ���� �Ѱ��� ����
		}

		//�� type���� �����ϴ� ����+1(1�� �����ִ� ���� ���Դ� ��� ����ϱ� ���ؼ�)
		//�� �ؼ� type���� �� ������ ����, ��� �� ���Դ�(�˸��� ���) 1���� ��츦 ���ָ� �ȴ�. 
		int c_case = 1; 
		for (auto iter : clothes) {
			c_case = c_case * (iter.second + 1);
		}
		c_case--;
		cout << c_case << '\n';
	}

	return 0;
}
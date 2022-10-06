#include <iostream>  //c++ ����� ���
#include <queue>	 //queue ���(�켱���� ť �̿��ϱ� ���ؼ�)
#include <vector>	 //vector ���

using namespace std; //std ���̺귯�� ���

int check(vector<int>& children, priority_queue<int>& present_heap) { //�Ǹ��ϴ� ���̰� �ִ��� üũ�ϴ� �Լ�

	for (int i = 0; i < children.size(); i++) { //���̵� ����ŭ �ݺ�
		if (present_heap.top() < children[i]) //���� ������ ���� ����ִ� ������ �������� ���̰� ���ϴ� �ͺ��� �۴ٸ� ���̴� �Ǹ��� ��
			return 0; //�Ǹ������Ƿ� 0 ����
		else { //���� ������ ���� ��� ���ڿ��� ���̵��� ���ϴ� ��ŭ ������ �� �ִ� ���
			int temp = present_heap.top() - children[i]; //���̵��� ������ ��ŭ ���ְ�, �װ��� temp�� ����
			present_heap.pop(); //���� ���� �� ����
			present_heap.push(temp); //temp�� �켱����ť�� ����
		}
	}
	return 1; //�Ǹ����� �ʾ����Ƿ� 1 ����
}

int main() { //�����Լ�
	int n, m;  //���ʴ�� �������� ����, ���̵� ���
	cin >> n >> m;  //�Է�

	vector<int> children(n);  //���� �ʱ�ȭ
	priority_queue<int> present_heap;  //�� �ʱ�ȭ

	int x; //x��� ���� ����(���� ���� �Է¹ޱ� ���ؼ�)
	while (n--) { //������ ������ŭ �ݺ�
		cin >> x;  //���ھ��� ���� ���� �Է¹ޱ�
		present_heap.push(x);  //���� ������ �켱����ť�� ����
	}

	int y; //���̵� ���ڰ� ���ϴ� ���� ���� ������ ����
	while (m--) { //���̵� �����ŭ �ݺ�
		cin >> y; //���̵� ���ڰ� ���ϴ� ���� ���� �Է¹ޱ�
		children.push_back(y); //���Ϳ� ����
	}

	int result = check(children, present_heap); //check�Լ��� ���� 1 �Ǵ� 0 ���Ϲޱ�

	cout << result << '\n';  //����� ���

	return 0; //����
}
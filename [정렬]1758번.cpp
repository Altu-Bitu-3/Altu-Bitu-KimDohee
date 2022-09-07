#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

void max_tip(int left, int right) {
	int p1 = left;  //왼쪽부터 오른쪽으로 가면서 가리킬 포인터
	int count = 1;
	int tip_sum = 0;

	while (p1 <= right) {
		if ((arr[p1] - (count - 1)) < 0) {  //팁이 음수면 바로 조건문 빠져나오도록
			break;
		}
		else {
			tip_sum += arr[p1] - (count - 1);  //팁 계산(문제 참고)
			p1++;  //다음 칸 가리키도록
			count++;   //인덱스 값 하나 증가
		}
		
	}
	cout << tip_sum << "\n";
}

int main() {
	int n; // 스타박스 앞에 서 있는 사람의 수 
	
	cin >> n;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());   //내림차순으로 정렬

	max_tip(0, n-1);
}
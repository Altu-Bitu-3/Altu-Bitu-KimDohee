#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//함수-카멜표기법
long long maxTip(int left, int right, vector<int>& arr) {
	int p1 = left;  //왼쪽부터 오른쪽으로 가면서 가리킬 포인터
	long long tip_sum = 0;

	while ((p1 <= right) && ((arr[p1] - p1) >= 0)) { //팁이 음수면 바로 탈출
		
		tip_sum += (arr[p1] - p1);  //팁 계산(문제 참고)
		p1++;  //다음 칸 가리키도록

	}

	return tip_sum;
}

int main() {
	int n; // 스타박스 앞에 서 있는 사람의 수 
	vector<int> arr;  

	long long sum = 0;
	
	cin >> n;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());   //내림차순으로 정렬

	sum = maxTip(0, n-1, arr);

	cout << sum << "\n";

	return 0;
}
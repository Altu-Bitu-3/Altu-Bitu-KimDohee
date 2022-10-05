#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, h, t; //인구수, 센티의 키, 뿅망치 횟수

	//입력
	cin >> n >> h >> t;

	//힙 초기화
	priority_queue<int> magic_heap;

	int x;
	while (n--) { //n횟수만큼 값 입력
		cin >> x;
		magic_heap.push(x);
	}

	int count = 0; //뿅망치 사용 횟수 저장할 변수

	while (t--) { //뿅망치 제한 횟수만큼 반복
		if (magic_heap.top() >= h) { //top이 센티보다 클 경우
			if (magic_heap.top() > 1) { 
				int k = magic_heap.top() / 2; //제일 위에 있는 값을 나누기 2
				magic_heap.pop(); //나누기 2하기 전의 값은 삭제
				magic_heap.push(k); //나누기 2한 값 삽입
				count++; //사용횟수 1 증가
			}
		}
	}

	//뿅망치 사용 후 키가 가장 큰 거인의 키를 max에 저장해둠
	int max = magic_heap.top();

	int check = 0; //0은 센티보다 키 크거나 같은 거인이 없는 경우

	for (int i = 0; i < magic_heap.size(); i++) {
		if (magic_heap.top() >= h) {
			//센티보다 크거나 같은 거인이 있으면
			check = 1; //1로 update
		}
		magic_heap.pop(); //top에 있는 값 삭제
	}

	switch (check) {
	case 0: //거인들이 모두 센티보다 작으면
		cout << "YES\n";  //YES, count 출력
		cout << count << '\n';
		break;
	case 1: //거인 중에 센티보다 크거나 같은 거인이 있으면
		cout << "NO\n";  //NO, max 출력
		cout << max << '\n';
		break;
	}

	return 0;
}
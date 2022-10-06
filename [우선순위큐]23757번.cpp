#include <iostream>  //c++ 입출력 헤더
#include <queue>	 //queue 헤더(우선순위 큐 이용하기 위해서)
#include <vector>	 //vector 헤더

using namespace std; //std 라이브러리 사용

int check(vector<int>& children, priority_queue<int>& present_heap) { //실망하는 아이가 있는지 체크하는 함수

	for (int i = 0; i < children.size(); i++) { //아이들 수만큼 반복
		if (present_heap.top() < children[i]) //가장 선물이 많이 담겨있는 상자의 선물수가 아이가 원하는 것보다 작다면 아이는 실망할 것
			return 0; //실망했으므로 0 리턴
		else { //가장 선물이 많이 담긴 상자에서 아이들이 원하는 만큼 꺼내갈 수 있는 경우
			int temp = present_heap.top() - children[i]; //아이들이 가져간 만큼 빼주고, 그값을 temp에 저장
			present_heap.pop(); //제일 위의 값 삭제
			present_heap.push(temp); //temp를 우선순위큐에 넣음
		}
	}
	return 1; //실망하지 않았으므로 1 리턴
}

int main() { //메인함수
	int n, m;  //차례대로 선물상자 개수, 아이들 명수
	cin >> n >> m;  //입력

	vector<int> children(n);  //벡터 초기화
	priority_queue<int> present_heap;  //힙 초기화

	int x; //x라는 변수 선언(선물 개수 입력받기 위해서)
	while (n--) { //상자의 개수만큼 반복
		cin >> x;  //상자안의 선물 개수 입력받기
		present_heap.push(x);  //선물 개수를 우선순위큐에 삽입
	}

	int y; //아이들 각자가 원하는 선물 개수 저장할 변수
	while (m--) { //아이들 명수만큼 반복
		cin >> y; //아이들 각자가 원하는 선물 개수 입력받기
		children.push_back(y); //벡터에 저장
	}

	int result = check(children, present_heap); //check함수를 통해 1 또는 0 리턴받기

	cout << result << '\n';  //결과값 출력

	return 0; //종료
}
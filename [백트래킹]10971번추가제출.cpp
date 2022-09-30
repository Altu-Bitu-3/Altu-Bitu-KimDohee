//라이브코딩 15649번에서 check 베열(벡터)를 이용해서 체크하는 로직을 참고하였습니다. 

#include <iostream> 

using namespace std; 

int cost[10][10];  //비용 함수
int n;   //도시 수
bool check[10] = { false };  //방문하지 않은 상태:false로 초기화
int result=1e8; //10의 6승 x 10 x 10 을 최댓값으로 설정

void calculateCost(int i, int j, int cnt, int csum) {  //i: 시작 도시, j: 인덱스, cnt: 방문한 도시 횟수, csum: 비용을 더해나갈 변수
	if (cnt == n) { //모든 도시 방문했을때(기저조건)
		if (cost[j][i] == 0) { //모든 도시 방문했는데, 처음으로 돌아갈 수 없는경우는
			return;				// 순회 불가
		}
		if (cost[j][i]>0) {//이동가능하면
			result = min(csum + cost[j][i], result); //최솟값 비교해서 최종비용으로 결정
		}
		return;   //함수 종료
	}

	for (int k = 0; k < n; k++) {  //k=0~n까지 돌면서 행렬의 모든 항 체크
		if ((check[k] == true) || (cost[j][k] == 0)) { //방문했던 곳이거나 이동할 수 없는 곳이면(cost[j][k]==0) 건너뛰기
			continue;
		}
		check[k] = true; //방문했으므로 true 대입
		calculateCost(i, k, cnt + 1, csum + cost[j][k]); //다음 인덱스 넣어서 호출
		check[k] = false; // 원래 상태로 돌려놓음
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {   //차례로 nxn행렬 입력받음(비용 입력) 
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	//연산
	for (int i = 0; i < n; i++) {
		//시작도시: i, 0부터 n까지 다른 지점에서 시작해보면서 비용 계산
		check[i] = true; //시작도시-true로 바꿈(방문했다는 뜻) 
		calculateCost(i, i, 1, 0); //차례로 시작도시, 위치, 방문한 도시의 수, 비용
		check[i] = false; //다시 false로 초기화(재사용(?) 위해) 
	}

	cout << result << '\n';   //최소비용 호출
	return 0;
}
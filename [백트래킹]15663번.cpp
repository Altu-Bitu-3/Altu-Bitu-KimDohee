//라이브코딩에서 진행한 두 문제의 로직을 이용하였습니다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m; //n개의 자연수 입력받기, m개 고르기

vector<int> v;  //입력받을 벡터
vector<int> num(SIZE);  //결과값 저장할 벡터
vector<bool> check(SIZE); //중복 확인할 벡터

void backtracking(int cnt) {  //cnt는 수열의 인덱스를 의미
	if (cnt == m) { //고르고자 하는 m개 만족할때(기저조건)
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int cnum=-1; //중복 체크하기 위한 변수, 바로 이전에 선택된 값들 저장

	for (int i = 0; i < n; i++) {  //i: 고르려는 수
		if ((!check[i]) && (v[i] != cnum)) { 
			//check의 값을 체크하는 것에서 그치지 않고
			//v[i]와 cnum을 비교해서 2 4 4 처럼 중복되는 숫자가 출력되지 않게 방지
			cnum = v[i]; 
			num[cnt] = v[i];
			check[i] = true;			
			backtracking(cnt + 1);
			check[i] = false; //다시 사용하기 위하여 원래상태로 돌려놓음
		}
	}

}

int main() {
	//입력
	cin >> n >> m;

	int k;

	for(int j=0;j<n;j++){
		cin >> k;  //0부터 n-1인덱스까지 숫자 입력받기
		v.push_back(k);
	}

	sort(v.begin(), v.end());  //오름차순 정렬


	//연산
	backtracking(0);

	return 0;
}
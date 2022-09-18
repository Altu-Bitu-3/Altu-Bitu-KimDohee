#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int avg(vector<int> &v) { //산술평균 구하기
	double average;   //평균과 sum모두 범위가 더 넓은 double로 지정
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	average = sum / v.size();
	return round(average);  //반올림함수 round()사용
}

int middle(vector<int>& v) {  //중앙값 구하기 
	sort(v.begin(), v.end()); //정렬
	int midindx; //중앙값이 위치한 인덱스 
	midindx = (v.size()-1) / 2; //벡터는 인덱스 0부터 시작하므로 v.size()-1해줘야함
	return v[midindx];
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) { //비교함수
	if (a.second == b.second)
		return a.first < b.first;   //빈도수 같은 경우 두번째로 작은 값을 왼쪽에 위치시키기
	return a.second > b.second;  //빈도수 다르면 내림차순으로 정렬(빈도수 큰값부터) 
}

int mode(int n, vector<int>& v) {  //최빈값 구하기
	map<int, int> m; //(value, 빈도수) 저장할 map

	for (int i = 0; i < n; i++) {
		if (m.find(v[i]) != m.end()) {  //map에 value가 이미 존재하면 빈도수 1 증가
			m[v[i]]++;
		}
		else {   //새로운 value가 들어오면 추가, 빈도수 1 대입
			m[v[i]] = 1;
		}
	}

	vector<pair<int, int>> vec(m.begin(), m.end()); //map을 vector로 이동
	
	sort(vec.begin(), vec.end(), cmp); //빈도수 기준 정렬
	
	if (vec.size() == 1) { //vec size가 1이면 밑에 else구문에서 오류가 나므로 따로 빼줌
		return vec[0].first;
	}

	if (vec[0].second != vec[1].second) {
		return vec[0].first;
	}
	else {
		return vec[1].first;
	}
}

int range(int n, vector<int>& v) { //range구하기
	sort(v.begin(), v.end());  //오름차순 정렬
	return (v.back() - v.front());
}

int main() {
	//입력
	int n;
	cin >> n;  //n은 홀수

	if (n % 2 == 1) {

		vector<int> vec(n, 0);

		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			vec[i] = k;
		}

		//출력
		cout << avg(vec) << '\n';
		cout << middle(vec) << '\n';
		cout << mode(n, vec) << '\n';
		cout << range(n, vec) << '\n';
	}

	return 0;
}
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	string name;
	string n_log;
	set<string> s;

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> name >> n_log;  //이름과 출입기록 순서대로 입력

		if (n_log == "enter") {  //enter입력되면 set에 이름 추가
			s.insert(name);
			continue;
		}
		if (n_log == "leave") { //leave입력되면 set에 이름 삭제
			s.erase(name);
		}
	}
	
	vector<string> vec(s.begin(), s.end()); //vector로 변환하여 역순 출력 진행

	for (int i = vec.size()-1; i >=0; i--) {
		cout << vec[i] << '\n';
	}

	return 0;
}
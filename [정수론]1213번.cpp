#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ans = "";  //결과를 저장할 string

void palindrome(vector<int>& v, int idx) {
	for (int i = 0; i < 26; i++) { //전반부 알파벳 채우기
		for (int j = 0; j < v[i] / 2; j++) { //빈도수 절반만큼 앞에 채우고, 나머지 절반은 뒤(후반부)에 채우기
			ans += (i + 'A');
		}
	}

	if (idx != -1) {  //가운데에 홀수개인 알파벳 추가
		ans += (idx + 'A');
	}

	for (int i = 25; i >= 0; i--) {  //후반부 알파벳 채우기
		for (int j = 0; j < v[i] / 2; j++) {
			ans += (i + 'A');
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	//입력
	string s;
	cin >> s;

	int cnt = 0; //홀수개인 알파벳 개수 저장할 변수
	int odd_idx = -1; //홀수개인 알파벳 index 저장할 변수
	vector<int> vec(26);

	for (int i = 0; i < s.size(); i++) { //알파벳 개수 세기
		vec[s[i] - 'A']++;
	}


	for (int i = 0; i < 26; i++) {  //홀수개인 알파벳 개수 세기
		if (vec[i] % 2 == 1) {
			cnt++;
			odd_idx = i;
		}
	}

	if (cnt >= 2) { //홀수개인 알파벳이 두 개 이상이면 팰린드롬 만들 수 없음(중앙에는 1개만 올 수 있기 때문에)
		cout << "I'm Sorry Hansoo";
	}
	else {
		palindrome(vec, odd_idx);  //빈도수 저장된 vec과 홀수개인 알파벳이 있는 경우를 위해 odd_idx도 같이 input
	}

	return 0;
}
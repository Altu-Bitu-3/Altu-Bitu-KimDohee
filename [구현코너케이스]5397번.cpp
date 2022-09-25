#include <iostream>
#include <list>

using namespace std;
list<char>::iterator cursor;

void keyLogger(string s, list<char>& l) {
	cursor = l.begin(); //커서를 list의 맨 앞에 위치시킴

	for (int i = 0; i < s.length(); i++) {  //벡터 모든 칸 하나씩 검사
		if ((s[i] == '<') && (cursor != l.begin())) { //커서가 list의 처음에 위치하면, 왼쪽으로 갈 수 없기 때문
			cursor--; //커서를 왼쪽으로 한칸
		}
		else if ((s[i] == '>') && (cursor != l.end())) {  //커서가 list의 맨오른쪽에 위치하면 오른쪽으로 갈 수 없기 때문
			cursor++;
		}
		else if ((s[i] == '-') && (cursor!=l.begin())) { //커서가 첫번째칸에 위치하면, 지울게 없음
			cursor = l.erase(--cursor); //커서 먼저 왼쪽으로 한칸 옮기고 그 자리에 있는 값 삭제
		}
		else if((s[i]!='<')&&(s[i]!='>')&&(s[i]!='-')){
			l.insert(cursor, s[i]);  //일반 알파벳 입력되면 그대로 list에 insert
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);


	int n; //테스트케이스의 개수
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		list<char> l;
		keyLogger(s, l);
		for (cursor = l.begin(); cursor != l.end(); cursor++) {  //차례대로 출력
			cout << *cursor;
		}
		cout << '\n';
	}

	return 0;
}
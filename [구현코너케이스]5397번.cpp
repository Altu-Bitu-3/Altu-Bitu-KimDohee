#include <iostream>
#include <list>

using namespace std;
list<char>::iterator cursor;

void keyLogger(string s, list<char>& l) {
	cursor = l.begin(); //Ŀ���� list�� �� �տ� ��ġ��Ŵ

	for (int i = 0; i < s.length(); i++) {  //���� ��� ĭ �ϳ��� �˻�
		if ((s[i] == '<') && (cursor != l.begin())) { //Ŀ���� list�� ó���� ��ġ�ϸ�, �������� �� �� ���� ����
			cursor--; //Ŀ���� �������� ��ĭ
		}
		else if ((s[i] == '>') && (cursor != l.end())) {  //Ŀ���� list�� �ǿ����ʿ� ��ġ�ϸ� ���������� �� �� ���� ����
			cursor++;
		}
		else if ((s[i] == '-') && (cursor!=l.begin())) { //Ŀ���� ù��°ĭ�� ��ġ�ϸ�, ����� ����
			cursor = l.erase(--cursor); //Ŀ�� ���� �������� ��ĭ �ű�� �� �ڸ��� �ִ� �� ����
		}
		else if((s[i]!='<')&&(s[i]!='>')&&(s[i]!='-')){
			l.insert(cursor, s[i]);  //�Ϲ� ���ĺ� �ԷµǸ� �״�� list�� insert
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);


	int n; //�׽�Ʈ���̽��� ����
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		list<char> l;
		keyLogger(s, l);
		for (cursor = l.begin(); cursor != l.end(); cursor++) {  //���ʴ�� ���
			cout << *cursor;
		}
		cout << '\n';
	}

	return 0;
}
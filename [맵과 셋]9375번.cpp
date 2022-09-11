#include <iostream>
#include <map>

using namespace std;

int main() {
	int n; //테스트케이스 수 

	//의상 수 입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; //의상 수
		cin >> num; //의상의 개수
		string name, type;
		map<string, int> clothes; //(의상 종류, 의상 개수)

		for (int j = 0; j < num; j++) {
			cin >> name >> type;
			if (clothes.find(type) == clothes.end()) { //새로운 type이 map에 들어오면
				clothes[type] = 1;
			}
			else
				clothes[type] ++; //type존재시에 개수 한개씩 증가
		}

		//각 type별로 존재하는 개수+1(1을 더해주는 경우는 안입는 경우 고려하기 위해서)
		//을 해서 type별로 다 곱해준 다음, 모두 다 안입는(알몸의 경우) 1가지 경우를 빼주면 된다. 
		int c_case = 1; 
		for (auto iter : clothes) {
			c_case = c_case * (iter.second + 1);
		}
		c_case--;
		cout << c_case << '\n';
	}

	return 0;
}
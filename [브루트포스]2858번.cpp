#include <iostream>
#include <vector>

using namespace std;

void sizeOfRoom(int r, int b, vector<int>& v) {
	//r, b는 각각 빨간, 갈색 타일의 개수, v는 가로 세로 길이 저장할 벡터
	int total_num = r+b;  //총 타일의 개수

	for (int i = 1; i <= total_num; i++) {
		//가로길이가 i, 세로길이가 total_num/i일때 빨간색, 갈색 타일의 개수 각각 구하기
		if (total_num % i == 0) { //가로i, 세로 total_num/i가 둘다 정수로 나눠떨어질때만 반복문 돌리기
			int r_temp = (i+(total_num/i))*2-4;  //(가로+세로)*2-4가 가장자리(빨간) 타일의 개수
			if (r_temp == r) { //주어진 빨간 타일의 개수(입력으로 받은)와 가로가 i일때 빨간타일의 수가 같다면 문제에서 요구하는 L의 값이 i가 됨
				v[0] = i;
				v[1] = total_num / i;
				break;
			}
		}
	}
}

int main() {
	//입력
	int r, b;
	cin >> r >> b;

	vector<int> vec(2, 0); //vec[0]: L , vec[1] : W 
	
	sizeOfRoom(r, b, vec);

	cout << max(vec[0], vec[1]) << " "<< min(vec[0], vec[1]) << '\n';

	return 0;
}
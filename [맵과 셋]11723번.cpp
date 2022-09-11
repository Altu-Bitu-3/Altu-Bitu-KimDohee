#include <iostream>
#include <set>

using namespace std;
//const int SIZE = 3*1e6;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; //�����ؾ� �ϴ� ������ �� 
    cin >> n;

    set<int> S;

    for (int i = 0; i < n; i++) {
        string s;
        int x;

        cin >> s;   //cmd �ޱ�

        if (s == "add") {
            cin >> x;
            if (S.find(x) == S.end()) {  //S�� x�� ���� ���
                S.insert(x);   //insert�Լ� ���
            }
            continue;
        }

        if (s == "remove") {
            cin >> x;
            if (S.find(x) != S.end()) {
                S.erase(x);   //erase�Լ� ���
            }
            continue;
        }

        if (s == "check") {
            cin >> x;
            cout << (S.find(x) != S.end()) << '\n';
            continue;
        }

        if (s == "toggle") {
            cin >> x;
            if (S.find(x) != S.end()) {  //S�� x�� ������ x ����
                S.erase(x);
            }
            else {
                S.insert(x);
            }
            continue;
        }

        if (s == "all") {
            S = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
            continue;
        }

        if (s == "empty") {
            S.clear();  //clear�Լ� �̿�
        }
    }

    return 0;
}

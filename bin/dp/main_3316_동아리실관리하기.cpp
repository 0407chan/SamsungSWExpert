#include<iostream>
#include<string>

const int MOD = 1000000007;
using namespace std;

int T, N, res;
string s;
int dp[16][10000];

int main() {

    scanf("%d\n", &T);

    for (int tc = 1; tc <= T; ++tc) {
        getline(cin, s);
        N = s.length();

        //ù�� ���� ó��
        int req = 1 << (s[0] - 'A');
        for (int i = 1; i < 16; ++i) {
            if ((req & i) >= 1 && (1 & i) >= 1)dp[i][0] = 1;
        }

        //��°������
        for (int day = 1; day < N; ++day) {
            //å����
            req = 1 << (s[day] - 'A');

            for (int comb = 1; comb < 16; ++comb) {
                dp[comb][day] = 0;
                //å���ڰ� ���Ե� ���տ� ����
                if ((req & comb) >= 1) {

                    for (int prevComb = 1; prevComb < 16; ++prevComb) {
                        //���� ����� �Ѹ� �̻� ���Ե� ������ ã��
                        if ((comb & prevComb) >= 1) {
                            //���� �ش� ������ ����� �� ������
                            dp[comb][day] = (dp[comb][day] + dp[prevComb][day - 1]) % MOD;
                        }
                    }
                }
            }
        }

        res = 0;
        for (int i = 1; i < 16; ++i) {
            res = (res + dp[i][N - 1]) % MOD;
        }
        printf("#%d %d\n", tc, res);
    }

    return 0;
}

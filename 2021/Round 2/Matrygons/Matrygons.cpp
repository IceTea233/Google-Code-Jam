#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

vector<int> prm;

void prepare() {
    prm.PB(2);
    for (int i=3; i<=1000000; i++) {
        bool flag = 0;
        for (int j=0; prm[j] * prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            prm.PB(i);
    }
}

int count(int x, int b) {
    int cnt = 0;
    while (x) {
        if (x % b == 1)
            cnt++;
        else if (x % b == 0) {
            //do nothing
        } else {
            return 0;
        }
        x /= b;
    }
    return cnt;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    prepare();
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        int ans = 1;
        for (int i=3; i<N; i++) {
            if (N % i == 0) {
                for (auto it : prm) {
                    if (it > N / i)
                        break;
                    int cnt = count(N / i, it);
                    if (cnt > ans) {
                        printf("i = %lld, prm: %lld, cnt = %lld\n", i, it, cnt);
                    }
                    ans = max(ans, cnt);
                }
            }
        }

        printf("Case #%lld: %lld\n", t, ans);
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//

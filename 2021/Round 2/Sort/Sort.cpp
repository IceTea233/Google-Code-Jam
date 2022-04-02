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

int M(int i, int j) {
    printf("M %lld %lld\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int S(int i, int j) {
    printf("S %lld %lld\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int D() {
    printf("D\n");
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T, N;

    cin >> T >> N;
    for(int t=1; t<=T; t++) {
        for (int i=1; i<N; i++) {
            int q = M(i, N);
            if (q > i) {
                S(i, q);
            }
        }
        int chk = D();
        if (chk == -1)
            return 0;
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

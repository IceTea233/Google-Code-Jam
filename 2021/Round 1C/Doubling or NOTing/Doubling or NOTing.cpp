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

int NOT(int x) {
    if (x == 0)
        return 1;
    int y = x;
    for (int i=0; (1<<i) <= x; i++) {
        y ^= (1<<i);
    }
    // printf("%lld -> %lld\n", x, y);
    return y;
}

int ans;
void guess(int s, int e, int step) {
    // printf("(%lld, %lld, %lld) %lld\n", s, e, st);
    if (s == e) {
        // printf("ans upd\n");
        ans = step;
    }

    if (step == ans)
        return;

    guess(s*2, e, step+1);
    guess(NOT(s), e, step+1);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() > 8)
            exit(-1);
        int S = 0, E = 0;
        for (auto it : s1) {
            S <<= 1;
            if (it == '1')
                S |= 1;
        }
        for (auto it : s2) {
            E <<= 1;
            if (it == '1')
                E |= 1;
        }

        // cout << S << " " << E << "\n";
        ans = 20;
        guess(S, E, 0);
        printf("Case #%lld: ", t);
        if (ans == 20) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%lld\n", ans);
        }
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

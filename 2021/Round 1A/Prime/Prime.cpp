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
const int maxn = 1e2 + 7;

int M;
int sum;
int P[maxn] = {};
int N[maxn] = {};

bool okay(int x) {
    int mul = x;
    int cal = sum;
    int cnt[maxn] = {};

    for (int i=1; i<=M; i++) {
        while (mul % P[i] == 0) {
            cnt[i]++;
            cal -= P[i];
            mul /= P[i];
        }
    }

    if (mul > 1)
        return 0;

    // printf("%lld : %lld\n", cal, x);

    for (int i=1; i<=M; i++) {
        if (cnt[i] > N[i])
            return 0;
    }
    return cal == x;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> M;
        sum = 0;
        for (int i=1; i<=M; i++) {
            cin >> P[i] >> N[i];
            sum += P[i] * N[i];
        }

        int ans = 0;
        for (int i=max(2LL, sum-30000); i<sum; i++) {
            if (okay(i))
                ans = i;
        }
        cout << "Case #" << t << ": " << ans << "\n";
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

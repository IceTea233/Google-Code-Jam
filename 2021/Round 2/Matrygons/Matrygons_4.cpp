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
const int maxn = 1e6 + 7;
const int maxm = 1e6;

vector<int> prm;

int ans = 1;
void guess(int x, int dep) {
    // printf("(%lld, %lld)\n", x, dep);
    ans = max(ans, dep);
    for (int i = (dep == 0 ? 3 : 2); i*i <= x; i++) {
        if (x % i == 0) {
            guess(x / i - 1, dep + 1);
            guess(i - 1, dep + 1);
        }
    }
    if (x > 1)
        guess(1, dep+1);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        ans = 1;
        guess(N, 0);

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

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
const int maxn = 27;

int U[maxn] = {};
int V[maxn] = {};
int N, A, B;

bool chk(int x) {

    for (int i=1; i<=N; i++) {
        V[i] = U[i];
    }

    priority_queue<int> pq;
    pq.push(x);

    int tag = 0;
    for (int i=1; i<=N; i++) {
        if (V[i])
            tag = i;
    }
    while (!pq.empty() && tag) {
        int now = pq.top();
        pq.pop();
        if (now > tag) {
            if (now-A > 0)
                pq.push(now-A);
            if (now-B > 0)
                pq.push(now-B);
        } else if (now == tag) {
            V[tag]--;
        }

        while (tag > 0 && !V[tag])
            tag--;
    }

    if (tag)
        return 0;
    else
        return 1;
}

int BS(int l, int r) {
    printf("search(%lld, %lld)\n", l, r);
    if (l == r)
        return l;

    int m = (l + r) / 2;
    if (chk(m))
        return BS(l, m);
    else
        return BS(m+1, r);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {

        cin >> N >> A >> B;
        for (int i=1; i<=N; i++)
            cin >> U[i];

        int ans = BS(1, 30LL);
        if (ans == 30) {
            printf("Case #%lld: IMPOSSIBLE\n", t);
        } else {
            printf("Case #%lld: %lld\n", t, ans);
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

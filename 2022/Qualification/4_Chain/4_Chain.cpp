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
const int maxn = 2e5 + 7;

int F[maxn] = {};
int to[maxn] = {};
vector<int> from[maxn];

int tag[maxn] = {};

vector<int> stk;
void dfs1(int x, int p) {
    tag[x] = 1;
    stk.PB(x);

    int y = to[x];
    if (tag[y] == 0) {
        dfs1(y, x);
    } else if (tag[y] == 1) {
        int maxi = F[y];
        while (stk.back() != y) {
            int cur = stk.back();
            stk.PP();
            tag[cur] = 2;
            maxi = max(maxi, F[cur]);
            for (auto it : from[cur]) {
                if (tag[it] == 0) {
                    to[it] = y;
                    from[y].PB(cur);
                }
            }
        }
        to[y] = 0;
    }
    tag[y] = 2;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        for (int i=1; i<=N; i++) {
            from[i].clear();
        }
        memset(tag, 0, sizeof(int) * (N * 2 + 1));

        for (int i=1; i<=N; i++) {
            cin >> F[i];
        }

        for (int i=1; i<=N; i++) {
            cin >> to[i];
            from[to[i]].PB(i);
        }

        for (int i=1; i<=N; i++) {
            if (tag[i] == 0) {
                dfs1(i, i);
            }
        }
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/

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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int F[maxn] = {};
int to[maxn] = {};
vector<int> keep[maxn];

int in[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        for (int i=0; i<=N; i++) {
            keep[i].clear();
            in[i] = 0;
        }

        for (int i=1; i<=N; i++) {
            cin >> F[i];
        }
        for (int i=1; i<=N; i++) {
            cin >> to[i];
            in[to[i]]++;
        }

        queue<int> que;
        for (int i=1; i<=N; i++) {
            if (in[i] == 0) {
                que.push(i);
                keep[i].PB(0);
            }
        }

        de(1) printf("okay\n");

        int ans = 0;
        while (que.size()) {
            int cur = que.front();
            de(1) printf("cur = %lld\n", cur);
            que.pop();
            if (cur == 0)
                continue;
            if (--in[to[cur]] == 0) {
                que.push(to[cur]);
            }

            sort(all(keep[cur]));
            while (keep[cur].size() > 1) {
                ans += keep[cur].back();
                de(1) printf("ans += %lld\n", keep[cur].back());
                keep[cur].PP();
            }
            keep[to[cur]].PB(max(keep[cur][0], F[cur]));
            de(1) printf("keep[%lld] pushed %lld\n", to[cur], max(keep[cur][0], F[cur]));
        }

        while (keep[0].size()) {
            ans += keep[0].back();
            de(1) printf("ans += %lld\n", keep[0].back());
            keep[0].PP();
        }

        printf("Case #%lld: %lld\n", t, ans);
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

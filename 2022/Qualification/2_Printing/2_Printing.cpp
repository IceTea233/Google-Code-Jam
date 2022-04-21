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


int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int C[3], M[3], Y[3], K[3];
        for (int j=0; j<3; j++) {
            cin >> C[j] >> M[j] >> Y[j] >> K[j];
        }

        int rem = 1000000;
        int pc = 0, pm = 0, py = 0, pk = 0;

        pc = min({rem, C[0], C[1], C[2]});
        rem -= pc;
        pm = min({rem, M[0], M[1], M[2]});
        rem -= pm;
        py = min({rem, Y[0], Y[1], Y[2]});
        rem -= py;
        pk = min({rem, K[0], K[1], K[2]});
        rem -= pk;

        printf("Case #%lld: ", t);
        if (rem == 0) {
            printf("%lld %lld %lld %lld\n", pc, pm, py, pk);
        } else {
            printf("IMPOSSIBLE\n");
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

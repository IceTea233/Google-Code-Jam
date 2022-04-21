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
        int N;
        cin >> N;

        vector<int> A(N);


        for (i=0; i<=29; i++) {
            A[i] = (1 << i);
        }

        for (int i=30; i<=99; i++) {
            A[i] = 1000000000 + (30 - i);
        }

        for (int i=0; i<=99; i++) {
            printf("%lld ", A[i]);
        }
        printf("\n");
        fflush(stdout);

        vector<int> B(N);
        for (int i=0; i<N; i++) {
            cin >> B[i];
        }

        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += A[i];
            sum += B[i];
        }

        int goal = sum / 2;
        vector<int> ans;
        for (i=0; i <= N - 1; i++) {
            if (goal - B[i] >= 0) {
                ans.PB(B[i]);
                goal -= B[i];
            }
        }
        for (j=N-1; j >= 0; j--) {
            if (goal - A[j] >= 0) {
                ans.PB(A[j]);
                goal -= A[j];
            }
        }

        for (auto it : ans) {
            printf("%lld ", it);
        }
        printf("\n");
        fflush(stdout);
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

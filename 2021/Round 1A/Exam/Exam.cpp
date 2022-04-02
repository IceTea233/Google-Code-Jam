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
const int maxn = 3 + 7;

struct frac {
    int u;
    int d;

    void refresh() {
        if (u == 0)
            d = 1;
        else {
            int gcd = __gcd(u, d);
            u /= gcd;
            d /= gcd;
        }
    }

    frac operator +(frac b) {
        frac ret;
        ret.d = d * b.d;
        ret.u = u * b.d + b.u * d;
        ret.refresh();
        return ret;
    }
    frac operator -(frac b) {
        frac ret;
        ret.d = d * b.d;
        ret.u = u * b.d + b.u * d;
        ret.refresh();
        return ret;
    }
    frac operator *(frac b) {
        frac ret;
        ret.d = d * b.d;
        ret.u = u * b.u;
        ret.refresh();
        return ret;
    }

    frac operator /(frac b) {
        frac ret;
        ret.d = d * b.u;
        ret.u = u * b.d;
        ret.refresh();
        return ret;
    }

    void value() {
        cout << u << '/' << d;
    }
};

frac max(frac a, frac b) {
    int u1 = a.u * b.d;
    int u2 = b.u * a.d;
    if (a.u >= b.u)
        return a;
    else
        return b;
}

string A[maxn];
int S[maxn];

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, Q;
        cin >> N >> Q;
        for (int i=1; i<=N; i++) {
            cin >> A[i] >> S[i];
        }

        string ans;
        frac maxi = {1, 0};
        for (int i=0; i<Q; i++) {
            frac T = {0, 1}, F = {0, 1};
            int sum = 0;
            for (int i=1; i<=N; i++) {
                sum += S[i];
            }

            for (int j=1; j<=N; j++) {
                if (A[j][i] == 'T')
                    T = T + (frac){ A[j][i], S[j]} * (frac){1, 3} * (frac){1, Q};
                else
                    T = T + (frac){ A[j][i], Q-S[j]} * (frac){1, 3} * (frac){1, Q};
            }
            for (int j=1; j<=N; j++) {
                if (A[j][i] == 'F')
                    F = F + (frac){ A[j][i], S[j]} * (frac){1, 3} * (frac){1, Q};
                else
                    F = F + (frac){ A[j][i], Q-S[j]} * (frac){1, 3} * (frac){1, Q};
            }
            T.value();
            cout << "\n";
            F.value();
            cout << "\n";

            maxi = maxi + max(T, F);
        }
        maxi.value();
        cout << "\n";
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

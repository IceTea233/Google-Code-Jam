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

int T, N, Q;

int query(int i, int j, int k) {
    printf("%lld %lld %lld\n", i, j, k);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int answer(vector<int> &arr) {
    for (int i=1; i<=N; i++)
        printf("%lld ", arr[i]);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

void display(vector<int> &arr) {
    printf(">>>");
    for (auto it : arr)
        printf(" %lld", it);
    printf("\n");
}

vector<int> keep;

int search(int l, int r, int x) {
    de(1) printf("search(%lld, %lld)\n", l, r);
    if (r - l == 1)
        return l;
    else if (r - l == 2) {
        if (l == 0) {
            int q = query(keep[l+1], keep[l+2], x);
            if (q == x)
                return l+1;
            else
                return l;
        } else {
            int q = query(keep[l], keep[l+1], x);
            if (q == x)
                return l;
            else
                return l+1;
        }
    }

    int d = (r-l) / 3;
    int x1 = l+d;
    int x2 = l+d*2;
    int q = query(keep[x1], keep[x2], x);
    if (q == keep[x1])
        return search(l, x1, x);
    else if (q == x)
        return search(x1, x2, x);
    else
        return search(x2, r, x);
}

int32_t main() {
    int i,j;

    scanf("%lld %lld %lld", &T, &N, &Q);
    for (int t=1; t<=T; t++) {
        keep.clear();
        keep.PB(0);
        keep.PB(1);
        keep.PB(2);
        keep.PB(N+1);
        for (int i=3; i<=N; i++) {
            de(1) display(keep);
            int idx = search(0, keep.size()-1, i);
            keep.insert(begin(keep)+idx+1, i);
        }
        de(1) display(keep);
        int valid = answer(keep);
        if (valid == -1)
            exit(0);
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

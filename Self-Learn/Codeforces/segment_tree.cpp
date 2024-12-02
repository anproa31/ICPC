#include<bits/stdc++.h>
using namespace std;

void update(int id, int l, int r, int i, int v) {
    if(i < l || i > r) {
        return;
    }

    if(l == r) {
        ST[id] == v;
        return;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid + 1, r, i, v);


    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}

void get(int id, int l, int r, int u, int v) {
    if(u < l || v > r) return;
    if(u <= l && r <= v) return ST[id]; 

    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    return 0;
}
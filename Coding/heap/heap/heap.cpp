#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 +5;

void swim(int *A, int id) {
    int par=(id-1)/2;

    while(par>=0 && A[par] > A[id]) {
        swap(A[par],A[id]);
        id=par;
        par=(par-1)/2;
    }
}

void build_heap(int *A, int N) {
    for(int i=1; i<N; i++) {
        swim(A,i);
    }
}

int main() {
    int N=10;
    int A[N];
    //swap(A[1],A[3]);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }
    build_heap(A,N);
    for(int i=0; i<N; i++) {
        cout<<A[i]<<" ";
    }
    return 0;
}

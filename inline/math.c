#include "math.h"

inline int power2(int num) {
    return num * num;
}

int power(int n,int p) {
    int r = 1;
    for(int i = 0; i < p; i++) {
            r *= n;
    }

    return r;
}
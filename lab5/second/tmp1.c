#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "tmp1.h"

float SinIntegral(float A, float B, float e){
        float x;
        if(A > B){
                float tmp = A;
                A = B;
                B = tmp;
        }

        if(B - A <= e){
                float x0 = sinf(A);
                float x1 = sinf(A);
                return (x0 + x1) / 2 * (B - A);
        }

        while(A + e <= B){
                float x0 = sinf(A);
                float x1 = sinf(B);
                x = (x0 + x1) / 2;
                A = A + e;
        }

        x = x * e;

        if (A + e != B){
                float x0 = sinf(A);
                float x1 = sinf(B);
                x = x + (x0 + x1) / 2 * (B - A);
        }

        return x;
}

char* translation(long x){
        char* s = malloc(sizeof(int)*8);
        int p = 0;
        while(x > 0){
                s[p] = '0' + x % 3;
                x = x / 3;
                p++;
        }
        s[p] = '\0';

        long tmp;

        for (int i = 0; i < p/2; i++){
                tmp = s[i];
                s[i] = s[p-1];
                s[p-1] = tmp;
        }

        return s;
}
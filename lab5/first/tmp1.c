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
                return sinf(A) * (B - A);
        }

        while(A + e <= B){
                x = x + sinf(A);
                A = A + e;
        }

        x = x * e;

        if (A + e != B){
                x = x + sinf(A) * (B - A);
        }

        return x;
}

char* translation(long x){
        char* s = malloc(sizeof(int)*8);
        int p = 0;
        while(x > 0){
                s[p] = '0' + x % 2;
                x = x / 2;
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
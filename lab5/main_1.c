#include <stdio.h>
#include <stdlib.h>

#include "first/tmp1.h"

int main(){
        int x;
        float arg1, arg2, arg3;
        while(scanf("%d", &x) != EOF){
                if (x == 1){
                        if (scanf("%f %f %f", &arg1, &arg2, &arg3) < 3) {
                        printf("WRONG INPUT\n");
                        return 1;
                }
                printf("%f\n", SinIntegral(arg1, arg2, arg3));
                }

                else if (x == 2){
                        if (!(scanf("%f", &arg1))) {
                        printf("WRONG INPUT\n");
                        return 1;
                }
                printf("%s\n", translation(arg1));
                }

                else{
                        printf("WRONG INPUT\n");
                        return 1;
                }
        }
        return 0;
}
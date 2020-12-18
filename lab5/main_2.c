#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>

#define LIB1 "./lib/first/lib1.so"
#define LIB2 "./lib/second/lib2.so"

int main(){
        int l = 1;
        void *handle = dlopen(LIB1, RTLD_LAZY);

        if (dlerror() != NULL){
                printf("DLOPEN ERROR");
                return 1;
        }

        int x;
        float arg1, arg2, arg3;

        while(scanf("%d", &x) != EOF){
                if(x == 0){
                        if(l == 1){
                                l = 2;
                                handle = dlopen(LIB2, RTLD_LAZY);
                        }

                        else{
                                l = 1;
                                handle = dlopen(LIB1, RTLD_LAZY);
                        }

                        if (dlerror() != NULL){
                                printf("DLOPEN ERROR");
                                return 1;
                        }
                        printf("LIBRARY IS CHANGE");
                }

                else if(x == 1){
                        if (scanf("%f %f %f", &arg1, &arg2, &arg3) != 3) {
                                printf("WRONG INPUT");
                                return 1;
                        }

                        float (*i) (float, float, float);
                        i = dlsym(handle, "SinIntegral");
                        if (i == NULL) {
                                printf("DLSUM ERROR");
                                return 1;
                        }
                        printf("%f\n", SinIntegral(arg1, arg2, arg3));
                }

                else if(x == 2){
                        if (!(scanf("%f", &arg1))) {
                                printf("WRONG INPUT");
                                return 1;
                        }

                        float (*t) (float);
                        t = dlsym(handle, "translation");
                        if (t == NULL) {
                                printf("DLSUM ERROR");
                                return 1;
                        }
                        printf("%s\n", translation(arg1));
                }
                else{
                        printf("WRONG INPUT\n");
                        return 1;
                }
        }

        dlclose(handle);


        return 0;
}
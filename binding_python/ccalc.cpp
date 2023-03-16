#include <stdio.h>
#include <math.h>
#include <cstdio>

// // g++ cmult.cpp -o libcmult.so -Db_pie=true -Wl,-e, -shared
extern "C" { 

    float cmult(float int_param, float float_param) {
        float return_value = int_param * float_param;
        // printf("%f", return_value);
        return return_value;
    }

    float cdiv(float int_param, float float_param){
        float return_value = int_param / float_param;   
        return return_value;
    }

    float csum(float int_param, float float_param){
        float return_value = int_param + float_param;
        return return_value;
    }

    float csub(float int_param, float float_param){
        float return_value = int_param - float_param;
        return return_value;
    }

}



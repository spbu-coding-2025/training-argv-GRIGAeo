#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool argument_processing(const char* argv, const char* prefix, int* var);

int main(int argc, char* argv[]){
    int lower_bound = 0;
    int upper_bound = 0;
    bool is_lower = false;
    bool is_upper = false;

    for (int i = 1; i < argc; i ++){
        if (argument_processing(argv[i], "--lower_bound=", &lower_bound)){
            is_lower = true;
        }
        else if (argument_processing(argv[i], "--upper_bound=", &upper_bound)){
            is_upper = true;
        }
        else{
            fprintf(stderr, "No flags found");
            return 1;
        }
    }

    if (!is_lower){
        fprintf(stderr, "Flag lower bound is missing");
        return 1;
    }
    
    if (!is_upper){
        fprintf(stderr, "Flag upper bound is missing");
        return 1;
    }

    if (lower_bound > upper_bound){
        fprintf(stderr, "The lower bound is greater than the upper bound");
        return 1;
    }

    for (int k = lower_bound; k <= upper_bound; k ++){
        printf("%d", k);
        if (k != upper_bound){
            printf(" ");
        }
    }

    return 0;

    
}

bool argument_processing(const char* argv, const char* prefix, int* var){
    size_t len_prefix = strlen(prefix);
    
    if (strncmp(argv, prefix, len_prefix) == 0){
        *var = atoi(argv + len_prefix);
        return true;
    }
    return false;
}
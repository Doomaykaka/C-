#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int position;
} SearchResult;

int worker() {
    int count = 0;
    printf("Input numbers count:\n");
    scanf("%d", &count);

    int *nums = (int*) malloc(count * sizeof(int));

    if(nums == 0){
        return -1;
    }

    printf("Input numbers:\n");
    for(int i = 0; i < count; i++){
        scanf("%d", nums + i);
    }

    int number_to_find = 0;
    printf("Input number to find:\n");
    scanf("%d", &number_to_find);

    for(int i = 0; i < count; i++){
        if(nums[i] == number_to_find){
            printf("I find number %d on position %d\n", number_to_find, i);

            SearchResult programm_result;
            programm_result.number = number_to_find;
            programm_result.position = i;

            return 0;
        }
    }

    free(nums);

    printf("I find number %d on position -1\n", number_to_find);
}

void run(int (*callback) (void)){
    callback();
}

int main(int argc, char** argv){
    for(int i = 1; i < argc; i++){
        printf("Param #%d %s\n", i, argv[i]);
    }

    run(worker);
}

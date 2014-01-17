#include "TreeCalc.h"
#define OPERATORS "/+-*"
int main(){
    char str[] = "heloo";
    printf("%d\n", strlen(str));
    if (all_unique(str))
        printf("All unique\n");
    else printf("are dupes\n");


}
	
int all_unique(char * word){
    printf("Input = %s\n", word);
    int arr[256] = {0};
    int i;
    for (i = 0; i <= strlen(word) - 1; i++) {
        int val = word[i] - '0';
        if (arr[val])
            return 0;
        arr[val] = 1;
    }
    return 1;
}

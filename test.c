#include <stdio.h>
#include <stdlib.h>

void int2str(int n, char *s){
    char *p = s, temp;
    while(n){
        *s = n%10+'0';
        n/=10;
        s++;
    }

    *s = '\0';
    s--;

    for(; p<s; p++, s--){
        temp = *p; 
        *p = *s;
        *s = temp;
    }
}

int str2int(char *s){
    int result = 0;
    int power = 1;
    int num_stack[100];
    int i = 0;
    while(*s != '\0'){
        printf("got from thingy!!: %d %d\n", *s-'0', i);
        num_stack[i] = *s-'0';
        //printf("num stack: %d\n", num_stack[i]);
        s++;
        i++;
    }
    i--;
    while(i >= 0){
        printf("num stack: %d\n", num_stack[i]);
        result += power * num_stack[i];
        printf("result: %d %d %d\n", power, num_stack[i], result);
        power *= 10;
        i--;
    }
    return result;
}

int main(int argc, char *argv[]) {
    char str[100];
    int a = 4321;
    char str2[100] = "143250";
    int2str(a, str);
    printf("%s\n", str);
    printf("%d\n", str2int(str2));
}
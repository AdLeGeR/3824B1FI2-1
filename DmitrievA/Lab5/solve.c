#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX_SIZE 50

void flush(){
    int tc;
    while ((tc = getchar()) != '\n' && tc != EOF){}
}
void flushc(char c){
    if (c == '\n'){
        return;
    }
    flush();
}

typedef struct {
    char *name;
    int age;
} human;

void shell_sort(human *mas, int len){
    for(int s = len/2; s > 0; s/=2 ){
        for(int i = s; i < len; i++){
            for(int j = i-s; j >= 0 && mas[j].age > mas[j+s].age; j-=s){
                human temp = mas[j];
                mas[j] = mas[j+s];
                mas[j+s] = temp;
            }
        }
    }
}

void poryadok_sort(human *mas, int len){
    human *mas2 = calloc(len, sizeof(human));
    int hm[256];
    for(int i = 0; i<sizeof(int); i++){
        for(int i = 0; i < 256; i++){
            hm[i] = 0;
        }
        for(int j = 0; j < len; j++){
            char byte = *(((char*)&mas[j].age)+i);
            hm[byte]++;
        }
        int s = 0;
        for(int j = 0; j < 256; j++){
            int temp = hm[j];
            hm[j] = s;
            s+=temp;
        }
        for(int j = 0; j < len; j++){
            char byte = *(((char*)&mas[j].age)+i);
            mas2[hm[byte]] = mas[j];
            hm[byte]++;
        }
        for(int j = 0; j < len; j++){
            mas[j] = mas2[j];
        }
    }
    free(mas2);
}

void fast_sort(human *a, int len){
    if(len <= 1){
        return;
    }
    int i= 0;
    int j = len-1;  
    int pivot = a[(j+i)/2].age;
    while(1){
        while (a[i].age < pivot)
        {
            i++;
        }
        while (a[j].age > pivot)
        {
            j--;
        }
        if( i >= j){
            break;
        }
        human temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    fast_sort(a+(j+1), len - j -1);
    fast_sort(a, j - 1);
}

int main(){
    int incorrect = 0;
    FILE *fp;
    fp = fopen("People_in.txt", "r");
    human people[50];
    for(int i = 0; i < 50; i++){
        people[i].name = &"";
    }
    char c = 0;
    int count = 0;
    while (c != EOF || count == 50)
    {
        int n = 50;
        int i = 0;
        char *name = malloc(n);
        while((c = fgetc(fp)) != ' ' && c != EOF){
            name[i] = c;
            i++;
            if(i == n-1){
                n*= 2;
                char *name2 = malloc(n);
                for(int j = 0; j < i; ++j){
                    name2[j] = name[j];
                }
                free(name);
                name = name2;
            }
        }
        name[i] = '\0';
        if(c == EOF){
            break;
        }
        int age = 0;
        while((c = fgetc(fp)) != '\n' && c != EOF){
            age = age*10 + (c - '0');
        }
        people[count].age = age;
        people[count].name = name;
        count++;
    }
    fclose(fp);
    human cpeople[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++) cpeople[i] = people[i];
    while(1){
        printf("Choose algoritm of sort:\n1 - fast Hoar sort\n2 - poryadok sort\n3 - Shell sort\n");
        int t;
        int n;
        incorrect = 0;
        do
        {
            if(incorrect) printf("Type number from 1 to 3:");
            t = scanf("%d", &n);
            incorrect = 1;
            flush();
        } while (t != 0 && (n < 1 || n > 3));
        switch(n) 
        {
            case 1:
                t = clock();
                fast_sort(people, count);
                t -= clock();
                break;
            case 2:
                t= clock();
                poryadok_sort(people, count);
                t -= clock();
                break;
            case 3:
                t = clock();
                shell_sort(people, count);
                t -= clock();
                break;
        }
        fp = fopen("People_out.txt", "w");
        for(int i = 0; i < count; i++){
            fprintf(fp, "%s %d\n", people[i].name, people[i].age);
        }
        fclose(fp);
        printf("Result:\n");
        for(int i = 0; i < count; i++){
            printf("%s %d\n", people[i].name, people[i].age);
        }
        printf("time of sort: %d clocks, %f secs\n", t, (double)t/CLOCKS_PER_SEC);
        printf("would yppu want to choose another sort or exit? Type C(choose another sort) or E(exit): ");
        incorrect = 0;
        do{
            if(incorrect) printf("Type C or E: ");
            c = toupper(getchar());
            flushc(c);
            incorrect = 1;
        }while(c != 'C' && c != 'E');
        if(c == 'E') break;
    }
}
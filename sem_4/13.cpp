#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game {
    char name[50];
    float rating;
};

int cmp(const void* a, const void* b) {
    struct game* ga = (struct game*)a;
    struct game* gb = (struct game*)b;
    if (gb->rating > ga->rating) return 1;
    if (gb->rating < ga->rating) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%i", &n);
    
    struct game games[100];
    
    for (int i = 0; i < n; i++) {
        char name[50];
        char temp;
        
        scanf("%[^:]", name); 
        scanf("%c", &temp);
        
        int k;
        scanf("%i", &k);
        
        int sum = 0;
        int rate;
        for (int j = 0; j < k; j++) {
            scanf("%i", &rate);
            sum += rate;
        }
        
        strcpy(games[i].name, name);
        games[i].rating = (float)sum / k;
    }
    
    qsort(games, n, sizeof(struct game), cmp);
    
    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].name, games[i].rating);
    }
    
    return 0;
}
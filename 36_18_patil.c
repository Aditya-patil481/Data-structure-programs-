#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trie{
    int end;
    struct trie* child[26];
};

struct trie* getnode(){
    struct trie* t = (struct trie*)malloc(sizeof(struct trie));
    t->end = 0;
    for(int i=0;i<26;i++) t->child[i] = NULL;
    return t;
}

void insert(struct trie* root, char word[]){
    struct trie* curr = root;
    for(int i=0; word[i]; i++){
        int idx = word[i] - 'a';
        if(curr->child[idx] == NULL)
            curr->child[idx] = getnode();
        curr = curr->child[idx];
    }
    curr->end = 1;
}

int search(struct trie* root, char word[]){
    struct trie* curr = root;
    for(int i=0; word[i]; i++){
        int idx = word[i] - 'a';
        if(curr->child[idx] == NULL)
            return 0;
        curr = curr->child[idx];
    }
    return curr->end;
}

int main(){
    struct trie* root = getnode();
    int ch;
    char word[50];

    while(1){
        printf("\n1.Insert\n2.Search\n3.Exit\nEnter choice: ");
        scanf("%d",&ch);

        if(ch == 3) break;

        printf("Enter word: ");
        scanf("%s", word);

        if(ch == 1){
            insert(root, word);
            printf("Inserted\n");
        }
        else if(ch == 2){
            if(search(root, word))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
    }
    return 0;
}
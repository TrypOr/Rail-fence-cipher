#include<stdio.h>
#include<string.h>
#include <assert.h>

/*Rail fence encryption function */
void rail_fence_encr(char* plaintext,int rails);
/*Rail fence decryption function */
void rail_fence_decr(char* ciphertext,int rails);

void rail_fence_encr(char* plaintext,int rails){
int txtsize,i, j, k = -1, row = 0, col = 0;
txtsize = strlen(plaintext);
char array_rail[rails][txtsize]; /*2D array to use rail fence in*/
 /*Filling the 2D array with \0*/
    for(i = 0; i < rails; ++i)
        for(j = 0; j < txtsize; ++j)
            array_rail[i][j] = '\0';
    /*Setting the word inside the array*/
    for(i = 0; i < txtsize; ++i){
        array_rail[row][col++] = plaintext[i];
        
        if(row == 0 || row == rails-1){
            k= k * (-1);
        }
        row = row + k;
    }

    printf("Rail fence cipher encrypted word is ");
  /*Printing the encrypted word*/
    for(i = 0; i < rails; ++i){
        for(j = 0; j < txtsize; ++j){
            if(array_rail[i][j] != '\0'){
               printf("%c", array_rail[i][j]);
            }
        }
    }

}

void rail_fence_decr(char ciphertext[],int rails){
 int txtsize,i, j, k = -1, row = 0, col = 0,l=0;
txtsize = strlen(ciphertext);
char array_rail[rails][txtsize]; /*2D array to use rail fence in*/
 /*Filling the 2D array with \0*/
    for(i = 0; i < rails; ++i){
        for(j = 0; j < txtsize; ++j){
            array_rail[i][j] = '\n';
        }
    }
    /*Doing the same with encryption to recreate the array rail,by putting @ where the letters would go*/
    for(i = 0; i < txtsize; ++i){
        array_rail[row][col++] = '@';
 
        if(row == 0 || row == rails-1){
            k= k * (-1);
        }
        row = row + k;
    }
 /*Replacing the @ with each letter of plaintext*/
    for(i = 0; i < rails; ++i){
        for(j = 0; j < txtsize; ++j){
            if(array_rail[i][j] == '@'){
                array_rail[i][j] = ciphertext[l++];
            }
        }
    }
    /*Resetting in order to print*/
    row = 0;
    col=0;
    k = -1;
 
    printf("\nRail fence cipher decrypted word is  ");
 /*Printing the decrypted word*/
    for(i = 0; i < txtsize; ++i){
        printf("%c", array_rail[row][col++]);
 
        if(row == 0 || row == rails-1){
            k= k * (-1);
        }
        row = row + k;
    }
}
/*Main to test rail fence cipher*/
int main(void){
    int rails;
    char test[] = "Hello World!";
    char en_test[]="HWe o!lordll";
    /*RAIL FENCE CIPHER TEST 1*/
    rails=4;
    printf("RAIL FENCE CIPHER TEST:\n");
    rail_fence_encr(test, rails);
    rail_fence_decr(en_test, rails);

    return 0;
}
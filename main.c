/* 
Jiajia Yang
C3314189
Engg1003 Assignment 1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CaesarEn( char *message, char *output, int rotationAmount);//caesar cipher encryption function prototype
int CaesarDe( char *message, char *output, int rotationAmount);//caesar cipher decryption function prototype
int SubEn( char *message, char *output, const char *key); //substitution Encryption function prototype
int SubDe( char *message, char *output, const char *key); //substitution Decryption function prototype

int main(){
    FILE *inputCode, *outputCode;
    inputCode = fopen("inputCode.txt", "r");
    outputCode = fopen("outputCode.txt", "w");
    if (inputCode == NULL)
    perror("File Input");
    int i,j,k,choice;
    float rotationAmount;
    char message[1024],output[1024],key[30];
    char *point;
    rotationAmount = strtol(key, &point, 10);
    
    
    //make a selection menu for console 
    printf("Please make a selection\n");
    printf("1. Encryption with a rotation cipher key:\n");
    printf("2. Decryption with a rotation cipher key:\n");
    printf("3. Encryption with a substitution cipher given plain text and key:\n");
    printf("4. Decryption with a substitution cipher given plain text and key:\n");
    scanf ("%c",&choice);
    while ((getchar()) != '\n');
    switch(choice){
        case 1:
            printf("You have chosen rotation cipher encryption\n");
            printf("Enter a key (integer between [0,25])\n");
            scanf("%d", &rotationAmount);
            CaesarEn(message, output, rotationAmount);
            printf("%c", output);
            printf("\n");

        case 2:
            printf("You have chosen rotation cipher decryption\n");
            printf("1. Decipher with key\n");
            printf("2. Decipher without key\n");
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
               printf("\nPlease select 1 or 2: \n");
               scanf("%d", &choice);
            }
            if (choice == 1) { 
               printf("Key: %d\n", rotationAmount);
               CaesarDe(message, output, rotationAmount);
               break;
                
            }
            if (choice == 2) { 
               rotationAmount = 0;
               CaesarDe(message, output, rotationAmount);
               
               while (strstr(output, " A ") == NULL && strstr(output, " THE ") == NULL) {
                     rotationAmount++;
                     CaesarDe(message, output, rotationAmount);
                }
                printf("Key: %d\n", rotationAmount);
                printf("\n");
                printf("Message Text: \n");
                for (i = 0; message[i] != '\0'; i++) {
                    printf("%c", message[i]);
                    
                }
                printf("\n");
                printf("Output Text: \n");
                for (i = 0; message[i] != '\0'; i++) {
                    printf("%c", output[i]);
                    fprintf(output, "%c", output[i]);
                    
                }
                printf("\n");
                
            }
           
         case 3:
         k = SubEn(message, output, key);
         if (k == 1)
            exit(k);
         printf("\nKey: %s\n\n", key);
         printf("Message Text: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", message[i]);
             
         }
         printf("\n");
         printf("Output Text: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", output[i]);
             fprintf(output, "%c", output[i]);
             
         }
         printf("\n");
      case 4:
         
         k = SubDe(message, output, *key);
         if (k == 1)
            exit(k);
         printf("\nKey: %s\n", key);
         printf("\nKey: %s\n", key);
         printf("Message Text: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", message[i]);
             
         }
         printf("\n");
         printf("Output Text: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", output[i]);
             fprintf(output, "%c", output[i]);
             
         }
         printf("\n");
   }
   
   fclose(stdin);
   return k;
}
    
    int CaesarEn( char *message,char *output, int rotationAmount){
    int i;
    for (i = 0; i < strlen (message); i++){
        if (message[i]>='A' && message[i]<='Z'){
            //Encryt the UPPER CASE letters 
            message[i] = ((message[i]-'A')+rotationAmount)%26+ 'A';
            
        }
        else if (message[i]>='a' && message[i]<='z'){ 
            //Find the lower case letters and change it to UPPER CASE letters
            message[i] = message[i]-32; 
            message[i] = ((message[i]-'A')+rotationAmount)%26+ 'A';
        }    
    }
    return 0;
        
    }
    
    
    int CaesarDe(char *message, char *output, int rotationAmount){
        int i;
        for (i = 0; i < strlen (message); i++){
            
            if (message[i]>='A' && message[i]<='Z'){
                
                message[i] = ((message[i]-'A')-rotationAmount)%26+ 'A';  
            }
            else if (message[i]>='a' && message[i]<='z'){
                message[i] = message[i]-32;
                message[i] = ((message[i]-'A')-rotationAmount)%26+ 'A';
            }    
        }
        return 0;
    }
        

     int SubEn( char *message, char *output, const char *key){
 
        int i, j[1024];
        for ( i = 0; message[i] != '\0'; i++){
            if(message[i]>='a' && message[i]<='z'){
              j[i] = message[i] - 65;
              output[i] = key[j[i]];
            }
            else
            output[i] = message[i];
            
        }
        return 0;
         
     }
             
    int SubDe( char *message, char *output, const char *key){
        const char code[26]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char OriginalCode;
        char NewestCode;
        int i,m,n=0;
        for (i = 0; message[i] != '\0'; i++){
            OriginalCode = key[i];
            NewestCode = code[i];
            if(message[i]>='A' && message[i]<='Z'){
              for (m = 0; m < 1025; m++){
            if (message[i] == OriginalCode){
               output[i] = NewestCode;
               break;
                
            }
            else{
               m++;
               OriginalCode = key[n];
               NewestCode = code[n];
               n++;
               if (n > 25)
                  n = 0;
                
            }
                  
              }
                
            }
            else
         output[i] = message[i];
   }
   return 0;
}
             

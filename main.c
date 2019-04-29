/* 
Student Name : Jiajia Yang
Student Number : C3314189
Engg1003 Assignment 1 
Final Code
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function prototypes
int CaesarEn( char *message, char *output, int rotationAmount);//Caesar cipher encryption function prototype
int CaesarDe( char *message, char *output, int rotationAmount);//Caesar cipher decryption function prototype
int SubEn( char *message, char *output, const char *key); //Substitution Encryption function prototype
int SubDe( char *message, char *output, const char *key); //Substitution Decryption function prototype

int main(){
    //Text read from a file
    FILE *inputCode, *outputCode;
    inputCode = fopen("inputCode.txt", "r");
    outputCode = fopen("outputCode.txt", "w");
    while (inputCode == NULL)  //Determine if the file exists
    perror("File Input");
    
    int i,k,choice;
    int rotationAmount;
    char message[100],output[100],key[30];
    char *point;
    rotationAmount = strtol(key, &point, 10);
    
    //Make a selection menu
    printf("\nPlease make a selection from 1 to 4\n");
    printf("1. Encryption with a rotation cipher key\n");
    printf("2. Decryption with a rotation cipher key\n");
    printf("3. Encryption with a substitution cipher key\n");
    printf("4. Decryption with a substitution cipher key\n");
    scanf ("%c",&choice);
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {//Make sure the entered is not blank 
    printf("Please select 1 , 2 , 3, \n");
    scanf("%d", &choice);
    //while ((getchar()) != '\n');//Make sure the entered is not blank 
    switch(choice){
        case 1://Encryption of a message with a rotation cipher
            printf("You have chosen rotation cipher encryption.\n");
            printf("Enter a shift amount (integer between [0,25])\n");
            scanf("%d", &rotationAmount);
            CaesarEn(message, output, rotationAmount);
            printf("%c", output);
            printf("\n");

        case 2://Decryption of a message encrypted with a rotation cipher
            printf("You have chosen rotation cipher decryption.\n");
            printf("Please make a selection between 1 and 2\n");
            printf("1. Decipher with shift amount\n");
            printf("2. Decipher without shift amount\n");
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {//Make sure the entered is not blank 
               printf("Please select 1 or 2 \n");
               scanf("%d", &choice);
            }
            while (choice == 1) { //Decipher with shift amount 
               printf("Shift amount is : %d\n", rotationAmount);
               CaesarDe(message, output, rotationAmount);
               break;
                
            }
            while (choice == 2) { //Decipher without shift amount 
               rotationAmount = 0;
               CaesarDe(message, output, rotationAmount);
               while (strstr(output, " A ") == NULL && strstr(output, " THE ") == NULL) {
                     rotationAmount++;
                     CaesarDe(message, output, rotationAmount);
                }
                printf("Shift amount is : %d\n", rotationAmount);
                printf("\n");
                printf("Message is : \n");
                for (i = 0; message[i] != '\0'; i++) {
                    printf("%c", message[i]);
                    
                }
                printf("\n");
                printf("Output is : \n");
                for (i = 0; message[i] != '\0'; i++) {
                    printf("%c", output[i]);
                    fprintf(output, "%c", output[i]);
                    
                }
                printf("\n");
                
            }
           
         case 3://Encryption of a message with a substitution cipher
         //Return value is "k"
         k = SubEn(message, output, key);
         while (k == 1)
            exit(k);
         printf("\nKey: %s\n", key);
         printf("Message is : \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", message[i]);
             
         }
         printf("\n");
         printf("Output is : \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", output[i]);
             fprintf(output, "%c", output[i]);
             
         }
         printf("\n");
         
      case 4: //Decryption of a message encrypted with a substitution cipher
         //Return value is "k"
         k = SubDe(message, output, *key);
         while (k == 1)
            exit(k);
         printf("\nKey: %s\n", key);
         printf("\nKey: %s\n", key);
         printf("Message is: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", message[i]);
             
         }
         printf("\n");
         printf("Output is: \n");
         for (i = 0; message[i] != '\0'; i++) {
             printf("%c", output[i]);
             fprintf(output, "%c", output[i]);
             
         }
         printf("\n");
   }
   
   fclose(stdin);
   return k;
}
}
    
//Some function definetions 
//Caesar cipher encryption function definetion
int CaesarEn( char *message,char *output, int rotationAmount){
    int i;
    for (i = 0; i < strlen (message); i++){
        if (message[i] >= 'A' && message[i] <= 'Z'){
            //Encryption of the UPPER CASE letters 
            message[i] = ((message[i] - 'A') + rotationAmount) %26 + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z'){ 
            //Find the lower case letters and change it to UPPER CASE letters
            message[i] = message[i]-32; 
            message[i] = ((message[i] - 'A') + rotationAmount) %26 + 'A';
        }    
    }
    return 0;
    
}
    
//Caesar cipher decryption function definetion
int CaesarDe(char *message, char *output, int rotationAmount){
    int i;
    for (i = 0; i < strlen (message); i++){
            
        if (message[i] >= 'A' && message[i] <= 'Z'){
                
            message[i] = ((message[i] - 'A') - rotationAmount) %26 + 'A';  
        }
        else if (message[i] >= 'a' && message[i] <= 'z'){
            message[i] = message[i] - 32;
            message[i] = ((message[i] - 'A') - rotationAmount) %26 + 'A';
        }    
    }
    return 0;
    
}
        
//Substitution Encryption function definetion
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

//Substitution Decryption function definetion         
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

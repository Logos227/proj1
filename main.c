/* 
Jiajia Yang
C3314189
Engg1003 Assignment 1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CaesarEn(const char *message, char *output, int rotationAmount);//caesar cipher encryption function prototype
int CaesarDe(const char *message, char *output, int rotationAmount);//caesar cipher decryption function prototype
int SubEn(const char *message, char *output, const char *key); 
int SubDe(const char *message, char *output, const char *key); 

//int SubEn(char AlphabetSub[]);     //substitution Encryption function prototype
//int SubDe(char DEAlphabetSub[]);   //substitution Decryption function prototype
//int SetAlphabetSub(char SubTable[],char DESubTable[]);// set alphabet substitution function prototype

int mian(){
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

   
  // below should connet with #include
    //int CaesarEn(const char *message, char *output, int rotationAmount);//caesar cipher encryption function prototype
    //this should be the main code
    
    
    int CaesarEn(const char *message,char *output, int rotationAmount){//这里没分号哦
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
    
    
    int CaesarDe(const char *message, *char *output, int rotationAmount){
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
        //next  code should in main code 
        // printf("%s",message);
        //printf("\n");
        // here is the end of task2 
       
       
        //printf("%s",message);
        //printf("\n");
        
   
    /*here is provious sub function and mian code 以下是之前写的替换密码函数和mian
    void SubEn(char AlphabetSub[]);   //substitution Encryption prototype
    void SubDe(char DEAlphabetSub[]);   //substitution Decryption prototype
    void SetAlphabetSub(char SubTable[],char DESubTable[]);// set alphabet substitution prototype 
    int main(){ //【NOT SURE IN 9】----might be char AlphabetSub[] instead char SubTable[
        int m;  // to choose encryption(m=1) of decryption(m=2)
        char SubTable['z'+1]; //NOT SURE HERE---Substition table for Encryption-
        char DESubTable['Z'+1];
        printf("Enter 1 to encrypt,enter 2 to decrypt.");
        scanf("%d",&m);//read m from console
        SetAlphabetSub(SubTable, DESubTable);
        switch(m){
            case 1: SubEn(SubTable);
            break;
            case 2: SubDe(DESubTable);
            break;
            default:break;
        }
        return 0;
    }
    
    */
     int SubEn(const char *message, char *output, char *key){
    //provious start -----void SubEn(char AlphabetSub[]){// Encryption function
        /*
        should exit in mian code
        char message;
        printf("Please enter message to be encrypted ");
        gets(message);//read message
        printf("Encrypted message is");
        */
        int i,j[1024];
        
        for (int i = 0; message[i] != '\0'; i++){
            if(message[i]>='a' && meaaage[i]<='z'){
              j[i] = message[i] - 65;
              output[i] = key[j[i]];
                
            }
            else
            output[i] = message[i];
            
        }
        return 0;
         
     }
              /*here is the provious code 
              AlphabetSub[message[i]];
              printf("%s",message);  
            }
            else
            printf("%s",message);
        }
        printf("\n");
    }
    */
    int SubDe(const char *message, char *output, char *key){
        //void SubDe(char DEAlphabetSub[]){//Decryption function
       /*
        char message;
        printf("Please enter message to be dencrypted ");
        gets(message);//read message
        printf("Dencrypted message is");
        */
        const char code[26]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char OriginalCode;
        char NewestCode;
        int i,m,n=0;
        for (int i = 0; message[i] != '\0'; i++){
            OriginalCode = key[i];
            NewestCode = code[i];
            if(message[i]>='A' && message[i]<='Z'){
              for (m = 0; m < 1025; m++){
            if (message[i] == OriginalCode){
               outputText[i] = NewestCode;
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
              /*
              DEAlphabetSub[message[i]];
              printf("%s",message);  
            }
            else
            printf("%s",message);
        }
        printf("\n");
   }
   */
  

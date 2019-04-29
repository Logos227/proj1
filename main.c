/* 
Jiajia Yang
C3314189
Engg1003 Assignment 1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CaesarEn(const char *message, /*char *output,//seem dont need it */ int rotationAmount);//caesar cipher encryption function prototype
int CaesarDe(const char *message, char *output, int rotationAmount);//caesar cipher decryption function prototype
int SubEn(const char *message, char *output, char *key); 
int SubDe(const char *message, char *output, char *key); 

//int SubEn(char AlphabetSub[]);     //substitution Encryption function prototype
//int SubDe(char DEAlphabetSub[]);   //substitution Decryption function prototype
//int SetAlphabetSub(char SubTable[],char DESubTable[]);// set alphabet substitution function prototype

int mian(){
    
    FILE *input, *output;
    
    output = fopen("output.txt", "w");
    input = fopen("input.txt", "r");
   if (input == NULL)
      perror("File Input");

   rotationAmount = strtol(key, &ptr, 10);
    
    
    //make a selection menu for console 
    printf("Please make a selection\n");
    printf("1. Encryption with a rotation cipher key:\n");
    printf("2. Decryption with a rotation cipher key:\n");
    printf("3. Encryption with a substitution cipher given plain text and key:\n");
    printf("4. Decryption with a substitution cipher given plain text and key:\n");
    char choice;
    scanf ("%c",&choice);
    while ((getchar()) != '\n');
    switch(choice){
        case 1:
            printf("You have chosen rotation cipher encryption\n");
            printf("Enter a key (integer between [0,25])\n");
            scanf("%d", &rotationAmount);
            FILE *input, *output;
            input = fopen("input.txt", "r");
            output = fopen("output.txt", "w");
            if (input == NULL)
            perror("File Input");
            char message,outputCode;
            while((message = fgetc (input)) != EOF){
                outputCode=CaesarEn(message);
                printf("%c", outputCode);
        }
        printf("\n");
        
        
        case 2:
            printf("You have chosen rotation cipher decryption\n");
            printf("1. Decipher with key\n");
            printf("2. Decipher without key\n");
            scanf("%d", &choice);
            if (selector != 1 && selector != 2) {
               printf("\nPlease select 1 or 2: \n");
               scanf("%d", &selector);
            }
            if (choice == 1) { 
               printf("Key: %d\n\n", rotationAmount);
               CaesarDe(message, output, rotationAmount);
               break;
                
            }
            if (choice == 2) { /
               rotationAmount = 0;
               CaesarDe(message, output, rotationAmount);
               
               while (strstr(output, " A ") == NULL && strstr(output, " THE ") == NULL) {
                     rotationAmount++;
                     CaesarDe(message, output, rotationAmount);
                }
                printf("Key: %d\n", rotationAmount);
                printf("\n");
                
            }
           
         
         case 3:
         error = encryptSubstitutionCipher(messageText, key, outputText);
         if (error == 1)
            exit(error);
         printf("\nKey: %s\n\n", key);
         break;
      case 4:
         
         error = decryptSubstitutionCipher(messageText, key, outputText);
         if (error == 1)
            exit(error);
         printf("\nKey: %s\n\n", key);
         break;
   }
                
        
        
        
    }
    
    //while(choice <'a' || choice > 'd')
    

    
    
    //function
    //void encryption(char message[100], char encrypted[100], int key)
    /*
    void encryption(char message[100], char encrypted[100], int key){
   // declare variables here
   for(i = 0; message[i] != '\0'; ++i){
    symbol = message[i];

    if(symbol >= 'a' && symbol <= 'z'){
        symbol = symbol + key;

        if(symbol > 'z'){
            symbol = symbol - 'z' + 'a' - 1;
        }

        encrypted[i] = symbol;
    }
    else if(symbol >= 'A' && symbol <= 'Z'){
        symbol = symbol + key;

        if(symbol > 'Z'){
            symbol = symbol - 'Z' + 'A' - 1;
        }

        encrypted[i] = symbol;
    }
    else if(symbol >= '0' && symbol <= '9'){
        symbol = symbol + key;

        if(symbol > '9'){
            symbol = symbol - '9' + '1' - 1;    
        }

        encrypted[i] = symbol;
    }
  }
}
    */
  //till here is the function of caeser, dont know why change symbol and change the UP to Low letter
  //below is change my provious caeser code as function (testing)
  // below should connet with #include
    //int CaesarEn(const char *message, char *output, int rotationAmount);//caesar cipher encryption function prototype
    //this should be the main code
    
    
    int CaesarEn(const char *message,/*char *output,//这个好像不用*/ int rotationAmount){//这里没分号哦
    // not sure if here should agg "char message[100], encrypted[100];"
    int i;
    //上一行j, k, t;dont know why add jkt as "变量"in int 
    //Task1:Encryption of a message with a rotation cipher given the message text and rotation amount
    //while(1){   //为什么要加while(1)呢
        //next  4 code should in main code 
        //printf("Enter message to be encrypted:");
        //gets(message);
        //printf("Enter shift amount(1-25):");
        //scanf("%d%*c",&rotationAmount);
        for (i = 0; i < strlen (message); i++){
            
            if (message[i]>='A' && message[i]<='Z'){
                //Encryt the UPPER CASE letters 
                message[i] = ((message[i]-'A')+move)%26+ 'A';  
            }
            else if (message[i]>='a' && message[i]<='z'){ 
                //Find the lower case letters and change it to UPPER CASE letters
                message[i] = message[i]-32; 
                message[i] = ((message[i]-'A')+move)%26+ 'A';
            }    
        }
        return 0;
    }
    
    
    int CaesarDe(const char *message, /*char *output,//这个好像不用*/ int rotationAmount){
        //Task2:Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        //next  4 code should in main code 
        //printf("Enter message to be dencrypted:");
        //gets(message);
        //printf("Enter shift amount(1-25):");
        //scanf("%d%*c",&rotationAmount);
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
  /*
  
  // here is the provious draft code with chinese comments  
   void SetAlphabetSub(char SubTable[],char DESubTable[]){
       int i;
       char j;
       char s;//password
       printf("Please enter password(UPPER WORDS) ");
       gets(pasword); //读入密钥
       printf("%s",s);
       printf(" alphabet substitution is: ");
       char s1;    
       for(i = 0 ; i < s.length(); i++){ //对密钥进行处理（去掉空格和重复的字符）
       bool sign =0;  //标志变量
       if(s[i] >= 'A' && s[i] <='Z'){
           for(int j = 0; j < s1.length(); j++){
               if(s[i] == s1[j]){
                   sign = 1;
                   break;
                   
               }
               
           }
           if(sign == 0) s1 = s1 + s[i];
           else sign = 0;
           
       }
           
       }
       for( j ='a';j<='z';j++){
           printf("%s",j);
           printf("\n");
       }
       char ch='A';
       for( i = 'a' ;i <= 'z'; i++){//该循环利用密钥得到置换表
       if(i < 'a' + s1.length()){//前面直接用s1代替
       SubTable[i] = s1[i-'a']; 
           
       }
       else{ //后面将剩下的"贴"上去
       for(int j = 'a'; j < 'a' + s1.length(); j++)
       {
           if(ch == SubTable[j])
           {
               ch++;
               j= 'a'; //每次都从头开始搜索
               continue;
               
           }
           
       }
       SubTable[i] = ch;
       ch++;
           
       }
       printf("%s",SubTable[i]); //同时输出置换表
       }
       printf("/n");
       for( i='a'; i<= 'z'; i++) //该循环利用置换表得到反置换表
       {
           DESubTable[ SubTable[i] ] = i;
           
       }
       for( i='A'; i<= 'Z'; i++) //输出反置换表
       {
           printf("%s",DESubTable[i]);
           
       }
       printf("/n");
       
   }
    
} 
*/

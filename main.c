#include <stdio.h>
#include <string.h>


int main(){
    //Task3  Encryption of a message with a substitution cipher given message text and alphabet substitution
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
    
    void SubEn(char AlphabetSub[]){// Encryption function
        char message;
        printf("Please enter message to be encrypted ");
        gets(message);//read message
        printf("Encrypted message is");
        for (int i = 0; i < message.length(); i++){
            if(message[i]>='a' && meaaage[i]<='z'){
              AlphabetSub[message[i]];
              printf("%s",message);  
            }
            else
            printf("%s",message);
        }
        printf("\n");
    }
    
    
   void SubDe(char DEAlphabetSub[]){//Decryption function
       char message;
        printf("Please enter message to be dencrypted ");
        gets(message);//read message
        printf("Dencrypted message is");
        for (int i = 0; i < message.length(); i++){
            if(message[i]>='A' && meaaage[i]<='Z'){
              DEAlphabetSub[message[i]];
              printf("%s",message);  
            }
            else
            printf("%s",message);
        }
        printf("\n");
   }
   
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
    
    
    
    
    //here is the task 1and task 2
    /*char passwd[100], encrypted[100];
    int i, j, k, t, move;
    //Task1:Encryption of a message with a rotation cipher given the message text and rotation amount
    while(1){
        printf("Enter message to be encrypted:");
        gets(passwd);
        printf("Enter shift amount(1-25):");
        scanf("%d%*c",&move);
        for (i = 0; i , strlen (passwd); i++){
            
            if (passwd[i]>='A' && passwd[i]<='Z'){
                //Encryt the UPPER CASE letters 
                passwd[i] = ((passwd[i]-'A')+move)%26+ 'A';  
            }
            else if (passwd[i]>='a' && passwd[i]<='z'){ 
                //Find the lower case letters and change it to UPPER CASE letters
                passwd[i] = passwd[i]-32; 
                passwd[i] = ((passwd[i]-'A')+move)%26+ 'A';
            }    
        }
        //Task2:Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        /*printf("Enter message to be dencrypted:");
        gets(passwd);
        printf("Enter shift amount(1-25):");
        scanf("%d%*c",&move);
        for (i = 0; i < strlen (passwd); i++){
            
            if (passwd[i]>='A' && passwd[i]<='Z'){
                
                passwd[i] = ((passwd[i]-'A')-move)%26+ 'A';  
            }
            else if (passwd[i]>='a' && passwd[i]<='z'){
                passwd[i] = passwd[i]-32;
                passwd[i] = ((passwd[i]-'A')-move)%26+ 'A';
            }    
        }
        
        printf("%s",passwd);
        printf("\n");
    }   // here is the end of task2 
    
        printf("%s",passwd);
        printf("\n");
    }
    */
    
 //return 0;
 //}

#include <stdio.h>
#include <string.h>


int main(){
    char passwd[100], encrypted[100];
    int i, j, k, t, move;
    //Encryption of a message with a rotation cipher given the message text and rotation amount
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
        printf("%s",passwd);
        printf("\n");
    }
    
 return 0;
 }

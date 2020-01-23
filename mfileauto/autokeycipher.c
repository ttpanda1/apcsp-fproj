/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *encryptMessage(char *plainText, char *keyWords)
{
    char tabulaRecta[26][26];
   
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for ( int i = 0; i < 26; i++ ) {
        for ( int j = 0; j < 26; j++ ) {
            tabulaRecta[i][j] = letters[(i + j) % 26];
        }
    }

    char *tmpText = malloc((strlen(plainText) + strlen(keyWords))* sizeof(char));
    char *eMessage = malloc(strlen(plainText) * sizeof(char));
 
    strcpy(tmpText, keyWords);
    strcpy(tmpText + strlen(keyWords), plainText);

    for ( int i = 0; i < strlen(tmpText); i++ ) {
        tmpText[i] = toupper(tmpText[i]);
    }

    int j = 0;
    for( int i = 0; i < strlen(plainText); i++ )
    {
        if (isalpha(plainText[i]))
        {
            while( !isalpha(tmpText[j])) {
                j++;
            }
           
            int rowNum = tmpText[j] - 'A';
            int colNum = plainText[i] - 'A';
           
            eMessage[i] = tabulaRecta[rowNum][colNum];
           
            j++;
        }
        else {
            eMessage[i] = plainText[i];
        }
    }
   
    return eMessage;
}

char *decryptMessage(char *eMessage, char *keyWords) {
    char *dMessage = malloc(strlen(eMessage) * sizeof(char));
    char *tmpKey = malloc((strlen(eMessage) + strlen(keyWords))* sizeof(char));

    strcpy(tmpKey,keyWords);
    strcpy(dMessage,eMessage);

    for ( int i = 0; i < strlen(tmpKey); i++ ) {
	tmpKey[i] = toupper(tmpKey[i]);
    }
   
    int j=0;
    for ( int i = 0; i < strlen(eMessage); i++ ) {

        while( !isalpha(tmpKey[j])) {
            j++;
        }

        tmpKey[j] = toupper(tmpKey[j]);


        if (isalpha(eMessage[i])) {
            dMessage[i] = eMessage[i] - tmpKey[j];

            j++;

            if ( dMessage[i] < 0 ) {
                dMessage[i] = dMessage[i] + 26 + 65;
            }
            else {
                dMessage[i] = dMessage[i] + 65;
            }
           
            char tmp = dMessage[i];
            strncat(tmpKey, &tmp, 1);
        }
    }

    return dMessage;
}

int main(int argc, char* argv[])
{
  char* input1;
  char* inputKey;
  char* inputMessage;
  
        if (argc > 3) {
	  input1 = argv[1];
	  inputKey = argv[2];
	  inputMessage =  argv[3];  
        }

        if ( strcmp(input1, "Encrypt") == 0) {
            printf("Encrypted Message: %s\r\n", encryptMessage(inputMessage, inputKey));
	}
	if ( strcmp(input1, "Decrypt") == 0) {
	    printf("Decyrpted Message: %s\r\n", decryptMessage(inputMessage, inputKey));
	}
    return 0;
}

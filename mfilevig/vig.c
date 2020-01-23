#include <stdio.h>
#include <string.h>

char keystring[200];
int k;
char output[200];
char charstring[200];

char *Encrypt(int det, char *charstring, char *keystring) {
  if ( det == 0 ) {
  for ( int i = 0; strlen(charstring) > i; i++) {
     if ( charstring[i] > 96 ) {
     if ( 123 > charstring[i] ) {
      char tm = charstring[i] + keystring[i] - 194;
      int tmp = tm % 26;
      output[i] = 'a' + tmp;
     }
     }
     else {
       output[i] = charstring[i];
     }
  }
}
else {

  for ( int i = 0; strlen(charstring) > i; i++) {
     if ( charstring[i] > 96 ) {
     if ( 123 > charstring[i] ) {
      char tm = 26 + charstring[i] - keystring[i];
      int tmp = tm % 26;
      output[i] = 'a' + tmp;
    }
    }
    else {
      output[i] = charstring[i];
    }
  }
}
return output;
}


int main(int argc, char* argv[]) {

// constructing the message to encrypt/decrypt
if ( argc >= 4 ) {
  for ( int i = 3; argc > i; i++) {
    strcat(charstring, argv[i]);
    strcat(charstring, " ");
  }
}
else {
  char* charstring = argv[3];
}


  char* input1;
  char* inputKey;
  char* inputMessage;

  input1 = argv[1];
  int det = 5;

  if ( strcmp(input1, "Encrypt") == 0) {
    det = 0;
  }
  if ( strcmp(input1, "Decrypt") == 0) {
    det = 1;
  }


// converts everyting to lower case
for ( int i = 0; strlen(charstring) > i; i++) {

  if ( 91 > charstring[i] ) {
    if ( charstring[i] > 64 ) {
      char tmp = charstring[i] + 32;
      charstring[i] = tmp;
    }
  }
}


char* key = argv[2];

// constructing the key
  for ( int i = 0; strlen(charstring) > i; i++) {
    k = i % strlen(key);
    keystring[i] = key[k];
  }

int t = 0;
int y;
char tmp[200];

  for ( int i = 0; strlen(keystring) > i; i++) {
    if (charstring[i] == ' ') {
      t = t + 1;
      tmp[i] = ' ';
    }
    else {
      y = i - t;
      tmp[i] = keystring[y];
    }
  }

  for ( int i = 0; strlen(keystring) > i; i++) {
    keystring[i] = tmp[i];
  }

for ( int i = 0; strlen(keystring) > i; i++) {

  if ( 95 > keystring[i] ) {
    if ( 32 != keystring[i] ) {
      char tmp = keystring[i] + 32;
      keystring[i] = tmp;
    }
  }
}

// actual encryption

printf("Plain Text: %s\nCipher Text: %s\r\n", charstring, Encrypt(det, charstring, keystring));



}



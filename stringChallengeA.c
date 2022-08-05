/******************************************************************************

StringChallenge(str) take the str parameter being passed, which will be a 
positive integer, take its binary representation (padded to the nearest N * 8 bits), 
reverse that string of bits, and then finally return the new reversed string in 
decimal form. For example: if str is "47" then the binary version of this integer
is 101111 but we pad it to be 00101111. Your program should reverse this binary 
string which then becomes: 11110100 and then finally return the decimal version 
of this string, which is 244.

*******************************************************************************/
#include <stdio.h> 
#include <string.h>
#include<stdlib.h>

void StringChallenge(char * str) {
  
  // code goes here 

  //convert to binary value
  long ipnum = atoi(str), r; 
  unsigned long biNum = 0;
  long phmultipler = 1;

  while(ipnum !=0) {
    r = ipnum % 2;
    ipnum = ipnum / 2;
    biNum += r * phmultipler;
    phmultipler *= 10;
  } 

  //printf("biNum is: %lu\n", biNum);
  char biStr[10000];
  sprintf(biStr, "%lu", biNum);
  //printf("biStr is: %s\n", biStr);

  //pad string
  int slen =strlen(biStr), padLen;
  //printf("slen is: %d\n", slen);
  if(slen%8 != 0){
    padLen = 8-(slen%8);
  }else{
    padLen = 0;
  }
  //printf("padLen is: %d\n", padLen);

  char padBiStr[10000];
  int tmpLen = padLen;
  while(tmpLen > 0){
    //strncat(padBiStr, "0", 50);
    strcat(padBiStr, "0");
    tmpLen--;
  }
  //strncat(padBiStr, biStr, 50);
  strcat(padBiStr, biStr);
  //printf("padBiStr is: %s\n", padBiStr);

  //reverse string
  int itr = 0;
  int newLen =strlen(padBiStr); 
  //printf("newLen is: %d\n", newLen);
  char tmpStr[10000];

  for(int i = newLen-1; i >= 0; i--) {
    tmpStr[itr] = padBiStr[i];
    itr++;
  } 

  //printf("tmpStr is: %s\n", tmpStr);

  //convert to decimal
  long dval = 1;
  long totl =0;
  int j = newLen-1;
  while(j >= 0){
    if(tmpStr[j] == '1'){
      totl += dval;
    }
    dval *= 2;
    j--;
  }

  printf("%lu", totl);

}

int main(void) { 
   
  // keep this function call here
  StringChallenge("4567");
  return 0;
    
}
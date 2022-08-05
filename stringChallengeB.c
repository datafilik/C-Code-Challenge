/******************************************************************************

Given a decimal and binary number in string form (e.g  {"56", "011000"}), 
the challenge is to find out how many bits in the binary number has to be 
flipped to represent the binary equivalent of the binary number.

*******************************************************************************/
#include <stdio.h> 
#include <string.h>
#include<stdlib.h>

void StringChallenge(char * strArr[], int arrLength) {
  
  // code goes here
  long ipDecVal = atoi(strArr[0]);
  //printf("ipDecVal is: %lu\n", ipDecVal);

  // ---convert decimal value to binary---
  unsigned long biNum = 0;
  long rem, multiplier = 1;
  while(ipDecVal != 0){
    rem = ipDecVal % 2;
    ipDecVal = ipDecVal / 2;
    biNum += rem * multiplier;
    multiplier *= 10;
  }
  //printf("biNum is: %lu\n", biNum);

  char biStr[100000];
  sprintf(biStr, "%lu", biNum);
  //printf("biStr is: %s\n", biStr);

  char* ipBiValStr = strArr[1];
  //printf("ipBiValStr is: %s\n", ipBiValStr);

  // ----compare both binary values----
  int biValLen = strlen(ipBiValStr);
  //printf("biValLen is: %d\n", biValLen);

  int diffCount = 0;
  for (int i = 0; i < biValLen; i++) {
    if (biStr[i] != ipBiValStr[i]) {
      diffCount += 1;
    }
  }

  //--ouput number of difference betweeen both binary values--
  printf("%d", diffCount);

}

int main(void) { 
   
  // keep this function call here
  char * A[] = {"5624", "0010111111001"};
  //char * A[] = {"44", "111111"};
  //char * A[] = {"56", "011000"};
  int arrLength = sizeof(A) / sizeof(*A);
  StringChallenge(A, arrLength);
  return 0;
    
}
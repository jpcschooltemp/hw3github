nclude <stdio.h>
#include <stdlib.h>


void readEntry(short *number, char string[]);
void echoEntry(short number, char string[]);
void saveFile(short number, char string[]);
void continueCheck(short *flagContinue);
void readFile();

int main()
{
  short number, flagContinue;
  char string[32];
 
  do
  {
    readEntry(&number, string);
    echoEntry(number, string);
    saveFile(number, string);
    continueCheck(&flagContinue);
  } while(flagContinue);
 
  readFile();
 
 
  exit(0);
}

void readEntry(short *number, char string[])
{
  printf("Enter a number greater than zero: ");
  scanf("%hd", number);
  printf("Enter a string less than 32 characters long: ");
  scanf("%s", string);
  return;
}

void echoEntry(short number, char string[])
{
  printf("%hd %s\n", number, string);
  return;
}

void saveFile(short number, char string[])
{
  FILE *pFile;
 
  pFile = fopen("data.txt", "a");
  if (pFile != NULL)
    fprintf(pFile, "%hd %s\n", number, string);
  fclose(pFile);
}

void readFile()
{
  FILE *pFile;
  short number;
  char string[32];
 
  pFile = fopen("data.txt", "r");
 
  if(pFile != NULL)
  {
    while(!(feof(pFile)))
    {
      fscanf(pFile, "%hd %[^\n]", &number, string);
      if(!(feof(pFile)))
      printf("%hd %s\n", number, string);
     
    }
  }
  fclose(pFile);
}

void continueCheck(short *flagContinue)
{
  char answer;
  printf("Would you like to continue entering data?(Y/N) ");
  scanf(" %c", &answer);
  if (answer=='y' || answer=='Y')
    *flagContinue = 1;
  else
    *flagContinue = 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

void parse(char*);
void ls();
void ls_l(); //ls -l
void clear();
void quit();
void makedir(char*);

int main()
{
char buff[FILENAME_MAX];
char *cmd;

getcwd(buff,FILENAME_MAX);
cmd = malloc(100);

while(1){

  printf("\n%s>",buff);
  fgets(cmd, 100, stdin);
  parse(cmd);
}

return 0;
}


void parse(char *cmd)
{
 if(strncmp(cmd, "ls", strlen(cmd)-1)==0)
    ls();
 else if(strncmp(cmd, "ls -l", strlen(cmd)-1)==0)
    ls_l();
 else if(strncmp(cmd, "clear", strlen(cmd)-1)==0)
     clear();
else if(strncmp(cmd, "quit", strlen(cmd)-1)==0)
      quit();
else if(strncmp(cmd, "mkdir", 5)==0)
       makedir(cmd);
 else
    printf("\nInvalid Unix Command..");
}


void ls()
{
  struct dirent *de;

  DIR *dr = opendir(".");

  if( dr==NULL )
  {
     printf("Error opening directory...");
     exit(0);
  }

  while( (de = readdir(dr))!=NULL )
     printf("%s\n", de->d_name);

  closedir(dr);

}

void ls_l()
{
   printf("Implemetation pending.....");
   system("ls -l");  //this is expected
}

void makedir(char *cmd)
{
   //cmd->test001
    char *p;
    int i;

    int len = strlen(cmd);
    p = malloc(50);
    for( i=1 ; i<=6 ; i++)
        cmd++;

    strncpy(p, cmd, len-7);

    if(mkdir(p, 0777) == -1 )
         printf("Invalid Command....");
    else
         printf("directory named %s created", p);

     p=NULL;

}

void clear()
{
 system("clear");  
}


void quit()
{
 exit(0);
}

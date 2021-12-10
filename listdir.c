#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

int flagF = 0, flagR = 0 , arg = 0;

void afficherR(char * pathname);
int RepExist();
int main(int argc , char * argv[])
{

    int c ;
  while( (c = getopt(argc , argv , "fr") )!= -1 )
  {
  
  
  switch(c)
  {
     case 'f':
     
     flagF = 1;
     
     break;
     
     case 'r':     
      flagR = 1;
           break;
    case'?':
      fprintf(stderr ,"Unkown option %c passed an argument",optopt);
          break;
      default:
       fprintf(stderr,"getopt"); }
  }
  
  arg = argc;
int i = 0;
      if (flagR ==1 && flagF == 1)
    
    i = 3;
    else if ( (flagR == 1 && flagF == 0 )|| (flagR==0 && flagF == 1))
    i = 2;
    if (flagR ==0 && flagF == 0)
    {

    afficherR(".");
    goto fin;
    }
    
if(RepExist() == 1 )
{
for (i ; i < argc ; i++)
{
afficherR(argv[i]);
} 
}
else{
afficherR(".");
}
  
fin:
return 0;
}

int RepExist(){


    int i = 0;
    struct stat BufferInfo;
    if (flagR ==1 && flagF == 1)
    
    i = 3;
    else if ( (flagR == 1 && flagF == 0 )|| (flagR==0 && flagF == 1))
    i = 2;
    if (arg == i)
      return 0;
        else
     return 1;
}

void afficherR(char * pathname)
{
    char chemin [100] = {0};
    struct stat Buffer;
      strcat(chemin,pathname);
    DIR * dir = opendir(chemin);    
    if (dir == NULL)
    {
    perror("dir");
    exit(1);
    }
    struct dirent * rep = readdir(dir);
    if (flagR == 1 || (flagR == 0 && flagF ==0)){
                  printf("\033[0;37m");
         printf("\n Les repertoires qui existe : \n ");
    while(rep != NULL ){
    if(rep->d_type == DT_DIR)
      {
      if (rep->d_name[0]!='.'){
          printf("\033[0;34m");
          printf("\e[1m%s  ",rep->d_name);
      }
      }
      
    
    rep =readdir(dir);
    }
    
    printf("\n");
    }
    
    if(flagF == 1){
    
              printf("\033[0;37m");
             printf("\n Les fichiers qui existe : \n ");
             dir = opendir(chemin);
             rep = readdir(dir);
        while(rep!=NULL)
        {
        
        if(rep->d_type != DT_DIR)
      {printf("\033[0;32m");
       printf("\e[1m%s  ",rep->d_name);
      
      }    rep =readdir(dir);
        
        }
    }
    
    printf("\n");
    
        printf("\n");
   }
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

int flagF = 0, flagR = 0 , arg = 0;

void afficherR(char * pathname);
int RepExist();
int main(int argc , char * argv[])
{

    int c ;
  while( (c = getopt(argc , argv , "fr") )!= -1 )
  {
  
  
  switch(c)
  {
     case 'f':
     
     flagF = 1;
     
     break;
     
     case 'r':     
      flagR = 1;
           break;
    case'?':
      fprintf(stderr ,"Unkown option %c passed an argument",optopt);
          break;
      default:
       fprintf(stderr,"getopt"); }
  }
  
  arg = argc;
int i = 0;
      if (flagR ==1 && flagF == 1)
    
    i = 3;
    else if ( (flagR == 1 && flagF == 0 )|| (flagR==0 && flagF == 1))
    i = 2;
    if (flagR ==0 && flagF == 0)
    {

    afficherR(".");
    goto fin;
    }
    
if(RepExist() == 1 )
{
for (i ; i < argc ; i++)
{
afficherR(argv[i]);
} 
}
else{
afficherR(".");
}
  
fin:
return 0;
}

int RepExist(){


    int i = 0;
    struct stat BufferInfo;
    if (flagR ==1 && flagF == 1)
    
    i = 3;
    else if ( (flagR == 1 && flagF == 0 )|| (flagR==0 && flagF == 1))
    i = 2;
    if (arg == i)
      return 0;
        else
     return 1;
}

void afficherR(char * pathname)
{
    char chemin [100] = {0};
    struct stat Buffer;
      strcat(chemin,pathname);
    DIR * dir = opendir(chemin);    
    if (dir == NULL)
    {
    perror("dir");
    exit(1);
    }
    struct dirent * rep = readdir(dir);
    if (flagR == 1 || (flagR == 0 && flagF ==0)){
                  printf("\033[0;37m");
         printf("\n Les repertoires qui existe : \n ");
    while(rep != NULL ){
    if(rep->d_type == DT_DIR)
      {
      if (rep->d_name[0]!='.'){
          printf("\033[0;34m");
          printf("\e[1m%s  ",rep->d_name);
      }
      }
      
    
    rep =readdir(dir);
    }
    
    printf("\n");
    }
    
    if(flagF == 1){
    
              printf("\033[0;37m");
             printf("\n Les fichiers qui existe : \n ");
             dir = opendir(chemin);
             rep = readdir(dir);
        while(rep!=NULL)
        {
        
        if(rep->d_type != DT_DIR)
      {printf("\033[0;32m");
       printf("\e[1m%s  ",rep->d_name);
      
      }    rep =readdir(dir);
        
        }
    }
    
    printf("\n");
    
        printf("\n");
   }

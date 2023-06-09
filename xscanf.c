#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void xscanf(char *str,...){
    char token[sizeof(str)];int k=0;
    va_list ptr;
    va_start(ptr,str);
    for(int i=0;str[i]!='\0';i++){
        token[k++]=str[i];        
        if(str[i+1]=='%' || str[i+1]=='\0'){
            token[k]='\0';k=0;
            if(token[0]=='%'){
                char ch1=token[1];
                if(ch1=='i'||ch1=='d'|| ch1=='u'){
                    fscanf(stdin,"%i",va_arg(ptr,int*));
                    fprintf(stdout,"%s",token+2);
                }
                else if(ch1=='h'){
                    fscanf(stdin,"%hi",va_arg(ptr,short*));
                    fprintf(stdout,"%s",token+2);
                }
                else if(ch1=='c'){
                    char c;
                    while((c=fgetc(stdin))=='\n'||c==' '||c==EOF){}
                    *va_arg(ptr,char*)=c;
                    fprintf(stdout,"%s",token+2);
                }
                else if(ch1=='f'){
                    fscanf(stdin,"%f",va_arg(ptr,float*));
                    fprintf(stdout,"%s",token+2);
                }
                else if(ch1=='l'){
                    char ch2=token[2];
                    if(ch2=='u'||ch2=='d'||ch2=='i'){
                        fscanf(stdin,"%li",va_arg(ptr,long*));
                        fprintf(stdout,"%s",token+3);
                    }
                    else if(ch2=='f'){
                        fscanf(stdin,"%lf",va_arg(ptr,double*));
                        fprintf(stdout,"%s",token+3);
                    }
                }
                else if(ch1=='L'){
                    char ch2=token[2];
                    if(ch2=='u'||ch2=='d'||ch2=='i'){
                        fscanf(stdin,"%Li",va_arg(ptr,long long*));
                        fprintf(stdout,"%s",token+3);
                    }
                    else if(ch2=='f'){
                        fscanf(stdin,"%Lf",va_arg(ptr,long double*));
                        fprintf(stdout,"%s",token+3);
                    }
                    }
                else if(ch1=='s'){
                    fscanf(stdin,"%s",va_arg(ptr,char*));
                    fprintf(stdout,"%s",token+2);
                }
            }
            else{
                
                fprintf(stdout,"%s",token);
            }
        }
    }
}
int main(){
    int a;float b; char c;char s[20]; short d;long long e;
    xscanf("Scan this %i HEllo %c %sBYEBYe",&a,&c,s);
    printf("%i -%c- >%s<",a,c,s);
    return 0;
}
//bugs: xscanf("%i %c %s",&a,&c); returns segfault whereas scanf doesnt
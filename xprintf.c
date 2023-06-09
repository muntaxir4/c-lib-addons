#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

void xprintf(char *str,...){   
    va_list ptr;
    va_start(ptr,str);
    char token[50];int k=0;   
    for(int i=0;str[i]!='\0';i++){
        token[k++]=str[i];
        if(str[i+1]=='%'||str[i+1]=='\0'){
            token[k]='\0';k=0;
            if(token[0]!='%'){
                fprintf(stdout,"%s",token);
            }
            else{
                int j=1;char ch1=0;
                while((ch1=token[j++])<58) {}
                if(ch1=='i'||ch1=='d'|| ch1=='u'||ch1=='h'){
                    if(ch1=='h') j=j+1;
                    fprintf(stdout,token,va_arg(ptr,int));
                }
                else if(ch1=='c'){
                    fprintf(stdout,token,va_arg(ptr,int));
                }
                else if(ch1=='f'){
                    fprintf(stdout,token,va_arg(ptr,double));
                }
                else if(ch1=='l'){
                    char ch2=token[2];
                    if(ch2=='u'||ch2=='d'||ch2=='i'){
                        fprintf(stdout,token,va_arg(ptr,long));
                    }
                    else if(ch2=='f'){
                        fprintf(stdout,token,va_arg(ptr,double));
                    }
                }
                else if(ch1=='L'){
                    char ch2=token[2];
                    if(ch2=='u'||ch2=='d'||ch2=='i'){
                        fprintf(stdout,token,va_arg(ptr,long long));
                    }
                    else if(ch2=='f'){
                        fprintf(stdout,token,va_arg(ptr,long double));
                    }
                }
                else if(ch1=='s'){
                    fprintf(stdout,token,va_arg(ptr,char*));
                }
                else{
                    fprintf(stdout,"%s",token);
                }
            }
        }
    }
}
int main() {
    clock_t start=clock();
    printf("The quick %i brown %.4f fox %c jumped over %li the lazy %s dog", 69, 69.1, 'x', 696969,"The rise of 69");
    printf("\n%fs\n",(float)(clock()-start)/CLOCKS_PER_SEC);
    start=clock();
    xprintf("The quick %i brown %.4f fox %c jumped over %li the lazy %s dog", 69, 69.1, 'x', 696969,"The rise of 69");
    printf("\n%fs\n",(float)(clock()-start)/CLOCKS_PER_SEC);
    //print
    return 0;
}
#include <stdio.h>
#include <stdarg.h>

int mprintf(const char *str,...){   
    va_list ptr;
    va_start(ptr,str);//str is the last known variable name
    char token[1000];
    int k=0;//index of where to store the characters of str in token
    for(int i=0;str[i]!='\0';i++){
        token[k++]=str[i];
        if(str[i+1]=='%'||str[i+1]=='\0'){
            token[k]='\0';k=0;//the token becomes a string when terminated with '\0'
            if(token[0]!='%'){
                fprintf(stdout,"%s",token);//printing the whole token if it is not a format specifier
            }
            else{
                int j=1;char ch1=0;
                while((ch1=token[j++])<58) {}//this loop is required when printing formatted value like 0.2f, when ch1='f' loop ends
                if(ch1=='i'||ch1=='d'|| ch1=='u'||ch1=='h'){
                    fprintf(stdout,token,va_arg(ptr,int));
                }
                else if(ch1=='c'){
                    fprintf(stdout,token,va_arg(ptr,int));//gcc compiler promotes char in va_arg to int by default
                }
                else if(ch1=='f'){
                    fprintf(stdout,token,va_arg(ptr,double));//gcc compiler promotes float in va_arg to double by default
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
                    fprintf(stdout,"%s",token);//print the whole token if no case is matched
                }
            }
        }
    }
    va_end(ptr);
    return 0;
}
// int main() {
//     mprintf("The quick %i brown %.4f fox %c jumped over %li the lazy %s dog", 23, 20.23, 'x', 20202020,"The rise of Humans");
//     return 0;
// }
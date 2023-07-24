#include <stdio.h>
#include <stdarg.h>

int mscanf(const char *str,...){
    char token[50];int k=0;
    va_list ptr;
    va_start(ptr,str);//str is the last known variable name
    for(int i=0;str[i]!='\0';i++){//loop runs till null character is found in str
        token[k++]=str[i];        
        if(str[i+1]=='%' || str[i+1]=='\0'){
            token[k]='\0';//terminating with null char to make it a string
            k=0;
            char ch1=token[1];
            if(ch1=='i'||ch1=='d'|| ch1=='u'){
                fscanf(stdin,"%i",va_arg(ptr,int*));
            }
            else if(ch1=='h'){
                fscanf(stdin,"%hi",va_arg(ptr,short*));
            }
            else if(ch1=='c'){
                char c;//scanf() ignores ' ' and '\n' if it is scanning char format
                while((c=fgetc(stdin))=='\n'||c==' '||c==EOF){}//using this loop to ignore some chars
                *va_arg(ptr,char*)=c;//storing the char value now
            }
            else if(ch1=='f'){
                fscanf(stdin,"%f",va_arg(ptr,float*));
            }
            else if(ch1=='l'){
                char ch2=token[2];
                if(ch2=='u'||ch2=='d'||ch2=='i'){
                    fscanf(stdin,"%li",va_arg(ptr,long*));
                }
                else if(ch2=='f'){
                    fscanf(stdin,"%lf",va_arg(ptr,double*));
                }
            }
            else if(ch1=='L'){
                char ch2=token[2];
                if(ch2=='u'||ch2=='d'||ch2=='i'){
                    fscanf(stdin,"%Li",va_arg(ptr,long long*));
                }
                else if(ch2=='f'){
                    fscanf(stdin,"%Lf",va_arg(ptr,long double*));
                }
                }
            else if(ch1=='s'){
                fscanf(stdin,"%s",va_arg(ptr,char*));
            }
        }
    }
    va_end(ptr);
    return 0;
}
// int main(){
//     int a;char c;char s[20];
//     mscanf("%i %c %s",&a,&c,s);
//     printf("%i %c %s",a,c,s);
//     return 0;
// }
//bugs: xscanf("%i %c %s",&a,&c); returns segfault whereas scanf doesnt
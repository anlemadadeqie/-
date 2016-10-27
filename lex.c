/*************************************************************************
	> File Name: 编译器.c
	> Author:jiafei 
	> Mail:hjh@xiyoulinux.org 
	> Created Time: 2016年10月18日 星期二 15时09分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char keyword[][20] = {"int","long","float","double","short","char","return","break","if","else","for","while","continue","switch","case","void","default","struct","define","static","do","main","printf"};

int length = 21;

int isNum(char c){
    if(c >= '0' && c <= '9'){
        return 0;
    }
    return -1;
}


int isLetter(char c){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        return 0;
    }
    return -1;
}

char getLetter(char *s){
    return *s;
}


void Print(char *x, char *s){

  printf("<%s, %s>\n", x, s);
}



void Judge(char *s){
    char ch = NULL ;
    char stringbuffer[100];
    int state = 0;
    int i = 0;
    
    while(ch != '\n'){
    switch(state){
        case 0:
            ch = getLetter(s++);
            switch(ch){
                case '[':
                case ']':
                case '(':
                case ')':
                case ';':
                case ',':
                case '{':
                case '}':
                case '#':
                case '<':
                case '>':
                case '.':
                case '"':
                    stringbuffer[i++] = ch;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer, "界符");
                    state = 0;
                    i = 0;
                    break;

                case ' ': 
                    state = 0;
                    break;
                case '\t':
                    state = 0;
                    break;
                case '+':
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '+' && ch != '='){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");

                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                        
                    }
                    break;

                case '-' : 
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '-' && ch != '='){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;

                case '=' :
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '='){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;

                case '&':
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '&'){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;

                case '|':
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '|'){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;

                case '*':
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '='){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        Print(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;


                case '/':
                    stringbuffer[i++] = ch;
                    ch = getLetter(s++);
                    if(ch != '='){
                        s--;
                        stringbuffer[i] = '\0';
                        i = 0;
                        Print(stringbuffer, "运算符");
                    }else{
                        stringbuffer[i++] = ch;
                        stringbuffer[i] = '\0';
                        printf(stringbuffer,"运算符");
                        i = 0;
                        state = 0;
                    }
                    break;

                default:
                if((ch == '_') || (isLetter(ch == 0))){
                    stringbuffer[i++] = ch;
                    state = 1;

                }else if(isNum(ch) == 0){
                    stringbuffer[i++] = ch;
                    state = 2;
    
                }else{
                    printf("输入不符合规范!");
                
                }
            }
            break;


        case 1:     //判断字母
            ch = getLetter(s++);
            if((ch == '_') || (isNum(ch) == 0) || (isLetter(ch) == 0)){
                stringbuffer[i++] = ch;
                state = 1;
            }else{
                s--;
                stringbuffer[i] = '\0';
                i = 0;
                int j = 0;
                for(j = 0; j < length; j++){
                    if((strcmp(stringbuffer, keyword[j] )) == 0){
                        Print(stringbuffer, "关键字");
                        state = 0;
                        break;
                    }else{
                        Print(stringbuffer, "标识符");
                        state = 0;
                        break;
                    }
                }
                
            }
            break;

        case 2:     //判断数字
        
            ch = getLetter(s++);
            if(isNum(ch) == 0){
                stringbuffer[i++] = ch;
            }else if(ch == '.'){
                stringbuffer[i++] = ch;
                state = 3;
            }else if(ch == 'E' || ch == 'e'){
                stringbuffer[i++] = ch;
                state = 4;
            }else{
                    s--;
                    stringbuffer[i] = '\0';
                    Print(stringbuffer,"数字");
                    i = 0;
            }
            break;
                
        case 3:
            ch = getLetter(s++);
            if(isNum(ch) == 0){
                stringbuffer[i++] = ch;
                state = 5;
            }else{
                printf("输入格式有错！");

            }
            break;

        case 4:
            ch = getLetter(s++);
            if(isNum(ch) == 0){
                stringbuffer[i++] = ch;
            }else{
                s--;
                stringbuffer[i] = '\0';
                Print(stringbuffer,"数字");
                i = 0;

            }
            break;

        case 5:
            ch = getLetter(s++);
            if(isNum(ch) == 0){
                stringbuffer[i++] = ch;
            }else if(ch == 'E' || ch == 'e'){
                stringbuffer[i++] = ch;
                state = 4;
            }else{
                s--;
                stringbuffer[i] = '\0';
                Print(stringbuffer, "数字");
                i = 0;
            }
            break;
        }     
    }
    
}


int main(){

    char buffer[1024];
    FILE* fp;
    char ch;

    if((fp = fopen("test.txt","r+")) == NULL){
        
        printf("打开文件失败！");
    }
    
    fgets(buffer, 1024, fp);
    while(!feof(fp)){

        Judge(buffer);
        fgets(buffer,1024,fp);

    }

    fclose(fp);

    return 0;
}

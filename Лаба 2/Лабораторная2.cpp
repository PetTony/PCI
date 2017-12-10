#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

int main (){
	setlocale(LC_ALL, "rus");
	int len; 
	char *code = new char[1000];
	printf("Введите ключ: ");
	scanf("%s", code);
	len=strlen(code);
	//printf("Длина: %d", len);
	FILE *fp1, *fp2, *fp3;
	fp1=fopen("input.txt", "r");
	fp2=fopen("encrypt.txt", "w");
	fp3=fopen("decrypt.txt", "w");
	int flag;
    char point;
    int circle=0; // круг
    point=getc(fp1);
    while (!feof(fp1)){
    		if (circle<=len){
    			point=point^code[circle];
    			circle++;
    		}
    		else{
    			circle=0;
    			point=point^code[circle];
    			circle++;
    		}
    			fprintf(fp2, "%c", point);    			
        	point = getc(fp1);
    }
    //дешифрация
    fclose (fp2);
    fp2=fopen("encrypt.txt", "r");
    circle=0; // круг
    point=getc(fp2);
    while (!feof(fp2)){
    		if (circle<=len){
    			point=point^code[circle];
    			circle++;
    		}
    		else{
    			circle=0;
    			point=point^code[circle];
    			circle++;
    		}
    			fprintf(fp3, "%c", point);    			
        	point = getc(fp2);
    }
	fclose (fp1);
	fclose (fp2);
	fclose (fp3);
	getchar();
	return 0;
}



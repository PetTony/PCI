#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void encrypt (int key){
	FILE *fp1, *fp2;
	fp1=fopen("input.txt", "r");
	fp2=fopen("encrypt.txt", "w");
    int flag;
    char point;
    point=getc(fp1);
    while (!feof(fp1)){
    	flag=0;
    	if (point>='a' && point<='z'){
    		point=toupper(point);
		}
    	if (point>='A' && point<='Z'){
    		point=point+(key%26);
    		if (point>'Z')
    			point='A'+(point-'Z')-1;
    			fprintf(fp2, "%c", point);
    			flag=1;    			
    	}
    	if (!flag) fprintf (fp2, "%c", point);
        	point = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}

void decrypt (int key){
	FILE *fp2, *fp3, *fp4;
	fp2=fopen("encrypt.txt", "r");
	fp3=fopen("analyze.txt", "r");
	fp4=fopen("decrypt.txt", "w");
	int flag, counter=0, save;
    int arrayAnalyze[2][92]={0};
    int arrayEncrypt[2][92]={0};
    int tmp, digit;
    char point;
    
//  частота символов в анализируемом тексте
    point=getc(fp3);
    while (!feof(fp3)){
    	if (point>='A' && point<='Z'){
    		digit=point;
    		arrayAnalyze[0][digit]++;   			
    	}
    	if (point>='a' && point<='z'){
    		digit=toupper(point);
    		arrayAnalyze[0][digit]++;    			
    	} 
        	point = getc(fp3);
        	counter++;
    }
    printf("счётчик: %d\n", counter);    
    counter=0;
  //  частота символов в зашифрованном тексте
    point=getc(fp2);
    while (!feof(fp2)){
    	if (point>='A' && point<='Z'){
    		digit=point;
    		arrayEncrypt[0][digit]++;   			
    	}
    	if (point>='a' && point<='z'){
    		digit=toupper(point);
    		arrayEncrypt[0][digit]++;    			
    	} 
    	
        	point = getc(fp2);
        	counter++;
    }  
    printf("счётчик: %d\n", counter);  
    counter=0;
    // дозаполнение массивов
    flag=65;
    while(flag<=90){
    	arrayEncrypt[1][flag]=flag;
    	arrayAnalyze[1][flag]=flag;
    	flag++;
    }
    
    printf("\n");
    fclose (fp2);
    
    // сортировка arrayAnalyze 
    
    bool noSwap;
	for (int i = 90; i >= 65; i--){
    	noSwap = 1;
    	for (int j = 65; j <= i; j++)	{
     	    if (arrayAnalyze[0][j]>arrayAnalyze[0][j+1]) {
      			arrayAnalyze[0][91] = arrayAnalyze[0][j];
      			arrayAnalyze[1][91] = arrayAnalyze[1][j];
      			arrayAnalyze[0][j] = arrayAnalyze[0][j+1];
      			arrayAnalyze[1][j] = arrayAnalyze[1][j+1];
      			arrayAnalyze[0][j+1] = arrayAnalyze[0][91];
      			arrayAnalyze[1][j+1] = arrayAnalyze[1][91];
       	    	noSwap = 0;
    		}
   	 	}
    	if (noSwap == 1)
      	  break;
		}
	counter=0;	
	printf("Отсортированный массив\n");
    flag=65;
    while(flag<=90){
    	printf("%d ", flag);
    	printf("%d ", arrayAnalyze[0][flag]);
    	printf("%d \n", arrayAnalyze[1][flag]);
    	counter+=arrayAnalyze[0][flag];
    	flag++;
    }
    printf("\n");
    printf("Общее количество символов: %d\n", counter);
    // сортировка arrayEncrypt
    for (int i = 90; i >= 65; i--){
    noSwap = 1;
    for (int j = 65; j <= i; j++)	{
     	if (arrayEncrypt[0][j]>arrayEncrypt[0][j+1]) {
      		arrayEncrypt[0][91] = arrayEncrypt[0][j];
      		arrayEncrypt[1][91] = arrayEncrypt[1][j];
      		arrayEncrypt[0][j] = arrayEncrypt[0][j+1];
      		arrayEncrypt[1][j] = arrayEncrypt[1][j+1];
      		arrayEncrypt[0][j+1] = arrayEncrypt[0][91];
      		arrayEncrypt[1][j+1] = arrayEncrypt[1][91];
       	    noSwap = 0;
    	}
   	}
    if (noSwap == 1)
      	break;
	}
	counter=0;	
	printf("Отсортированный массив\n");
    flag=65;
    while(flag<=90){
    	printf("%d ", flag);
    	printf("%d ", arrayEncrypt[0][flag]);
    	printf("%d \n", arrayEncrypt[1][flag]);
    	counter+=arrayAnalyze[0][flag];
    	flag++;
    }
    printf("\n");
     printf("Общее количество символов: %d\n", counter);
    // выходной файл
    fp2=fopen("encrypt.txt", "r");
    point=getc(fp2);
    while (!feof(fp2)){
    	if (point>='a' && point<='z'){
    			point=toupper(point);
    		}
    	flag=0;
    	if (point>='A' && point<='Z'){
    		flag=1;
    		tmp=65;
    		while(arrayEncrypt[1][tmp]!=point){
    			tmp++;
    		}
    		fprintf (fp4, "%c", arrayAnalyze[1][tmp]);  			
    	}
    	else
    		if (!flag) fprintf (fp4, "%c", point);
        	point = getc(fp2);
    }	
    fclose (fp2);
    fclose (fp3);
    fclose (fp4);
}
    	
int main (){
	setlocale(LC_ALL, "rus");
	int key=0;
	while ((key<=0) || (key>=26)){
		printf("Введите целочисленный ключ:");
		scanf("%d", &key);
	}
		encrypt (key);
		decrypt (key);
	getchar ();
	return 0;
}





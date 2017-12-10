/*  описание лабы
n,e - открытые числа
d - закрытое число
в main генерируются открытые числа, передаются функции, она шифрует текст
из main дешифруем
*/	
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


int abonent(unsigned long long int e,unsigned long long int n){
	unsigned long long int sch,save,point;
	FILE *fp1;
	fp1=fopen("log.txt", "w");
	fprintf(fp1,"Открытый ключ е: %llu\nОткрытый ключ n: %llu\n",e,n);
	printf("Введите число для шифрования:\n");
	scanf("%llu",&point);
	printf("Исходный код: %llu\n",point);
    point=pow(point,e);
	point%=n;
    printf("Шифр: %llu\n", point);    			
	fclose (fp1);
	return (point);
}

int main (){
	setlocale(LC_ALL, "rus");
	unsigned long long int n,p,q,m,i,d,e,encrypt,mod1=0,mod2=1;
	int v,publicYa,publicYb,one,two,yes,flag,sch=0;
	printf("Введите число p:\n");
	while(sch!=1){
		scanf("%llu",&p);
		m=p/3;	
		i=2;
		flag=1;
		while(flag!=0 && i<=m){
			flag=p%i;
			i++;
		}
		if(flag==0||p==4){
			printf("Число составное, повторите ввод:\n");
		}
		else{
			printf("Число простое\n");
			sch=1;
		}
	}
	sch=0;
	printf("Введите число q:\n");
	while(sch!=1){
		scanf("%llu",&q);
		m=q/3;	
		i=2;
		flag=1;
		while(flag!=0 && i<=m){
			flag=q%i;
			i++;
		}
		if(flag==0||q==4){
			printf("Число составное, повторите ввод:\n");
		}
		else{
			printf("Число простое\n");
			sch=1;
		}
	}
	// вычисление n,m
	n=p*q;
	printf("n: %llu\n",n);
	m=(p-1)*(q-1);
	printf("m: %llu\n",m);
	// проверка взаимно простого числа
	sch=0;
	printf("Введите число e, взаимно простое с m:\n");
	while(sch!=1){
		scanf("%llu",&e);
		if (e<m){	
		i=2;
		while(mod1!=mod2 && i<=e){
			mod1=m%i;
			mod2=e%i;
			i++;
		}
		if(mod1==mod2&&mod1==0){
			printf("Число не являются взаимно простыми, повторите ввод:\n");
			mod1=0;
			mod2=1;
		}
		else{
			printf("Числа взаимно простые\n");
			sch=1;	
			}
		}
		else{
			printf("Число e должно быть меньше m\n");
		}
	}
	// определение d
	d=1;
	while((e*d)%m!=1){
		d++;
	}
	printf("Число d: %llu\n", d);
	// передача открытых ключей	
	encrypt=abonent(e,n);
	// дешифрация
	encrypt=pow(encrypt,e);
	encrypt%=n;
    printf("Расшифрованное число %llu\n", encrypt); 
	getchar();
	return 0;
}






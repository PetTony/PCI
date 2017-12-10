/*  1)Глобальные открытые элементы:
		n-случаное простое число
		g<n
	2)Абонентом А вычисляется:
		выбирается секретное число Xa<n
		вычисляется открытое значение Ya=g^(Xa) mod n
	3)Абонентом B вычисляется:
		выбирается секретное число Xb<n
		вычисляется открытое значение Yb=g^(Xb) mod 
	4) Вычисление ключей
		вычисляется секретный ключ абонентом A: K=Yb^(Xa) mod n
		вычисляется секретный ключ абонентом B: K=Ya^(Xb) mod n
*/	
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
		
int abonentTwo(unsigned long long int n, unsigned long long int g, int publicYa){
	unsigned long long int secretXb, publicYb, key;
		int flag=0;
		FILE *fp1;
		fp1=fopen("log.txt", "a");
		while(flag==0){
			printf("Введите секретное число Xb:\n");
			scanf("%llu",&secretXb);
			if(secretXb<n){
				flag=1;
			}
		}
	    publicYb=pow(g,secretXb);
		publicYb=publicYb % n;
		key=pow(publicYa,secretXb);
		key=key % n;
		printf("Переданное значение от 1абонента Ya: %llu\n",publicYa);
		printf("ключ: %llu\n",key);
	//	fprintf(fp1, "Ключ B: %llu\n", key);
		return(publicYb);
};

int abonentOne(unsigned long long int n, unsigned long long int g, int publicYb){
	unsigned long long int secretXa, publicYa, key;
		int flag=0;
		FILE *fp1;
		fp1=fopen("log.txt", "w");
		while(flag==0){
			printf("Введите секретное число Xa:\n");
			scanf("%llu",&secretXa);
			if(secretXa<n){
				flag=1;
			}
		}
		publicYa=pow(g,secretXa);
		publicYa=publicYa%n;
		fprintf(fp1, "Открытое значение n: %llu\nОткрытое значение g: %llu\n",n,g);
		fprintf(fp1, "Открытое значение public Ya: %llu\n", publicYa);
		publicYb=abonentTwo(n,g,publicYa);// вычисленное открытое значение передаём второму абоненту и ждём ответ
		fprintf(fp1, "Открытое значение public Yb: %llu\n", publicYb);
		printf("Переданное значение от 2абонента Yb: %llu\n",publicYb);
		key=pow(publicYb,secretXa);
		key=key % n;
	//	fprintf(fp1, "Ключ А: %llu\n", key);
		printf("ключ: %llu\n",key);
		fclose (fp1);
		return 0;
};

int main (){
	setlocale(LC_ALL, "rus");
	unsigned long long int n,m,i,flag,g;
	printf("Введите случайное простое число n:\n");
	scanf("%llu",&n);
	m=n/3;	
	i=2;
	flag=1;
	while(flag!=0 && i<=m){
		flag=n%i;
		i++;
	}
	if(flag==0||n==4){
		printf("Число составное\n");
	}
	else{
		printf("Число простое\n");
		flag=0;
		while(flag!=1){
			printf("Введите g:\n");
			scanf("%llu",&g);
			if(g<n){
				flag=1;
			}
		}
		abonentOne(n,g,0);	
	}
	getchar ();
	return 0;
}






/*  1)���������� �������� ��������:
		n-�������� ������� �����
		g<n
	2)��������� � �����������:
		���������� ��������� ����� Xa<n
		����������� �������� �������� Ya=g^(Xa) mod n
	3)��������� B �����������:
		���������� ��������� ����� Xb<n
		����������� �������� �������� Yb=g^(Xb) mod 
	4) ���������� ������
		����������� ��������� ���� ��������� A: K=Yb^(Xa) mod n
		����������� ��������� ���� ��������� B: K=Ya^(Xb) mod n
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
			printf("������� ��������� ����� Xb:\n");
			scanf("%llu",&secretXb);
			if(secretXb<n){
				flag=1;
			}
		}
	    publicYb=pow(g,secretXb);
		publicYb=publicYb % n;
		key=pow(publicYa,secretXb);
		key=key % n;
		printf("���������� �������� �� 1�������� Ya: %llu\n",publicYa);
		printf("����: %llu\n",key);
	//	fprintf(fp1, "���� B: %llu\n", key);
		return(publicYb);
};

int abonentOne(unsigned long long int n, unsigned long long int g, int publicYb){
	unsigned long long int secretXa, publicYa, key;
		int flag=0;
		FILE *fp1;
		fp1=fopen("log.txt", "w");
		while(flag==0){
			printf("������� ��������� ����� Xa:\n");
			scanf("%llu",&secretXa);
			if(secretXa<n){
				flag=1;
			}
		}
		publicYa=pow(g,secretXa);
		publicYa=publicYa%n;
		fprintf(fp1, "�������� �������� n: %llu\n�������� �������� g: %llu\n",n,g);
		fprintf(fp1, "�������� �������� public Ya: %llu\n", publicYa);
		publicYb=abonentTwo(n,g,publicYa);// ����������� �������� �������� ������� ������� �������� � ��� �����
		fprintf(fp1, "�������� �������� public Yb: %llu\n", publicYb);
		printf("���������� �������� �� 2�������� Yb: %llu\n",publicYb);
		key=pow(publicYb,secretXa);
		key=key % n;
	//	fprintf(fp1, "���� �: %llu\n", key);
		printf("����: %llu\n",key);
		fclose (fp1);
		return 0;
};

int main (){
	setlocale(LC_ALL, "rus");
	unsigned long long int n,m,i,flag,g;
	printf("������� ��������� ������� ����� n:\n");
	scanf("%llu",&n);
	m=n/3;	
	i=2;
	flag=1;
	while(flag!=0 && i<=m){
		flag=n%i;
		i++;
	}
	if(flag==0||n==4){
		printf("����� ���������\n");
	}
	else{
		printf("����� �������\n");
		flag=0;
		while(flag!=1){
			printf("������� g:\n");
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






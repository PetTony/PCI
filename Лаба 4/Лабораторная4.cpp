/*  �������� ����
n,e - �������� �����
d - �������� �����
� main ������������ �������� �����, ���������� �������, ��� ������� �����
�� main ���������
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
	fprintf(fp1,"�������� ���� �: %llu\n�������� ���� n: %llu\n",e,n);
	printf("������� ����� ��� ����������:\n");
	scanf("%llu",&point);
	printf("�������� ���: %llu\n",point);
    point=pow(point,e);
	point%=n;
    printf("����: %llu\n", point);    			
	fclose (fp1);
	return (point);
}

int main (){
	setlocale(LC_ALL, "rus");
	unsigned long long int n,p,q,m,i,d,e,encrypt,mod1=0,mod2=1;
	int v,publicYa,publicYb,one,two,yes,flag,sch=0;
	printf("������� ����� p:\n");
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
			printf("����� ���������, ��������� ����:\n");
		}
		else{
			printf("����� �������\n");
			sch=1;
		}
	}
	sch=0;
	printf("������� ����� q:\n");
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
			printf("����� ���������, ��������� ����:\n");
		}
		else{
			printf("����� �������\n");
			sch=1;
		}
	}
	// ���������� n,m
	n=p*q;
	printf("n: %llu\n",n);
	m=(p-1)*(q-1);
	printf("m: %llu\n",m);
	// �������� ������� �������� �����
	sch=0;
	printf("������� ����� e, ������� ������� � m:\n");
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
			printf("����� �� �������� ������� ��������, ��������� ����:\n");
			mod1=0;
			mod2=1;
		}
		else{
			printf("����� ������� �������\n");
			sch=1;	
			}
		}
		else{
			printf("����� e ������ ���� ������ m\n");
		}
	}
	// ����������� d
	d=1;
	while((e*d)%m!=1){
		d++;
	}
	printf("����� d: %llu\n", d);
	// �������� �������� ������	
	encrypt=abonent(e,n);
	// ����������
	encrypt=pow(encrypt,e);
	encrypt%=n;
    printf("�������������� ����� %llu\n", encrypt); 
	getchar();
	return 0;
}






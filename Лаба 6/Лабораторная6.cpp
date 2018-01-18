#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// функция pow
unsigned long long int fpow(int osn, int degree){
	unsigned long long int saveosn,deg;
	for(saveosn=osn,deg=1;deg<degree;deg++){
		saveosn*=osn;
	}
	return saveosn;
}

// функция ChToInt
int CharToInt(int Symbol){
	switch (Symbol){
   		case 48:{
    		Symbol=0;
    		break;
    	}
   		case 49:{
    		Symbol=1;
    		break;
    	}
    	case 50:{
    		Symbol=2;
    		break;
    	}
    	case 51:{
    		Symbol=3;
    		break;
    	}
    	case 52:{
    		Symbol=4;
    		break;
   		}
    	case 53:{
    		Symbol=5;
    		break;
    	}
    	case 54:{
    		Symbol=6;
    		break;
    	}
    	case 55:{
    		Symbol=7;
    		break;
    	}
    	case 56:{
    		Symbol=8;
    		break;
    	}
    	case 57:{
    		Symbol=9;
    		break;
    	}
    	default:{
    		break;
    	}
   	}
	return Symbol;
}

// функция хеширования
int Hash(int one, int two, int three, int four, int five, int six){
	return (one+two+three+four+five)%10+1;
}

// функция определения простоты числа
int Easy(unsigned long long int Per){
	unsigned long long int m,i,flag,res;
		m=Per/3;	
		i=2;
		flag=1;
		while(flag!=0 && i<=m){
			flag=Per%i;
			i++;
		}
		if(flag==0||Per==4){
			res=0;
		}
		else{
			res=1;
		}
	return (res);
}

// проверка взаимно простого числа
int VzEasy(unsigned long long int b){
	int mod1=0, mod2=1, sch=0,tmpg=2,j=2;
	while(sch!=1&&tmpg<b){
		while(mod1!=mod2 && j<=b){
			mod1=b%j;
			mod2=tmpg%j;
			j++;
		}
		if(mod1==mod2&&mod1==0){
			tmpg++;
		}
		else{
			sch=1;	
			}
		}
		return (tmpg);
	}

//сервер
unsigned long long int Server(int username, int salt, int pv, int P4, int P5, int P6, int P7){
	unsigned long long int rez, flag, B, b, k=3, us, Ks,Ss,Ns,gs;
	char point;
	switch(P7){
		case 0:{
			FILE *fp1;
			fp1=fopen("Server.txt", "w");
			if (P7==0){
				fprintf(fp1,"Username:\n%d\nSalt:\n%d\nVerifier:\n%d\ng:\n%d\nN:\n%d\n",username,salt,pv,P5, P6);
				printf("Пользователь зарегистрирован!\n");
				fclose (fp1);
   				return (0);
				break;
			}
		}
		// начало аутентификации
		case 1:{
			if (P5!=0){
				FILE *fp1;
				int intpoint,temppoint,circle=0;
				fp1=fopen("Server.txt", "r");
    			point=getc(fp1);
    			while (!feof(fp1)){
    				flag=0;
    				intpoint=point;
    				while(intpoint!=10){
    					intpoint=point;
    					intpoint=CharToInt(intpoint);			   	
    					if (flag==0){
    						temppoint=intpoint;
    					}
    					if (flag>0){
    						temppoint*=10;
    						temppoint+=intpoint;
    					}
    					point=getc(fp1);
    					intpoint=point;
    					flag++;
    				}
    				if(circle==1){
    					username=temppoint;
						printf("Username: %d\n",temppoint);
						temppoint=0;	
    				}
    				if(circle==3){
    					salt=temppoint;
    					temppoint=0;
						printf("Salt: %d\n",salt);	
    				}
    				if(circle==5){
    					pv=temppoint;
						temppoint=0;	
    					printf("Verifier: %d\n",pv);
    				}
    				if(circle==7){
    					gs=temppoint;
						temppoint=0;	
    					printf("gs: %d\n",gs);
    				}
    				if(circle==9){
    					Ns=temppoint;
						temppoint=0;	
    					printf("Ns: %d\n",Ns);
    				}
					circle++;
					point=getc(fp1);
				
			}       
			// получение B,b
			printf("Введите произвольное числовое значение b: \n");
			scanf("%d",&b);	
			B=k*pv; 
			B+=fpow(gs,b);
		//	printf("B=%d\n",B);
		//	printf("А=%d\n",P5);
			us=Hash(P5,B,0,0,0,0);
		//	printf("us=%d\n",us);
			if (us!=0){
		//		printf("Pv%d\n", pv);
				Ss=fpow(pv,us);
		//			printf("fpow(pv,us)%d\n", Ss);
				Ss=Ss%Ns;
		//			printf("Ss%d\n", Ss);
		//			printf("B%d\n", B);
				Ss=fpow(Ss,B);
		//			printf("fpow(Ss,B)%d\n", Ss);
				Ss=P5*Ss;
		//		printf("P5*Ss%d\n", Ss);
				Ss=Ss%Ns;
		//		printf("ostgs%d\n", Ss);
		//		printf("S%d\n", Ss);
				Ks=Hash(Ss,0,0,0,0,0);
				printf("Ks%d\n", Ks);
			//	Ss=((fpow(fpow(pv,us)%Ns,B))*P5)%gs;
			//	printf("S%d\n", Ss);
			//	Ks=Hash(Ss,0,0,0,0,0);
			//	printf("Ks%d\n", Ks);
				int Ms=0,Htemps;
		//		printf("Разбор\n");
		//		printf("Ns:%d\n",Ns);
		//			printf("gs:%d\n",gs);
		//			printf("username:%d\n",username);
		//			printf("salt:%d\n",salt);
		//			printf("P5:%d\n",P5);
		//			printf("B:%d\n",B);
		//			printf("Ks:%d\n",Ks);
				Ms=Hash((Hash(Ns,0,0,0,0,0)^Hash(gs,0,0,0,0,0)),Hash(username,0,0,0,0,0),salt,P5,B,Ks);
			//	printf("Server Ms:%d\n", Ms);
				//Ms=0;
				//	Ms=Hash(Ns,0,0,0,0,0);
				//	Htemps=Hash(gs,0,0,0,0,0);
				//	Ms=Ms^Htemps;
				//	Htemps=Hash(username,0,0,0,0,0);
				//	Ms=Hash(Ms,Htemps,salt,P5,B,Ks);
				//	printf("Server new Ms:%d",Ms);
				fp1=fopen("log.txt", "w");
				fprintf(fp1,"B:\n%d\nus:\n%d\nK:\n%d\nMs:\n%d\n",B,us,Ks,Ms);
				fclose (fp1);
				return B;
			}
			else
				printf("Ошибка, процесс аутентификации прерван1!!!\n");
				return (-4);
			}
			else{
				printf("Ошибка, процесс аутентификации прерван2!!!\n");
				return (-5);
			}
			break;
		}
		case 2:{
			FILE *fp1;
			int intpoint,temppoint,circle=0;
			fp1=fopen("Server.txt", "r");
    		point=getc(fp1);
    		while (!feof(fp1)){
    			flag=0;
    			intpoint=point;
    			while(intpoint!=10){
    				intpoint=point;
    				intpoint=CharToInt(intpoint);			   	
    				if (flag==0){
    					temppoint=intpoint;
    				}
    				if (flag>0){
    					temppoint*=10;
    					temppoint+=intpoint;
    				}
    				point=getc(fp1);
    				intpoint=point;
    				flag++;
    			}
    			if(circle==3){
    				salt=temppoint;
    				temppoint=0;
				//	printf("Salt: %d\n",salt);	
    			}
				circle++;
				point=getc(fp1);	
			}
			fclose (fp1);
			return salt;
			break;
		}
		case 3:{
			FILE *fp1;
			int intpoint,temppoint,circle=0,Ms;
			fp1=fopen("log.txt", "r");
    		point=getc(fp1);
    		while (!feof(fp1)){
    			flag=0;
    			intpoint=point;
    			while(intpoint!=10){
    				intpoint=point;
    				intpoint=CharToInt(intpoint);			   	
    				if (flag==0){
    					temppoint=intpoint;
    				}
    				if (flag>0){
    					temppoint*=10;
    					temppoint+=intpoint;
    				}
    				point=getc(fp1);
    				intpoint=point;
    				flag++;
    			}
    			if(circle==1||circle==3){
    				temppoint=0;
    			}
    			if(circle==5){
    				Ks=temppoint;
    				temppoint=0;
			//		printf("Ks from log: %d\n",Ks);	
    			}
    			if(circle==7){
    				Ms=temppoint;
    				temppoint=0;
			//		printf("Ms: %d\n",Ms);	
    			}
				circle++;
				point=getc(fp1);	
			}
	//		printf("Mc: %d\n",P6);
			if (Ms==P6){
				int Rs=Hash(P5,Ms,Ks,0,0,0);
				printf("Rs: %d\n",Rs);
				return Rs;
			}
			fclose (fp1);
			return -6;
			break;
		}
	}
   }
    
// клиент
int Client(int Var1, int Var2){
	unsigned long long int g,q,N=0;
	unsigned long long int usl,fl=0,fl1=0,S,tmp1,Kc;
	unsigned long long int I,p,x,v,a,s,A,err,Bc,uc,pass,errorc;
	FILE *fp1;
	// регистрация пользователя
	usl=0;
	while(usl==0){
		printf("Для регистрации пользователя нажмите 1, для аутентификации - 2, для  выхода - 3\n");
		scanf("%d",&fl1);
		switch (fl1){
			case 1:{
				// выбор q и определение N
				printf("Введите число q:\n");
				while(fl!=1){
					scanf("%llu",&q);
					usl=Easy(q);
					if(usl==1){
						N=2*q+1;
						usl=Easy(N);
						if(usl==1){
							fl=1;
							printf("Число N: %llu\n", N);
						}
						else
							printf("Введите другое число q:\n");
							usl=1;
					}
					if (usl!=1){
						printf("Введите другое число q:\n");
					}
				}
				// генератор мультипликативной группы g
				g=VzEasy(N);
				printf("Генератор мультипликативной группы g: %llu\n", g);
				// параметр-множитель (srp-6 - k=3)
				int k=3;
				// Теперь регистрация нового пользователя
				printf("Введите числовой идентификатор пользователя: \n");
				scanf("%d",&I);
				printf("Введите числовой пароль: \n");
				scanf("%d",&p);
				// генерация соли
				printf("Введите произвольную числовую соль: \n");
				scanf("%d",&s);
				x=Hash(s,p,0,0,0,0);
				v=fpow(g,x);
				v%=N;
				// хранилище клиента
				fp1=fopen("Client.txt", "w");
				fprintf(fp1,"Username:\n%d\nSalt:\n%d\ng:\n%d\nN:\n%d\n",I,s,g,N);
				fclose (fp1);
				Server(I,s,v,0,g,N,0);
				break;
			}
			case 2:{
				printf("Введите произвольное числовое значение a: \n");
				scanf("%d",&a);
				// нужно получить g и N
				int intpointcl,temppointcl,circlecl=0,flagcl,I;
				char pointcl;
				fp1=fopen("Client.txt", "r");
    				pointcl=getc(fp1);
    			while (!feof(fp1)){
    				flagcl=0;
    				intpointcl=pointcl;
    				while(intpointcl!=10){
    					intpointcl=pointcl;
						intpointcl=CharToInt(intpointcl);
    					if (flagcl==0){
    						temppointcl=intpointcl;
    					}
    					if (flagcl>0){
    						temppointcl*=10;
    						temppointcl+=intpointcl;
    					}
    					pointcl=getc(fp1);
    					intpointcl=pointcl;
    					flagcl++;
    				}
    				if(circlecl==1){
    					I=temppointcl;
						printf("Username: %d\n",temppointcl);
						temppointcl=0;	
    				}
    				if(circlecl==3){
    					s=temppointcl;
    					temppointcl=0;
						printf("Salt: %d\n",s);	
    				}
    				if(circlecl==5){
    					g=temppointcl;
						temppointcl=0;	
    					printf("g: %d\n",g);
    				}
    				if(circlecl==7){
    					N=temppointcl;
						temppointcl=0;	
    					printf("N: %d\n",N);
    				}
					circlecl++;
					pointcl=getc(fp1);
			}
				A=fpow(g,a);
				A%=N;
			//	printf("A=%d \n",A);
				Bc=Server(0,0,0,0,A,0,1);
				s=Server(0,0,0,0,0,0,2);
				if (Bc==0){
					errorc=-2;
				}
				if (Bc==-1){
					errorc=-1;
				}
				uc=Hash(A,Bc,0,0,0,0);
			//	printf("uc=%d\n",uc);
				if (uc==-1){
					errorc=-1;
				}
				if (uc==0){
					errorc=-3;
				}
				if (errorc!=-3&&errorc!=-2&&errorc!=-1){
					printf("Введите свой пароль: \n");
					scanf("%d",&pass);
					printf("Пароль:%d\n", pass);
					x=Hash(s,pass,0,0,0,0);
				//	printf("s:%d\n",s);
				//	printf("Hashx:%d\n",x);
				//	printf("g:%d\n",g);
					S=fpow(g,x);
				//	printf("S=fpow(g,x):%d\n",S);
				//	printf("N:%d\n",N);
					S=S%N;
				//	printf("S=S%N:%d\n",S);
				//		printf("uc:%d\n",uc);
				//			printf("a:%d\n",a);
					tmp1=a+uc*x;
				//	printf("tmp1=a+u*x:%d\n",tmp1);
					S=fpow(S,tmp1);
				//	printf("S=fpow(S,tmp1):%d\n",S);
				//		printf("Bc:%d\n",Bc);
					S=Bc-S;
				//	printf("S=Bc-S:%d\n",S);
					S=S%N;
				//	printf("S:%d\n",S);
					Kc=Hash(S,0,0,0,0,0);
					printf("Kc:%d\n",Kc);
					int Mc=0;
					int Htemp;
				/*	printf("Подробный разбор\n");
					printf("N:%d\n",N);
					printf("g:%d\n",g);
					printf("I:%d\n",I);
					printf("s:%d\n",s);
					printf("A:%d\n",A);
					printf("Bc:%d\n",Bc);
					printf("Kc:%d\n",Kc);*/
					Mc=Hash((Hash(N,0,0,0,0,0)^Hash(g,0,0,0,0,0)),Hash(I,0,0,0,0,0),s,A,Bc,Kc);
				//	printf("Mc:%d\n",Mc);
				//	Mc=0;
				//	Mc=Hash(N,0,0,0,0,0);
				//	Htemp=Hash(g,0,0,0,0,0);
				//	Mc=Mc^Htemp;
				//	Htemp=Hash(I,0,0,0,0,0);
				//	Mc=Hash(Mc,Htemp,s,A,Bc,Kc);
				//	printf("New Mc:%d\n",Mc);
					int Rcs,Rc;
					Rcs=Server(0,0,0,0,A,Mc,3);
					Rc=Hash(A,Mc,Kc,0,0,0);
					printf("Rc:%d\n",Rc);
				//	printf("Msc:%d\n",Msc);
					if (Rcs==Rc){
					printf("Успешная аутентификация!!!");
				}
				else{
					printf("Failed!!!");
				}
					}
					else{
						printf("Код ошибки: %d\n", errorc);
					}
			}
			case 3:{
				usl=1;
				break;
			}
			default:{
				printf("Некорректный ввод!!!\n");
				break;
			}
		}
	}
	return err;
}

int main (){
	setlocale(LC_ALL, "rus");
	Client(0,0);	
	getchar();
	return 0;
}




					   

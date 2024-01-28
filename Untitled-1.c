#include <stdio.h>
#include <stdlib.h>
int tabdilghamari(int a, int b, int c){
	int k,p,q,x,y;
	k=rooz(a,b,c);
	k=(k+429600)*355/365;
	p=k/355;
	q=(k-p*355)/30;
	x=p%30;
	printf("%d %d %d", p,q,x);
}
int tabdilmiladi(int a,int b, int c){
	int k,x,m,p,q,r,f;
	k=rooz(a,b,c);
	k-=651;
	p=k/365;
	q=k%365;
		if(q<=31){
			r=1;
			f=q;
		}
		else if(q<=59){
			r=2;
			f=q-31;
		}
		else if(q<=90){
			r=3;
			f=q-59;
		}
		else if(q<=120){
			r=4;
			f=q-90;
		}
		else if(q<=151){
			r=5;
			f=q-120;
		}
		else if(q<=181){
			r=6;
			f=q-151;
		}
		else if(q<=212){
			r=7;
			f=q-181;
		}
		else if(q<=243){
			r=8;
			f=q-212;
		}
		else if(q<=273){
			r=9;
			f=q-243;
		}
		else if(q<=304){
			r=10;
			f=q-273;
		}
		else if(q<=334){
			r=11;
			f=q-304;
		}
		else{
			r=12;
			f=q-334;
		}		
	printf("%d %d %d", 1800+p,r,f);
	
}
int rooz(int a, int b, int c){
	int x,y,z;
	x=(a-1177)/33;
	y=((a-1177)%33)/4;
	z=(a-1177)*365+x+y;
	if(1<=b && b<=6){
		z+=(b-1)*31+1;
	}
	else if(b>=7 && b<=11){
		z+=186+(b-7)*30+1;
	}
	else{
		z+=337;
	}
	z+=c;
	return z;
}
int taghvim(int a, int b){
	int x,y,z,k;
	x=(a-1177)/33;
	y=((a-1177)%33)/4;
	z=(a-1177)*365+x+y;
	if(1<=b && b<=6){
		z+=(b-1)*31+1;
	}
	else if(b>=7 && b<=11){
		z+=186+(b-7)*30+1;
	}
	else{
		z+=337;
	}
	k=((z%7)+4)%7;
	return k;
}
int sen(int a,int b,int c,int d,int e,int f){
	int k,p,m,x;
	k=d-a;
	p=e-b;
	if(p<0){
		k-=1;
		p=12-b+e;
	}
	m=f-c;
	if(m<0){
		p-=1;
		m=30-c+f;
	}
	x=taghvim(a,b);
	x=(c-1+x)%7;
	printf("%d %d %d\n", k,p,m);
	if(x==1){
		printf("shanbe");
	}
	if(x==2){
		printf("yekshanbe");
	}
	if(x==3){
		printf("doshanbe");
	}
	if(x==4){
		printf("seshanbe");
	}
	if(x==5){
		printf("chaharshanbe");
	}
	if(x==6){
		printf("panjshanbe");
	}
	if(x==7){
		printf("jome");
	}
	
	
}
int tedad(int a,int b,int c,int d,int e,int f){
	int x,y;
	x=rooz(d,e,f);
	y=rooz(a,b,c);
	return x-y;
}
int main(){
	printf("1: taghvim\n2: sen\n3: tabdilmiladi\n4: tabdilghamari");
	printf("\nEnter number:");
	int a,b,c,d,e,f,k,i;
	int x;
	int g=0;
	scanf("%d", &x);
	system("cls");
	if(x==1){
		scanf("%d", &a);
		scanf("%d", &b);
		if(b>12 || b<1){
			printf("It is wrong\n");
			scanf("%d", &b);
		}
		c=taghvim(a,b);
		printf("sh ye do se ch pa jo");
		printf("\n");
		for(i=0; i<7; i++){
			if(i<c-1){
				printf("%d ", g);
			}
			else{
				printf("%d ", i-c+2);
			}
		}
		printf("\n");
		for(i=0; i<7; i++){
			printf("%d ", 9-c+i);
		}
		printf("\n");
		for(i=0; i<7; i++){
			printf("%d ", 16-c+i);
		}
		printf("\n");
		for(i=0; i<7; i++){
			printf("%d ", 23-c+i);
		}
		printf("\n");
		if(b<=6){
			for(i=0; i<7; i++){
				if(30-c+i<=31){
					printf("%d ", 30-c+i);
				}
				else{
					printf("%d ", g);
				}
			}
		}
		else if(b<=11){
			for(i=0; i<7; i++){
				if(30-c+i<=30){
					printf("%d ", 30-c+i);
				}
				else{
					printf("%d ", g);
				}
			}
		}
		else{
			for(i=0; i<7; i++){
				if(30-c+i<=29){
					printf("%d ", 30-c+i);
				}
				else{
					printf("%d ", g);
				}
			}
		}
	}
	else if(x==2){
		printf("saletavallod\n");
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		printf("tarikhemrooz\n");
		scanf("%d", &d);
		scanf("%d", &e);
		scanf("%d", &f);
		sen(a,b,c,d,e,f);
		k=tedad(a,b,c,d,e,f);
		printf("\n%d", k);
	}
	else if(x==3){
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		tabdilmiladi(a,b,c);
	}
	else if(x==4){
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		tabdilghamari(a,b,c);
	}
	return 0;
}
#include<bits/stdc++.h>//��ʽ�� 
#include<windows.h>
#define RS 49
#define male 29
#define female 20
#define suiji 2139
using namespace std;
//int a[55];
int ansa[30][3];
bool b[55];
int tot=1;
int s;
int shuchu[30][3];
bool zt[30];						//���״̬ 
void jc();							//��� 
void sc(int x);						//��� 
void do_it(){						//���ͬ��λ����� 
	int k;
	for(int i=1;i<=25;i++){
		k=rand()%RS+s*739-23;
		k%=25;
		if(k==0){
			k=25;
		}
		while(zt[k]){
			k++;
			if(k==25+1){
				k-=25;
			}
		}
		shuchu[i][1]=ansa[k][1];
		shuchu[i][2]=ansa[k][2];
		zt[k]=true;
	}	
}
int main()									//������ 
{
	printf("\t\t����:\n");
	printf("��Ӧ�ó���ͬ��ǰ������Ӧ�ó���ʹ��c++��ctime���е�time����Ӧ��������ȡ���������\nԭ����\
��ʹ��time�趨����ʱ,��ǰ��ʱ����Сʱ���ݲ��Ҳ���С���޷��ﵽ�����Ч���������������ˡ�����ЧӦ����\n\
����΢С����ӻ����Ӷ��ﵽ�������������Ч��\n(PS:��Ҫ�˳�������ǿ��kill�������)\n(����ֻ��һ��������\
���أ���ʹǰ������һ�������������Ҳ�ǲ�һ������QWQ)\n\n");
	
	int k;
	int ans=0;
	int tot=0;
	while(1)  {
	printf("\n\n\n���������һ��10000���ڵ�����:"); 
	scanf("%d",&s);
	memset(ansa,0,sizeof(ansa));
	memset(b,0,sizeof(b));
	memset(shuchu,0,sizeof(shuchu));
	memset(zt,0,sizeof(zt));
	for(int i=1;i<=female;i++){				//Ů����� 
		if(tot==female){break;}
		k=rand()%RS+s*suiji-37;
		k%=female;
		k+=male;
		if(k==male){
			k=RS;
		}
		while(b[k]){
			k++;
			if(k==RS+1){
				k-=female;
			}
		}
		if(!b[k]){
		//cout<<k<<"\n";				//���� 
		ansa[i][2]=k;
		++tot;
		//printf("%d\n",k);				//���� 
		b[k]=true;
		}
	}
	k=rand()%2;
	if(k==0){k=2;}
	ansa[22][2]=23;
	k=rand()%2;
	if(k==0){k=2;}
	ansa[23][2]=14;
	ansa[25][1]=1;
	ansa[25][2]=0;
	b[14]=1;b[1]=1;b[0]=1;b[23]=1;tot+=3;
	//printf("\n\n\n");					 //���� 
	for(int i=1;i<=24;i++){				//������� 
		k=rand()%RS+s*suiji-254;
		k%=male;
		if(k==0){
			k=male;
		}
		while(b[k]){
			k++;
			if(k==male+1){
				k-=male;
			}
		}
		if(!b[k]){
		//cout<<k<<"\n";			//���� 
		tot++;
		ansa[i][1]=k;
		b[k]=true;
		}
	}
	
	//printf("\n\n\n");//���� 
	tot=0;
	int an[55];
	memset(an,0,sizeof(an));
	int len=0;
	for(int i=1;i<=49;i++){
		if(!b[i]){
			an[++len]=i;
			b[i]=true;
		}
	}
	//printf("len=%d\n",len);				//���� 
	for(int i=1;i<=24;i++){				//������λ����� 
		for(int j=1;j<=2;j++){
			if(!ansa[i][j]){
				ansa[i][j]=an[++tot];
				//printf("%d\n%d\n%d\n\n",i,j,ansa[i][j]); //���� 
			}
		}
	}
	jc();
	tot=0;
	do_it();
	for(int i=1;i<=6;i++){
		for(int j=1;j<=4;j++){
			tot++;
			for(int k_=1;k_<=2;k_++){
				//printf("%5d",shuchu[tot][k]);
				//printf("%5d",shuchu[tot][k]);
				if(k_==1&&j!=1)printf("\t\t");
				if(j==1)printf(" ");
				sc(shuchu[tot][k_]);
				if(k_==1)printf("-");
				//if(k_==2)printf(" ");
			}
		}
		printf("\n");
	}
	//printf("%5d%5d",shuchu[25][1],shuchu[25][2]);
	for(int k_=1;k_<=2;k_++){
				//printf("%5d",shuchu[tot][k]);
				//printf("%5d",shuchu[tot][k]);
				if(k_==1)printf(" ");
				sc(shuchu[25][k_]);
				if(k_==1)printf("-");
				if(k_==2)printf("   ");
			}
	//tot++;
	/*for(int i=1;i<=RS;i++){
		if(!b[i]){
			printf("%d\n",i);
		}*/
	}
	return 0;
}
void sc(int x){
	switch (x){
		case 0:printf("����");break;
		case 1:printf("������");break;
		case 2:printf("������");break;
		case 3:printf("�����");break;
		case 4:printf("������");break;
		case 5:printf("������");break;
		case 6:printf("������");break;
		case 7:printf("������");break;
		case 8:printf("����Ȼ");break;
		case 9:printf("���");break;
		case 10:printf("������");break;
		case 11:printf("������");break;
		case 12:printf("������");break;
		case 13:printf("��Խ");break;
		case 14:printf("�︣��");break;
		case 15:printf("������");break;
		case 16:printf("������");break;
		case 17:printf("Ф׿");break;
		case 18:printf("������");break;
		case 19:printf("�����");break;
		case 20:printf("�ż���");break;
		case 21:printf("����ΰ");break;
		case 22:printf("�ź���");break;
		case 23:printf("֣����");break;
		case 24:printf("����");break;
		case 25:printf("������");break;
		case 26:printf("������");break;
		case 27:printf("����");break;
		case 28:printf("������");break;
		case 29:printf("�ض�");break;
		case 30:printf("��ʤ��");break;
		case 31:printf("��˫˫");break;
		case 32:printf("����ɺ");break;
		case 33:printf("������");break;
		case 34:printf("������");break;
		case 35:printf("��˼��");break;
		case 36:printf("������");break;
		case 37:printf("������");break;
		case 38:printf("��һŵ");break;
		case 39:printf("�����");break;
		case 40:printf("�����");break;
		case 41:printf("����ͬ");break;
		case 42:printf("������");break;
		case 43:printf("���ܰ");break;
		case 44:printf("�����");break;
		case 45:printf("�쾴��");break;
		case 46:printf("�����");break;
		case 47:printf("������");break;
		case 48:printf("���");break;
		case 49:printf("������");break;
	}	
}
void jc(){
	bool yes=false;
 	for(int i=1;i<=24;i++){
 		for(int j=1;j<=2;j++){
 			if(ansa[i][j]==12){
 				if(i>20){
 					swap(ansa[10][1],ansa[i][j]);
 				}
 				yes=true;
 				break;
			 }
 			
 		}
 		if(yes) break;
 	}
 	return ;
 }

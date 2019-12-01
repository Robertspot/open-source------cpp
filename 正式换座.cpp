#include<bits/stdc++.h>//正式版 
//#include<windows.h>
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
bool zt[30];						//输出状态 
void jc();							//检查 
void sc(int x);						//输出 
void do_it(){						//最后同桌位置随机 
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
int main()									//主函数 
{
	printf("\t\t介绍:\n");
	printf("本应用程序不同于前代其他应用程序，使用c++中ctime库中的time（）应用种子来取得随机数。\n原因是\
当使用time设定种子时,当前后时间差过小时数据差别也会过小，无法达到随机的效果。本程序运用了“蝴蝶效应”，\n\
即将微小差别复杂化，从而达到整个数据随机的效果\n(PS:如要退出程序请强行kill这个程序)\n(数字只是一个启动的\
开关，即使前后输入一样的两个数结果也是不一样的哇QWQ)\n\n");
	
	int k;
	int ans=0;
	int tot=0;
	while(1)  {
	printf("\n\n\n请随机输入一个10000以内的数字:"); 
	scanf("%d",&s);
	memset(ansa,0,sizeof(ansa));
	memset(b,0,sizeof(b));
	memset(shuchu,0,sizeof(shuchu));
	memset(zt,0,sizeof(zt));
	for(int i=1;i<=female;i++){				//女生随机 
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
		//cout<<k<<"\n";				//调试 
		ansa[i][2]=k;
		++tot;
		//printf("%d\n",k);				//调试 
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
	//printf("\n\n\n");					 //调试 
	for(int i=1;i<=24;i++){				//男生随机 
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
		//cout<<k<<"\n";			//调试 
		tot++;
		ansa[i][1]=k;
		b[k]=true;
		}
	}
	
	//printf("\n\n\n");//调试 
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
	//printf("len=%d\n",len);				//调试 
	for(int i=1;i<=24;i++){				//检查空座位并填充 
		for(int j=1;j<=2;j++){
			if(!ansa[i][j]){
				ansa[i][j]=an[++tot];
				//printf("%d\n%d\n%d\n\n",i,j,ansa[i][j]); //调试 
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
		case 0:printf("空座");break;
		case 1:printf("弓汉羽");break;
		case 2:printf("王江涵");break;
		case 3:printf("王声宸");break;
		case 4:printf("王俊达");break;
		case 5:printf("王浩林");break;
		case 6:printf("王梓安");break;
		case 7:printf("王梓亦");break;
		case 8:printf("王鹏然");break;
		case 9:printf("王睿");break;
		case 10:printf("刘田攸");break;
		case 11:printf("刘传琦");break;
		case 12:printf("孙林轩");break;
		case 13:printf("吕越");break;
		case 14:printf("孙福泽");break;
		case 15:printf("张力洋");break;
		case 16:printf("宋亦来");break;
		case 17:printf("肖卓");break;
		case 18:printf("陈泓嘉");break;
		case 19:printf("吴佳儒");break;
		case 20:printf("张家明");break;
		case 21:printf("张霆伟");break;
		case 22:printf("张赫禹");break;
		case 23:printf("郑云骜");break;
		case 24:printf("林瑞涵");break;
		case 25:printf("赵万鸣");break;
		case 26:printf("赵明泽");break;
		case 27:printf("姜哲");break;
		case 28:printf("郝瑞升");break;
		case 29:printf("秦栋");break;
		case 30:printf("栾胜臣");break;

		case 31:printf("王双双");break;
		case 32:printf("王齐珊");break;
		case 33:printf("吕佳欣");break;
		case 34:printf("刘佳瑞");break;
		case 35:printf("刘思仪");break;
		case 36:printf("孙柳怡");break;
		case 37:printf("孙星移");break;
		case 38:printf("陈一诺");break;
		case 39:printf("李佳宁");break;
		case 40:printf("李雨姝");break;
		case 41:printf("张梓同");break;
		case 42:printf("张渠清");break;
		case 43:printf("洪睿馨");break;
		case 44:printf("唐铭璐");break;
		case 45:printf("徐敬文");break;
		case 46:printf("栾慧妍");break;
		case 47:printf("董雨萌");break;
		case 48:printf("董睿");break;
		case 49:printf("裘艺欣");break;
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

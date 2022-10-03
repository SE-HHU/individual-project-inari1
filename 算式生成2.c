#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
int getnumber()
{
return rand()%100;//产生随机数 
}
 
int getop()
{
return rand()%2 ;//产生随机符号 
} 
 
void getresult(int *num1,int *num2 ,int *op ,int *result)//生成答案的函数 
{
int k,n;
int count=0; 
printf("请再次输入生成算式的数量，来得到答案");
scanf("%d",&n); 
for(k=0;k<n;k++)
	{count++;
	FILE *fp = fopen("Answers.txt","a+");
        if(op[k]==1)
		{// 加法
		result[k]=num1[k]+num2[k];
			if(result[k]>150){
			                  num1[k]-=50;num2[k]-=50;
			                  result[k]=num1[k]+num2[k];
							 }
			if(result[k]>100){
			                  if (num1[k]>num2[k]){num1[k]-=50;}
			                  else{num2[k]-=50;}
			                  result[k]=num1[k]+num2[k];
							 }
	        if(NULL == fp){printf("open failed");}
	        fprintf(fp,"%d.答案%d:%d + %d = %d\t",k+1,k+1,num1[k],num2[k],result[k]);
	        if (count%4==0){fprintf(fp,"\n");}
	        printf("答案%d:%d + %d = %d\n",k+1,num1[k],num2[k],result[k]);
	    }
		else
		{ // 减法
            if(num1[k]>=num2[k])     
			{result[k]=num1[k]-num2[k];
			    if(NULL == fp)
	            {printf("open failed");}
	            fprintf(fp,"%d.答案%d:%d - %d = %d\t",k+1,k+1,num1[k],num2[k],result[k]);
	            if (count%4==0){fprintf(fp,"\n");}
	            printf("答案%d:%d - %d = %d\n",k+1,num1[k],num2[k],result[k]);
            } 
			else
			{result[k]=num2[k]-num1[k]; 
                if(NULL == fp)
	            {printf("open failed");}
	            fprintf(fp,"%d.答案%d:%d - %d = %d\t",k+1,k+1,num2[k],num1[k],result[k]);
	            if (count%4==0){fprintf(fp,"\n");}
	            printf("答案%d:%d - %d = %d\n",k+1,num2[k],num1[k],result[k]);
	            
            } 
        }fclose(fp);
   } 
} 
int main()
{
int i,n;
int count=0; 
printf("请输入生成算式的数量：");
scanf("%d",&n);
int num1[n],num2[n],op[n],result[n];// 产生两个操作数，符号，结果 
    for(i=0 ;i<n;i++)
	{//产生随机数 符号
        num1[i]=getnumber();
        num2[i]=getnumber();
        op[i]=getop();
    }
    /*下面将所有随机算式给出*/ 
int j; 
    for(j=0 ;j<n ;j++ )
    {count++;
	FILE *fp = fopen("Exercises.txt","a+");//先获取操作符，如果是+  不排大小，是减，再排大小
        if(op[j]==1)
		{//加法
		if(num1[j]+num2[j]>150)
		                   {
		                    num1[j]-=50;num2[j]-=50;
						   }
		if(num1[j]+num2[j]>100)
		                   {
		                    if (num1[j]>num2[j]){num1[j]-=50;}
			                else{num2[j]-=50;}
						   }
		if(NULL == fp){printf("open failed");}
	    fprintf(fp,"%d.四则运算题目%d:%d + %d = \t",j+1,j+1,num1[j],num2[j]);
	    if (count%4==0){fprintf(fp,"\n");}
	    printf("四则运算题目%d:%d + %d =\n",j+1,num1[j],num2[j]);
        }
		else
		{//减法
		    if(num1[j] >= num2[j] )
			{//num1 大于 num2
			if(NULL == fp){printf("open failed");}
	        fprintf(fp,"%d.四则运算题目%d:%d - %d = \t",j+1,j+1,num1[j],num2[j]);
	        if (count%4==0){fprintf(fp,"\n");}
            printf("四则运算题目%d:%d - %d =\n",j+1,num1[j],num2[j]);
            } 
			else
			{//num1 小于 num2 
			if(NULL == fp){printf("open failed");}
	        fprintf(fp,"%d.四则运算题目%d:%d - %d = \t",j+1,j+1,num2[j],num1[j]);
	        if (count%4==0){fprintf(fp,"\n");}
            printf("四则运算题目%d:%d - %d =\n",j+1,num2[j],num1[j]);
            }
        }fclose(fp);
    }
getresult(num1,num2,op,result);//输出所有算式的答案 
system("pause");
return 0;
} 

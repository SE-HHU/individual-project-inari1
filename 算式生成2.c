#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
int getnumber()
{
return rand()%100;//��������� 
}
 
int getop()
{
return rand()%2 ;//����������� 
} 
 
void getresult(int *num1,int *num2 ,int *op ,int *result)//���ɴ𰸵ĺ��� 
{
int k,n;
int count=0; 
printf("���ٴ�����������ʽ�����������õ���");
scanf("%d",&n); 
for(k=0;k<n;k++)
	{count++;
	FILE *fp = fopen("Answers.txt","a+");
        if(op[k]==1)
		{// �ӷ�
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
	        fprintf(fp,"%d.��%d:%d + %d = %d\t",k+1,k+1,num1[k],num2[k],result[k]);
	        if (count%4==0){fprintf(fp,"\n");}
	        printf("��%d:%d + %d = %d\n",k+1,num1[k],num2[k],result[k]);
	    }
		else
		{ // ����
            if(num1[k]>=num2[k])     
			{result[k]=num1[k]-num2[k];
			    if(NULL == fp)
	            {printf("open failed");}
	            fprintf(fp,"%d.��%d:%d - %d = %d\t",k+1,k+1,num1[k],num2[k],result[k]);
	            if (count%4==0){fprintf(fp,"\n");}
	            printf("��%d:%d - %d = %d\n",k+1,num1[k],num2[k],result[k]);
            } 
			else
			{result[k]=num2[k]-num1[k]; 
                if(NULL == fp)
	            {printf("open failed");}
	            fprintf(fp,"%d.��%d:%d - %d = %d\t",k+1,k+1,num2[k],num1[k],result[k]);
	            if (count%4==0){fprintf(fp,"\n");}
	            printf("��%d:%d - %d = %d\n",k+1,num2[k],num1[k],result[k]);
	            
            } 
        }fclose(fp);
   } 
} 
int main()
{
int i,n;
int count=0; 
printf("������������ʽ��������");
scanf("%d",&n);
int num1[n],num2[n],op[n],result[n];// �������������������ţ���� 
    for(i=0 ;i<n;i++)
	{//��������� ����
        num1[i]=getnumber();
        num2[i]=getnumber();
        op[i]=getop();
    }
    /*���潫���������ʽ����*/ 
int j; 
    for(j=0 ;j<n ;j++ )
    {count++;
	FILE *fp = fopen("Exercises.txt","a+");//�Ȼ�ȡ�������������+  ���Ŵ�С���Ǽ������Ŵ�С
        if(op[j]==1)
		{//�ӷ�
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
	    fprintf(fp,"%d.����������Ŀ%d:%d + %d = \t",j+1,j+1,num1[j],num2[j]);
	    if (count%4==0){fprintf(fp,"\n");}
	    printf("����������Ŀ%d:%d + %d =\n",j+1,num1[j],num2[j]);
        }
		else
		{//����
		    if(num1[j] >= num2[j] )
			{//num1 ���� num2
			if(NULL == fp){printf("open failed");}
	        fprintf(fp,"%d.����������Ŀ%d:%d - %d = \t",j+1,j+1,num1[j],num2[j]);
	        if (count%4==0){fprintf(fp,"\n");}
            printf("����������Ŀ%d:%d - %d =\n",j+1,num1[j],num2[j]);
            } 
			else
			{//num1 С�� num2 
			if(NULL == fp){printf("open failed");}
	        fprintf(fp,"%d.����������Ŀ%d:%d - %d = \t",j+1,j+1,num2[j],num1[j]);
	        if (count%4==0){fprintf(fp,"\n");}
            printf("����������Ŀ%d:%d - %d =\n",j+1,num2[j],num1[j]);
            }
        }fclose(fp);
    }
getresult(num1,num2,op,result);//���������ʽ�Ĵ� 
system("pause");
return 0;
} 

#include<stdio.h>
#include<string.h>
int main(){
    char ch[8]="Forouzan";
    int n=strlen(ch);
    printf("lENGTH: %d", n);
    printf("\n\n--------- SENDERS SITE ----------\n");
    int sum[4];
    for(int i=0;i<n;i=i+2)
    {
        int n1=ch[i];
        int n2=ch[i+1];
       
        int q1=n1/16;
        int q2=n2/16;
        int r1=n1%16;
        int r2=n2%16;
        sum[0]+=q1;
        sum[1]+=r1;
        sum[2]+=q2;
        sum[3]+=r2;
        printf("\n%x %x %x %x",q1,r1,q2,r2);
    }
       
    for(int i=3;i>=0;i--)
    {
        int q=sum[i]/16;
        int r=sum[i]%16;
       
        if(i>0) sum[i-1]+=q;
        else sum[3]+=q;
        sum[i]=r;
    }
    printf("\n----------------------------");
        printf("\n%x %x %x %x",sum[0],sum[1],sum[2],sum[3]);
   
    for(int i=3;i>=0;i--)
        sum[i]=15-sum[i];
    printf("\n----------------------------");
    printf("\nCompliment: %x %x %x %x",sum[0],sum[1],sum[2],sum[3]);
   
            printf("\n\n--------- RECEIVERS SITE ----------\n");


        int sum2[4];
    for(int i=0;i<n;i=i+2)
    {
        int n1=ch[i];
        int n2=ch[i+1];
       
        int q1=n1/16;
        int q2=n2/16;
        int r1=n1%16;
        int r2=n2%16;
        sum2[0]+=q1;
        sum2[1]+=r1;
        sum2[2]+=q2;
        sum2[3]+=r2;
        printf("\n%x %x %x %x",q1,r1,q2,r2);
    }
    sum2[0]+=sum[0];
    sum2[1]+=sum[1];
    sum2[2]+=sum[2];
    sum2[3]+=sum[3];
       


       
    for(int i=3;i>=0;i--)
    {
        int q=sum2[i]/16;
        int r=sum2[i]%16;
       
        if(i>0) sum2[i-1]+=q;
        else sum2[3]+=q;
        sum2[i]=r;
    }
    printf("\n----------------------------");
    printf("\n%x %x %x %x",sum2[0],sum2[1],sum2[2],sum2[3]);
    for(int i=3;i>=0;i--)
        sum2[i]=15-sum2[i];
    printf("\n----------------------------");
    printf("\nComp at receiver site: %x %x %x %x",sum2[0],sum2[1],sum2[2],sum2[3]);
    if(sum2[2]==0 && sum2[1]==0 && sum2[0]==0 && sum2[3]==0){
        printf("\nError free");
    }
    else {
        printf("\nError detected");
    }
}



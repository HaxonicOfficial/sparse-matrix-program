#include<stdio.h>
void main()
{
int a[50][50],b[50][50],i,j,count=0,m,n,k;

printf("\nenter the size of the matrix(A) in the form mxn:\n");
scanf("%d%d",&m,&n);

printf("\nenter the elements of the martrix(A):\n");
for(i=0;i<m;i++)
{for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]!=0)
count++;
}
}

if(count<((m*n)/2))
printf("\nGiven matrix is sparse matrix!!!\n");
else
printf("\nnot a sparse matrix\n");
if((count+1)*3>m*n)
printf("\nsparse matrix takes more memory (%dbytes) then the matrix A %dbytes\n",(count+1)*6,m*n*2);
else if((count+1)*3<m*n)
printf("\nsparse matrix takes less memory (%dbytes) then the matrix A %dbytes\n",(count+1)*6,m*n*2);
else
printf("\nsparse matrix takes same memory %dbytes as the matrix A %dbytes\n",(count+1)*6,m*n*2);

b[0][0]=m;
b[0][1]=n;
b[0][2]=count;
k=1;
for(i=1;i<((count)+1);i++)
{
for(j=0;j<n;j++)
{
if(a[i-1][j]!=0)
{	
	
	b[k][0]=i-1;
	
	b[k][1]=j;
	
	b[k][2]=a[i-1][j];
	k++;
}
}
}

printf("\nthe sparse matrix is:\n");
for(i=0;i<(count+1);i++)
{
for(j=0;j<3;j++)
{

printf("%d\t",b[i][j]);
}printf("\n");
}

}

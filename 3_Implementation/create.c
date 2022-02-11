#include<billing_system.h>
void create()
{
	int i=0;
	FILE *fp;
	fp=fopen("Records.txt","w");
	if(fp==NULL)
	{
		printf("Error\n");
	}
	printf("\t");
	printf("Enter the Number of Records:");
	scanf("%d",&n);
	printf("\n");
	FILE *fpq;
	fpq=fopen("Quantity.txt","w");
	fprintf(fp,"productnumber\t,ProductName\t, Quantity\n, Price\t");
	fprintf(fpq,"%d",n);
	fclose(fpq);
	while(i<n)
	{
	    printf("\t");
		printf("Enter Product Code:");
		scanf("%d",&item.productnumber);
		printf("\t");
		printf("Enter Product Name:");
		scanf("%s",item.productname);
		printf("\t");
		printf("Enter Quantity:");
		scanf("%d",&item.quantity);
		printf("\t");
		printf("Enter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
		fprintf(fp,"%d\t%s\t%d\t%d\t",item.productnumber,item.productname,item.quantity,item.price);
	}
	fclose(fp);
	printf("\t");
	printf("Records are Created");
	printf("\n");
	printf("\n");
}
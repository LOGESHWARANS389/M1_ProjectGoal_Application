#include<billing_system.h>
void display()
{
	int nk=0;
	FILE *fp;
	fp=fopen("Records.txt","r");
	if(feof(fp))
	{
		printf("Error in Opening Files\n");
	}
	printf("\t");
	printf("==============================================================\n");
	printf("\t");
	printf("|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
	printf("\t");
	printf("==============================================================\n");
	while(nk!=n)
	{
		nk++;
		fscanf(fp,"%d",&item.productnumber);
		if(item.productnumber==0)
		{
		    printf("\t");
			printf("There are no items in Cart");
			printf("\n");
			break;
		}
		fscanf(fp,"%s",item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",item.productnumber,item.productname,item.quantity,item.price);
	}
	fclose(fp);
}
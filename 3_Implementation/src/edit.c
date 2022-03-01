#include <Billing_System.h>

void edit()
{
	FILE *fp;
	FILE *fptr;
	FILE *fpk;
	int h;
	int found=0;
	int ka=0;
	int p;
	fp=fopen("Records.txt","r");
	fptr=fopen("temp1.txt","w");
	fpk=fopen("temp2.txt","w");
	printf("\t");
	printf("Enter the Product Number to Delete: ");
	scanf("%d",&h);
	printf("\n");
	p=n;
	while(!(ka==p))
	{
		ka++;
		fscanf(fp,"%d",&item.productnumber);
		if(item.productnumber==h)
		{
			found=1;
			fscanf(fp,"%10s",&item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			n--;
			printf("\tProduct has been Successfully Deleted\n");
		}
		else
		{
			fscanf(fp,"%10s",&item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",item.productnumber,item.productname,item.quantity,item.price);
		}
	}
	fprintf(fpk,"%d",n);
	fclose(fpk);
	fclose(fptr);
	fclose(fp);
	if(found==0)
	{
		printf("\tProduct no Found\n\n");
	}
	remove("Quantity.txt");
	rename("temp2.txt","Quantity.txt");
	remove("Records.txt");
	rename("temp1.txt","Records.txt");
}

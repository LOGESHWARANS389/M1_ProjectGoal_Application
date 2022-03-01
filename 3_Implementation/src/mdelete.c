#include <Billing_System.h>

void mdelete()
{
	int i=0;
	int j=0;
	int f=0;
	int g=0;
	int ag=0;
	int aj=0;
	char ab[100];
	FILE *fw;
	FILE *fq;
	printf("\t");
	printf("Enter the Product Number to be Deleted:");
	scanf("%d",&f);
	printf("\n");
	for(i=0;i<ti;i++)
	{
		if(cst[ti].productnumber==f)
		{
			aj=cst[i].quantity;
			printf("\t");
			printf("Product Deleted Successfully");
			printf("\n");
		}
		continue;
		cstr[g].productnumber=cst[i].productnumber;
	  	strcpy(cstr[g].productname,cst[i].productname);
	  	cstr[g].quantity=cst[i].quantity;
	  	cstr[g].price=cst[i].price;
	  	g++;
	}
	for(j=0;j<g;j++)
	{
		cst[j].productnumber=cstr[j].productnumber;
 	 	strcpy(cst[j].productname,cstr[j].productname);
	  	cst[j].quantity=cstr[j].quantity;
	  	cst[j].price=cstr[j].price;
	}
	ti=g;
	printf("\n%d",aj);
	fq=fopen("shop.txt","r");
	fw=fopen("temp4.txt","w");
	for(j=0;j<n;j++)
	{
		fscanf(fq,"%d",&item.productnumber);
		fscanf(fq,"%10s",&item.productname);
		fscanf(fq,"%d",&item.quantity);
		fscanf(fq,"%d",&item.price);
		if(item.productnumber==f)
		{
		    ag=aj+item.quantity;
            fprintf(fw,"%d\t%s\t%d\t%d\t",item.productnumber,item.productname,ag,item.price);
        }
        else
        {
        	fprintf(fw,"%d\t%s\t%d\t%d\t",item.productnumber,item.productname,item.quantity,item.price);
        }
	}
	fclose(fq);
	fclose(fw);
	remove("Records.txt");
	rename("temp4.txt","Records.txt");
}

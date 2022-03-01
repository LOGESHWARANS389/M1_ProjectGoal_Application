#include <Billing_System.h>

void bill()
{
	int na=0;  
	int a=0;	
	int cont=0;
	int k=0;
	int r=0;
	int w=0;
	int ch=0;
	int l=0;	
	int bi=0;
	int ln=0;
   
	printf("\t");
	printf("Enter the Product Number:");
	scanf("%d",&na);
	printf("\n");
	FILE *fp;
	fp=fopen("Records.txt","w");
	FILE *fptr;
	fptr=fopen("temp.txt","w");
	while(!(feof(fp)))
	{
		l++;
		fscanf(fp,"%d",&item.productnumber);
		fscanf(fp,"%10s",&item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		if(item.productnumber == na)
		{
			ln++;
			if(ln==2)
			break;
			printf("\tEnter the Quantity:");
			scanf("%d",&a);
			if(a <= item.quantity)
			{
				cst[ti].productnumber=item.productnumber;
				strcpy(cst[ti].productname,item.productname);
				cst[ti].quantity=a;
				cst[ti].price=item.price;
				item.quantity=item.quantity-a;
				ti++;
				//goto l1;
			}
			else
			{
				printf("\n\tSorry Out of Stock\n");
				bi++;
				//goto l1;
			}
		}
		else
		{
			cont++;
			fprintf(fptr,"%d\t",item.productnumber);
			fprintf(fptr,"%s\t",item.productname);
			fprintf(fptr,"%d\t",item.quantity);
			fprintf(fptr,"%d\t",item.price);
			continue;
		}
		fprintf(fptr,"%d\t",item.productnumber);
		fprintf(fptr,"%s\t",item.productname);
		fprintf(fptr,"%d\t",item.quantity);
		fprintf(fptr,"%d\t",item.price);
	}
	if(l==cont)
	printf("Error:Choose Properly\n");
	fclose(fptr);
	fclose(fp);
	remove("Records.txt");
	rename("temp.txt","Records.txt");
	ln=0;
	printf("\tDo you Want to Shop More!\n\tPress 1 for More\n\tPress 2 to Exit\n\t");
	scanf("%d",&k);
	if(k==1)
	goto l3;
}

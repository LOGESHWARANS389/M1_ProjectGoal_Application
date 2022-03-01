#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct item
{
	int productnumber;
	char productname[10];
	int quantity;
	int price;
}
item;
struct customer
{
	int productnumber;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cst[100];
struct temporary
{
	int productnumber;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cstr[100];
int t=0;
int n=0; 
int k=0;
int ba=0;
int ti=0;
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
		scanf("%10s",&item.productname);
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
		fscanf(fp,"%10s",&item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",item.productnumber,item.productname,item.quantity,item.price);
	}
	fclose(fp);
}
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
void invoice()
{
	int j;
	int o;
	float gt=0;
	if(ti==0)
	{
		printf("There are No Products in your Cart\n");
	}
	printf("\n\n                            INVOICE\n\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=((cst[o].price)*(cst[o].quantity));
		gt=gt+cst[o].amount;
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].productnumber,cst[j].productname,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount Payable:%f\n",gt);
	printf("Thank you for Shopping\n");
	printf("Visit Again\n");
}
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
void mdisplay()
{
	int i;
	int j;
	int o;
	printf("================================================================================\n");
	printf("product number\t|product name\t|quantity\t|price\t\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		printf("%14d\t|%12s\t|%6d\t|%6d\n",cst[o].productnumber,cst[o].productname,cst[o].quantity,cst[o].price);
	}
}

int main()
{
	char ch,password[10],q[10]="progto";
	int s=0;
	int y=0;
	int w=1;
	int i;
	FILE *fpe;
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\n");
	printf("************************************************************************************************************************\n");
	printf("*****************************************    WELCOME TO RETAIL STORE     ***********************************************\n");
	printf("\t                            GET A WELCOME BONUS ON YOUR FIRST PURCHASE \n\n");
	printf("\t\t\t       Kindly note that the Goods once sold are not returnable\n\t\t\t\t\t");
    printf("      Reference Number: %d\n",n);
    q: printf("\n\t");
    printf("****************************\n\t");
    printf("Select an Option: \n\t");
    printf("****************************\n\t");
	printf("1. ADMINISTRATOR\n\t");
	printf("2. CUSTOMER\n\t");
	printf("3. EXIT\n\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s)
	{
	          case 1:
               printf("\t____________________________\n");
			   printf("\n\tPlease Select an Option: \n\t");
               printf("____________________________\n");
		       printf("\n\t1.CREATE\n\t");
		       printf("2.DELETE/MODIFY\n\t");
		       printf("3.DISPLAY\n\t");
		       printf("4.MAIN MENU\n\n\t");
		       printf("Please Enter an Option: ");
		        scanf("%d",&y);
		        switch(y)
		        {
        		case 1:create();
        			      goto q;
  			    case 2:edit();
  			             goto q;
                case 3:display();
                         goto q;
                case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;
       case 2: printf("\n");
               printf("\t");
               printf("____________________________\n\n\t");
               printf("Select an Option: \n\t");
               printf("____________________________\n\n\t");
               printf("1.BILL\n\t");
               printf("2.INVOICE\n\t");
               printf("3.DISPLAY\n\t");
               printf("4.MYCART\n\t");
               printf("5.MAIN MENU\n\t");
               printf("6.DELETE ITEMS IN CART\n\n\t");
               printf("Please Enter an Option: ");
               scanf("%d",&y);
               printf("\n");
               switch(y)
		        {
                    case 1 : bill();
        			         goto q;
                    case 2 : invoice();
                             goto q;
                    case 3 : display();
                             goto q;
                    case 4 : mdisplay();
                             goto q;
                    case 5 : goto q;
                    case 6 : mdelete();
                             goto q;
                    default : printf("Error\n");
                              goto q;
        		}
		         break;
      case 3: printf("\tExiting...\n");
      break;
      default : printf("error\n");
      break;
	}
}

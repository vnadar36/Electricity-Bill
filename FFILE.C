#include<stdio.h>
#include<conio.h>
struct elec
{
   int cust_no, unit_con;
   float charge,gst,amt;
   float total_amt;
   char nam[25],add[25];
   float mno;
   int d,m,y,nd,nm,ny,ndays;
};

int month [12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void main()
{
   struct elec e;
   FILE *p,*q;
   clrscr();
   textcolor(BLACK);
   textbackground(15);
   printf("enter the customer IDNO :\t");
   scanf("%d",&e.cust_no);
   printf("\nenter the customer Name :\t");
   scanf("%s",e.nam);
   printf("\nenter the address :\t");
   scanf("%s",&e.add);
   printf("\nenter std number :\t");
   scanf("%f",&e.mno);
   printf("\nenter the unit consumed by customer  :\t");
   scanf("%d",&e.unit_con);
   printf("\n enter the date,month,year \n");
   scanf("%d%d%d",&e.d,&e.m,&e.y);

   if (e.unit_con <30 )
   {
e.charge = 0.40;
}
   else if (e.unit_con>=30 && e.unit_con<100)
   {
e.charge = 1.60;
}
else if (e.unit_con>=100 && e.unit_con<300)
{
e.charge = 3.60;
}
else if (e.unit_con>=300)
{
e.charge = 5.75;
}
  e.amt = e.unit_con*e.charge;
   if (e.amt>=300)
   {
e.gst= e.amt*5/100;
}
   e.total_amt = e.amt+e.gst;
   if (e.total_amt  < 25)
   {
e.total_amt =25;
}
   clrscr();
   e.ndays= month [e.m-1];
if(e.m==2)
{
if(e.y%100==0)
{
if(e.y%400==0)
e.ndays=29;
}
else
if(e.y%4==0)
e.ndays=29;
}
e.nd=e.nd+1;
e.nm=e.m;
e.ny=e.y;
if(e.nd>e.ndays)
{
e.nd=1;
e.nm++;
}
if(e.nm>12)
{
e.nm=1;
e.ny++;
}

   p = fopen("one.txt","w");
   fprintf(p,"%d %s %s %f %d %d %d %d", e.cust_no, e.nam, e.add, e.mno, e.unit_con, e.d, e.nm, e.ny);
   fclose(p);

      q = fopen("one.txt","r");
      fscanf(q,"%d %s %s %f %d %d %d %d", e.cust_no, e.nam, e.add, e.mno, e.unit_con, e.d, e.nm, e.ny);
      printf("\t\t\tElectricity Bill\n\n");
   printf("Customer IDNO                         :\t%d",e.cust_no);
   printf("\nCustomer Name                       :\t%s",e.nam);
   printf("\nCustomer Address                    :\t%s",e.add);
   printf("\nContact                             :\t%f",e.mno);
   printf("\nUnit Consumed                       :\t%d",e.unit_con);
   printf("\nAmount Charges @Rs- %2.f  per unit    :\t%f",e.charge,e.amt);
   printf("\nGST Amount                          :\t%f",e.gst);
   printf("\nNet Amount Paid By the Customer     :\t%f",e.total_amt);
   printf("\nLast date of payment                :\t%d/%d/%d",e.d,e.nm,e.ny);

      //printf("%d %s %s %f %d %d %d %d", e.cust_no, e.nam, e.add, e.mno, e.unit_con, e.d, e.nm, e.ny);
//while( !feof(q) );
   fclose(q);
   getch();
}
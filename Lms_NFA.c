#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

/*///////////////////////////////////////////////////////////////////login System Variable Start //////////////////////////////////////////////////////*/
struct login{
    char first_name[20];
    char last_name[20];
    char username[20];
    char password[20];
};

struct alogin{
    char afirst_name[20];
    char alast_name[20];
    char ausername[20];
    char apassword[20];
    int admin_id;
    char email [20];

};

struct book
{

    long id;

    char name[20],author[20],subject[20] ;
    //int intake;

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;
struct messa
{
    char mes[20];
    char rmes[20];
}li,lr;

struct payment
{
    char pass [20],add[20],AN[50], email[50],name[20],bname[50];
    long ph,cvc,valid,phone,qt,price,tprice;

}pay;
/*/////////////////////////////////////////////////////////////////// login System Variable End //////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////login System Function///////////////////////////////////////////////////////////*/


  /************************registe********/
registe (){
    FILE *log;
    log=fopen("login/login_info.dll","w");
    struct login l;
    printf("\n\n\n\t\t\t **************** Enter your information **************** \n");
        fflush(stdin);
        printf("\t\t\t..::Enter Your First Name:\n\t\t\t");
        gets(l.first_name);
        fflush(stdin);
        printf("\t\t\t..::Enter Your last_name:\n\t\t\t");
        gets(l.last_name);
        fflush(stdin);
        printf("\t\t\t..::Enter Your username:\n\t\t\t");
        gets(l.username);
        fflush(stdin);
        printf("\t\t\t..::Enter Your password:\n\t\t\t");
        gets(l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\n \t\t*****Registration Successful***** \t\t\nNow login with your username and password : ");
    printf("\t\t\n\n press any key to continue....... ");
    getch();
    system("CLS");
    login();
}
login(){
    char username [20],password[20];
    FILE *log;
    log =fopen("login/login_info.dll","r");
    struct login l;
    printf("\n\n\n\t\t\t ****************Enter your Username & Password*************");
    printf("\n\n\t\t\tUsername:");
    scanf("%s",&username);
    printf("\n\n\t\t\tPassword:");
    scanf("%s",&password);

     while(fread(&l,sizeof(l),1,log)){
        if (strcmp(username,l.username)==0 && strcmp (password,l.password)==0)
            {
             printf("\n\n\n\t\t\t\t **************** Successful Login ****************\n");
             printf("\t\t\t\t\t****** *** ***** ***** ***** **** ****** \n\n");
             printf("\t\t\t\t****** **** Enter What you Want **** ****** \n\n");
             printf("\t\t\t1. USER Dashboard\n");
             int ch;
             printf("\n\t\t\tEnter Your Choice: ");
             scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                    USER_Dashboard();
                    break;

                default:
                    printf("\t\t\tWrong Input\n");
                }


                }

                else{
                  printf("\t\t\tPlease Enter Correct UserID And Password\n");
                   break;
                }
     }
     fclose(log);
}



/************************************************************Admin Login *****************************************************/

aregiste (){
    FILE *log;
    log=fopen("login/A_login_info.dll","w");
    struct alogin l;
    printf("\n\n\n\t\t\t **************** Enter your information **************** \n");
    fflush(stdin);
    printf("\t\t\t..::Enter Your First Name:\n\t\t\t");
    gets(l.afirst_name);
    fflush(stdin);
    printf("\t\t\t..::Enter Your last_name:\n\t\t\t");
    gets(l.alast_name);
    fflush(stdin);
    printf("\t\t\t..::Enter Your username:\n\t\t\t");
    gets(l.ausername);
    fflush(stdin);
    printf("\t\t\t..::Enter Your password:\n\t\t\t");
    gets(l.apassword);
    printf("\t\t\t..::Enter Your Admin Id");
    scanf("%d",&l.admin_id);
    fflush(stdin);
    printf("\t\t\t..::Enter Your Email:\n\t\t\t");
    gets(l.email);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\n\n Congratulations! You have successfully completed the registration.\n");
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\n Please Note:An e-mail has been sent to your e-mail. Please verify your e-mail.");
    printf("\nWe will check all your data and if all the information is correct then we will \nsend you another mail and there you will be \ngiven a four digit code." );
    printf("\nYou will need a four-digit secret number to login as an admin." );
    printf("\nRemember, you will not be able to login to the \nadmin panel without a 4-digit secret number. ");
    printf("\nThe secret number of these four numbers is \nexclusively yours so refrain from sharing it with anyone else. Thanks ");
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\n Now login with your username and password  ");
    printf("\n\n press any key to continue....... ");
    getch();
    system("CLS");
    alogin();
}
alogin(){
    char ausername [20],apassword[20];
    FILE *log;
    log =fopen("login/A_login_info.dll","r");
    struct alogin l;
    printf("\n\n\n\t\t\t ****************Enter your Username & Password*************");
    printf("\n\n\t\t\tUsername:");
    scanf("%s",&ausername);
    printf("\n\n\t\t\tPassword:");
    scanf("%s",&apassword);

     while(fread(&l,sizeof(l),1,log)){
        if (strcmp(ausername,l.ausername)==0 && strcmp (apassword,l.apassword)==0)
        {
             int pin;

             printf("\t\t\tEnter Secret pin:");
             scanf("%d",&pin);
             if (pin==7580|| pin==1451 || pin==7418||pin==7651||pin==7481||pin==7849||pin==3668||pin==3175||pin==5123||pin==4187)
                {
             printf("\n\n\n\t\t\t\t **************** Login Successful ****************\n");
             printf("\t\t\t\t\t****** *** ***** ***** ***** **** ****** \n\n");
             printf("\t\t\t\t****** **** Enter What you Want **** ****** \n\n");
             printf("\t\t\t1. USER Dashboard\n");
             printf("\t\t\t2. ADMIN Dashboard\n");
             int ch;
             printf("\n\t\t\tEnter Your Choice: ");
             scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                    USER_Dashboard();
                    break;
                case 2:
                    ADMIN_Dashboard();
                    break;

                default:
                    printf("\t\t\tWrong Input\n");

                }

                }
                else
                    printf("Sorry! Yor Are not an Admin ");

                }

                else{
                  printf("\t\t\tPlease Enter Correct UserID And Password\n");
                   break;
                }
     }
     fclose(log);

}

 /************************login end ********/

/*////////////////////////////////////////////////////////////////////////login System Function End//////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////Read Online //////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////Read Online End/////////////////////////////////////////////////////*/





/*///////////////////////////////////////////////////////////////////////////// User Section Start //////////////////////////////////////////////////////*/
int user_reg_sys()
{
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\t\t\t\t\t\t  **** 1.Registration **** ");
    printf("\n\t\t\t\t\t\t  **** 2.Login **** " );
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\t\t\t Please Enter What you want :" );

    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        registe();
        break;
    case 2:
        login();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }
}



int USER_Dashboard()
{
    printf("\n\t\t\t<------------------------------------>\n");
    printf("\t\t\t| ------------USER PANEL------------ |\n");
    printf("\t\t\t| |       1. Book Section          | |\n");
    printf("\t\t\t| |       2. Search Book           | |\n");
    printf("\t\t\t| |       3. Book Purchase         | |\n");
    printf("\t\t\t| |       4. My Account            | |\n");
    printf("\t\t\t| |       5. Complain              | |\n");
    printf("\t\t\t| |       6. Contact Us            | |\n");
    printf("\t\t\t| |       7. Online Read           | |\n");
    printf("\t\t\t| |       8. Log Out               | |\n");
    printf("\t\t\t| ---------------------------------- |");
    printf("\n\t\t\t*------------------------------------*");

    //printf("\n\t\t\t|------------------------------------|");
    printf("\n\t\t\t\tEnter what you want:");
    //printf("\n\t\t\t|------------------------------------|");


    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          show_books();


        break;
    case 2:
          search_book_u();
        break;
    case 3:
          Book_Purchase();
        break;
    case 4:
        My_Account();
        break;
    case 5:
        Complain();
        break;
    case 6:
        Contact_Us();
        break;
    case 7 :
        subscription();
        break;
    case 8 :
        log_out() ;
        break;


    default:
        printf("Wrong Input\n");

    }


}

int subscription()
{

    printf("\n\n\t\t\t\t<----------------------------------->\n");
    printf("\t\t\t\t| ----------SUBSCRIPTION----------- |\n");
    printf("\t\t\t\t| |      1.Premium User           | |\n");
    printf("\t\t\t\t| |      2.Buy Premium            | |\n");
    printf("\t\t\t\t| ----------------------------------|");
    printf("\n\t\t\t\t*-----------------------------------*");
    printf("\n\t\t\t\t\tEnter what you want:");


        int i;
        //printf("\n\t\t\tEnter Here:");
        scanf("%d",&i);
        if (i==1)
         {
           int j;
           printf("\n\t\t\tEnter your Premium key:");
           scanf("%d",&j);
           if(j==572450||j==569858||j==645710|| j==854792|| j==759412||j==457896||j==758074|| j==758091)
             {
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >>BOOK PURCHASE<<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");

    printf("\n\t\t\tEnter What You Want: ");


                int ch;
                scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                      CSE();

                    break;
                case 2:
                      EEE();
                    break;
                case 3:
                      English();
                    break;
                case 4:
                    History();
                    break;
                case 5:
                    Architecture();
                    break;
                case 6:
                    Civil();
                    break;
                case 7 :
                    Economic() ;
                    break;


                default:
                    printf("Wrong Input\n");

               }
           }
        }
      else if(i==2)
        {
               printf("\n\n\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  Monthly Ofer           | 1.Free  | 2.Basic |3.Standard| 4.Premium   |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               //printf("\t\t|  *********              | ******  | ********| ******** | *********** |\n");
               printf("\t\t|  >> Price               |   0     |   75tk  |   130tk  |    225tk    |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Reading limitation  |   15    |    50   |   250    |  Unlimited  |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Audio books         |   No    |    25   |   100    |  Unlimited  |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Download books      |   No    |    50   |   250    |  Unlimited  |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Offline books       |   No    |    5    |    15    |     30      |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Cancel anytime      |   Yes   |   Yes   |   Yes    |     Yes     |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Support             |   No    |   Yes   |   Yes    |     Yes     |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Upload books        |   No    |    No   |   No     |     Yes     |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
               printf("\t\t|  >> Share account       |   No    |    1    |    2     |       4     |\n");
               printf("\t\t|-------------------------|---------|---------|----------|-------------|\n");
                int ch;
                printf("\n\t\t\t\tWhat You want? Please Enter Here:  ");
                scanf("%d", &ch);
              if (ch==1)
              {
                  printf("\n\tYour Are Using Free plan .\n\t\tPlease Upgrade Your Plan.\n\t\t\tThank You for Using LMS");
              }
              else if(ch==2)
              {
                   printf("\n\n\t\t\t<-------------------------------------------->\n");
                   printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
                   printf("\t\t\t| |        1.Bkash                         | |\n");
                   printf("\t\t\t| |        2.Roket                         | |\n");
                   printf("\t\t\t| |        3.Nagad                         | |\n");
                   printf("\t\t\t| ------------------------------------------ |");
                   printf("\n\t\t\t*--------------------------------------------*");
                   printf("\n\t\t\t\t   Enter what you want:");

                   int p;
                   scanf("%d", &p);
                   if(p==1)
                   {
                        long pho,passs;
                        int SUB_price=75;
                        printf("Enter Your Bkash Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Bkash PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\n\t\t\t------------------Invoice--------------------\n");
                        printf("|\n\t\t\t     Payment From      :%ld \n\n\t\t\t     Subscription Price:%d\n",pho,SUB_price);
                        printf("\n\t\t\t   Your Are Using Basic Plan.\n\t\t\t   Thank You for Using LMS");
                        printf("\n\n\t\t\t------------------********-------------------\n");
                   }
                   else if (p==2)
                   {
                       long pho,passs;
                        int SUB_price=75;
                        printf("Enter Your Roket Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Roket PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                        printf("\nYour Are Using  Basic Plan .\n\t\t\tThank You for Using LMS");
                        printf("\n\t\t\t--------------------********-------------------\n");
                   }
                   else if (p==3)
                   {
                       long pho,passs;
                        int SUB_price=75;
                        printf("Enter Your Nagad Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Nagad PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using  Basic Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }

              }

              else if(ch==3)
              {
                      printf("\n\n\t\t\t<-------------------------------------------->\n");
                      printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
                      printf("\t\t\t| |        1.Bkash                         | |\n");
                      printf("\t\t\t| |        2.Roket                         | |\n");
                      printf("\t\t\t| |        3.Nagad                         | |\n");
                      printf("\t\t\t| ------------------------------------------ |");
                      printf("\n\t\t\t*--------------------------------------------*");
                      printf("\n\t\t\t\t   Enter what you want:");

                   int p;
                   scanf("%d", &p);
                   if(p==1)
                   {
                        long pho,passs;
                        int SUB_price=130;
                        printf("Enter Your Bkash Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Bkash PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Standard Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }
                   else if (p==2)
                   {
                       long pho,passs;
                        int SUB_price=130;
                        printf("Enter Your Roket Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Roket PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Standard Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }
                   else if (p==3)
                   {
                       long pho,passs;
                        int SUB_price=130;
                        printf("Enter Your Nagad Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Nagad PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Standard Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }

              }
            else if (ch==4)
            {
                  printf("\n\n\t\t\t<-------------------------------------------->\n");
                  printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
                  printf("\t\t\t| |        1.Bkash                         | |\n");
                  printf("\t\t\t| |        2.Roket                         | |\n");
                  printf("\t\t\t| |        3.Nagad                         | |\n");
                  printf("\t\t\t| ------------------------------------------ |");
                  printf("\n\t\t\t*--------------------------------------------*");
                  printf("\n\t\t\t\t   Enter what you want:");

                   int p;
                   scanf("%d", &p);
                   if(p==1)
                   {
                        long pho,passs;
                        int SUB_price=225;
                        printf("Enter Your Bkash Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Bkash PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Premium  Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }
                   else if (p==2)
                   {
                       long pho,passs;
                        int SUB_price=225;
                        printf("Enter Your Roket Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Roket PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Premium  Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }
                   else if (p==3)
                   {
                       long pho,passs;
                        int SUB_price=225;
                        printf("Enter Your Nagad Number :");
                        scanf("%ld",&pho);
                        printf("Enter Your Nagad PassWord :");
                        scanf("%ld",&passs);
                        printf("\n\t\t\t--------------------Invoice-------------------\n");
                        printf("\n\t\t Payment From      :%ld \n\t\t Subscription Price:%d",pho,SUB_price);
                       printf("\nYour Are Using Premium  Plan .\n\t\t\tThank You for Using LMS");
                       printf("\n\t\t\t--------------------********-------------------\n");
                   }

            }



        }
      printf("\t\t\Back To Main menu Enter (0):-->");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    case 12:
          Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }

}




int show_books()
{
    printf("\n\n\t\t\t<---------------------------------->\n");
    printf("\t\t\t| ----------SHOW BOOKS------------ |\n");
    printf("\t\t\t| |    1. Book List              | |\n");
    printf("\t\t\t| |    2.Upcoming Book List      | |\n");
    printf("\t\t\t| -------------------------------- |");
    printf("\n\t\t\t*-----------------------------------*");
    printf("\n\t\t\t\tEnter What You Want: ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Book_Purchase();
        break;
    case 2:
        show_book_upcoming();
        break;
    }

}



int  Book_Purchase()
{
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t         >>BOOK PURCHASE<<");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>1.CSE");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>2.EEE");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>3.English");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>4.History");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>5.Architecture ");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>6.Civil");
    printf("\n\t\t\t   |----------------------------|");
    printf("\n\t\t\t\t   >>7.Economic");
    printf("\n\t\t\t   |----------------------------|");

    printf("\n\t\t\t\tEnter What You Want: ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          CSE();

        break;
    case 2:
          EEE();
        break;
    case 3:
          English();
        break;
    case 4:
        History();
        break;
    case 5:
        Architecture();
        break;
    case 6:
        Civil();
        break;
    case 7 :
        Economic() ;
        break;


    default:
        printf("Wrong Input\n");

    }
}
int CSE()
{

   printf("\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t|  *********    | ******  | ********|\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.CSE-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.CSE-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.CSE-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.CSE-104    |   D     |  104    | \n");
   printf("\t\t\t|---------------|---------|---------|\n\n");

    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
   //printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {


   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t|  *********    | ******  | ********|  \n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.CSE-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.CSE-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.CSE-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.CSE-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");
   printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        CSE_book1();
        break;
    case 2:
        CSE_book2();
        break;
    case 3:
        CSE_book3();
        break;
    case 4:
        CSE_book4();
        break;
   }
   }
   else if (s==2)
   {
   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
   //printf("\t\t\t|  *********    | ******  | ********| ***** | \n");
   printf("\t\t\t|  1.CSE-101    |   A     |  101    |  547  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.CSE-102    |   B     |  102    |  478  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.CSE-103    |   C     |  103    |  784  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.CSE-104    |   D     |  104    |  319  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");

   printf("\n\t\t\t Enter which Book you want to buy now :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }


   }



}
int EEE()
{

   //printf("\n\t\t\t------------------------------------------\n");

   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t|  *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.EEE-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.EEE-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.EEE-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.EEE-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");


    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
   //printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {

   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.EEE-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.EEE-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.EEE-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.EEE-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");

    printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        EEE_book1();
        break;
    case 2:
        EEE_book2();
        break;
    case 3:
        EEE_book3();
        break;
    case 4:
        EEE_book4();
        break;
   }

   }
    else if(s==2)
    {
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.EEE-101    |   A     |  101    |  600  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.EEE-102    |   B     |  102    |  350  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.EEE-103    |   C     |  103    |  840  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.EEE-104    |   D     |  104    |  547  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");

   printf("\n\t\t\t Enter which Book you want to buy now :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

}

int English()
{


   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t| BOOK Name     | Author  | Book Id |\n");
  // printf("\t\t\t|   *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.Eng-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.Eng-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.Eng-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.Eng-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");


    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
  // printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
    {
   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t| BOOK Name     | Author  | Book Id |\n");
   //printf("\t\t\t  *********     | ******  | ********|\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t  1.Eng-101     |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t  2.Eng-102     |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t  3.Eng-103     |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t  4.Eng-104     |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");

   printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Eng_book1();
        break;
    case 2:
        Eng_book2();
        break;
    case 3:
        Eng_book3();
        break;
    case 4:
        Eng_book4();
        break;
    }
    }


    else if(s==2)
    {

   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
   //printf("\t\t\t|  *********    | ******  | ********| ***** |\n\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.Eng-101    |   A     |  101    |  400  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.Eng-102    |   B     |  102    |  770  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.Eng-103    |   C     |  103    |  256  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.Eng-104    |   D     |  104    |  630  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");

   printf("\n\t\t\t Enter which Book you want to buy now :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }


}

int History()
{
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.His-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.His-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.His-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.His-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");


    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
   //printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {
   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.His-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.His-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.His-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.His-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");
   printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        his_book1();
        break;
    case 2:
        his_book2();
        break;
    case 3:
        his_book3();
        break;
    case 4:
        his_book4();
        break;
    }
   }

    else if(s==2)
    {
   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
   //printf("\t\t\t|  *********    | ******  | ********| ***** |\n\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.His-101    |   A     |  101    |  540  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|n");
   printf("\t\t\t|  2.His-102    |   B     |  102    |  390  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.His-103    |   C     |  103    |  875  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.His-104    |   D     |  104    |  684  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");
   printf("\n\t\t\t Enter which Book you want to buy now :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }



}

int Architecture()
{

   printf("\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.ARC-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.ARC-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.ARC-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.ARC-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");

    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
  // printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {
   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.ARC-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.ARC-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.ARC-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.ARC-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");
   printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        arc_book1();
        break;
    case 2:
        arc_book2();
        break;
    case 3:
        arc_book3();
        break;
    case 4:
        arc_book4();
        break;
    }

   }

    else if(s==2)
    {
   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
   //printf("\t\t\t|  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.ARC-101    |   A     |  101    |  755  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.ARC-102    |   B     |  102    |  900  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.ARC-103    |   C     |  103    |  645  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.ARC-104    |   D     |  104    |  812  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");
   printf("\n\t\t\t Enter which Book you want to buy now :   ");


   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }



}


int Civil()
{

   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t|  *********    | ******  || ********||\n\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.CVl-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.CVl-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.CVl-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.CVl-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");



    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
  // printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {
   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t|  *********    | ******  || ********||\n\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.CVl-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.CVl-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.CVl-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.CVl-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n\n");
   printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        civ_book1();
        break;
    case 2:
        civ_book2();
        break;
    case 3:
        civ_book3();
        break;
    case 4:
        civ_book4();
        break;
    }
   }

    else if(s==2)
    {
   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price |\n");
  // printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.CVl-101    |   A     |  101    |  555  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.CVl-102    |   B     |  102    |  768  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.CVl-103    |   C     |  103    |  281  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.CVl-104    |   D     |  104    |  596  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");
   printf("\n\t\t\t Enter which Book you want to buy now :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }


}



int Economic()
{



   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.ECO-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.ECO-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.ECO-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.ECO-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");

    printf("\n\t\t\t<------------------------------------->\n");
    printf("\t\t\t| --------PURCHASE SYSTEM------------ |\n");
    printf("\t\t\t| |        1.Online Read            | |\n");
    printf("\t\t\t| |        2.Buy Now                | |\n");
    printf("\t\t\t| ----------------------------------- |");
    printf("\n\t\t\t*-------------------------------------*");
    printf("\n\t\t\t\tEnter what you want:");
   int s;
   printf("\n\t\tEnter Your Choose:");
   scanf("%d",&s);
   if(s==1)
   {
   printf("\n\n\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id |\n");
   //printf("\t\t\t  *********    || ******  || ********||\n\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  1.ECO-101    |   A     |  101    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  2.ECO-102    |   B     |  102    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  3.ECO-103    |   C     |  103    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
   printf("\t\t\t|  4.ECO-104    |   D     |  104    |\n");
   printf("\t\t\t|---------------|---------|---------|\n");
    printf("\n\t\t\t Enter which Book you want to Read :   ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        eco_book1();
        break;
    case 2:
        eco_book2();
        break;
    case 3:
        eco_book3();
        break;
    case 4:
        eco_book4();
        break;
    }
   }

    else if(s==2)
    {
   printf("\n\n\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  BOOK Name    | Author  | Book Id | Price | \n");
   //printf("\t\t\t  *********    || ******  || ********|| ******|| \n\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  1.ECO-101    |   A     |  101    |   20  |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  2.ECO-102    |   B     |  102    |   400 |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  3.ECO-103    |   C     |  103    |   250 |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n");
   printf("\t\t\t|  4.ECO-104    |   D     |  104    |   140 |\n");
   printf("\t\t\t|---------------|---------|---------|-------|\n\n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
    }


}
/*.........................................................          payment   Start     ............................................................*/

int payment()
{

   printf("\n\n\t\t\t<------------------------------------------>\n");
   printf("\t\t\t| ----<< Select Your Payment System >>---- |\n ");
   printf("\t\t\t| |         1.Mobile Banking             | |\n");
   printf("\t\t\t| |         2.Bank Account               | |\n");
   printf("\t\t\t| |         3.CARD                       | |\n");
   printf("\t\t\t| |         4.Paypal                     | |\n");
   printf("\t\t\t| ---------------------------------------- |");
   printf("\n\t\t\t*------------------------------------------*");
   printf("\n\t\t\t\t   Enter what you want:");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Mobile_banking();
        break;
    case 2:
        Bank_Account();
        break;
    case 3:
        Card();
        break;
    case 4:
       Paypal();
       break;
    default:
        printf("Wrong Input\n");

    }
}

int Mobile_banking()
{

   printf("\n\n\t\t\t<-------------------------------------------->\n");
   printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
   printf("\t\t\t| |        1.Bkash                         | |\n");
   printf("\t\t\t| |        2.Roket                         | |\n");
   printf("\t\t\t| |        3.Nagad                         | |\n");
   printf("\t\t\t| ------------------------------------------ |");
   printf("\n\t\t\t*--------------------------------------------*");
   printf("\n\t\t\t\t   Enter what you want:");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        bkash();
        break;
    case 2:
        roket();
        break;
    case 3:
        nagad();
        break;

    default:
        printf("Wrong Input\n");

    }



}

int Bank_Account()
{
    printf("\n\n\t\t\t<-------------------------------------------->\n");
    printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
    printf("\t\t\t| |        1.Bank Asia                     | |\n");
    printf("\t\t\t| |        2.Islami Bank                   | |\n");
    printf("\t\t\t| |        3.Duch Bangla Bank              | |\n");
    printf("\t\t\t| ------------------------------------------ |");
    printf("\n\t\t\t*--------------------------------------------*");
    printf("\n\t\t\t\t   Enter what you want:");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Bank_Asia();
        break;
    case 2:
        islami_bank();
        break;
    case 3:
        Duch_Bangla_Bank();
        break;

    default:
        printf("Wrong Input\n");


    }
}

int Card ()
{
   printf("\n\n\t\t\t<-------------------------------------------->\n");
    printf("\t\t\t| -----<< Select Your Payment System >>----- |\n");
    printf("\t\t\t| |        1.Mastercard                    | |\n");
    printf("\t\t\t| |        2.Visa Card                     | |\n");
    printf("\t\t\t| ------------------------------------------ |");
    printf("\n\t\t\t*--------------------------------------------*");
    printf("\n\t\t\t\t   Enter what you want:");


   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Mastercard();
        break;
    case 2:
        visa();
        break;
    default:
        printf("Wrong Input\n");

    }
}



int bkash ()

{
    {
        float total, Shipping=50;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name            : ");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number    : ");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Book Name                  : ");
            gets(pay.bname);
            fflush(stdin);
            printf("Enter Book price           : ");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity        : ");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address: ");
            gets(pay.add);
            total=((pay.price)*(pay.qt))+ Shipping;
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName            : %s\n\t\tPhone Number    : %ld\n\t\tBook Name        : %s\n\t\tPrice           : %ld\n\t\tQuantity        : %ld\n\t\tShipping Address: %s\n\t\tTotal Amount with shipping : %f",pay.name,pay.phone,pay.bname,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
            case 1:
            fflush(stdin);
            printf("Enter Your Bkash Number         : ");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Total Price with shipping : ");
            scanf("%ld",&pay.tprice);
            fflush(stdin);
            printf("Enter Your Bkash PassWord       : ");
            scanf("%[^\n]",&pay.pass);

            printf("\n\n\t\t=====================================================================\n");
            printf("\t\t|                 << Invoice >>                                     |\n");
            printf("\t\t|           LIBRARY MANAGEMENT SYSTEM                               |\n");
            printf("\t\t|                                                                   |\n");
            printf("\t\t|     Name                       : %s                      |\n",pay.name);
            printf("\t\t|     Phone Number               : %ld                    |\n",pay.phone);
            printf("\t\t|     Book Name                  : %s                     |\n",pay.bname);
            printf("\t\t|     Price                      : %ld                    |\n",pay.price);
            printf("\t\t|     Quantity                   : %ld                       |\n",pay.qt);
            printf("\t\t|     Shipping Address           : %s                       |\n",pay.add);
            printf("\t\t|     Total Amount with shipping : %f                         |\n",total);
            printf("\t\t|     Bkash Number               : %ld                       |\n",pay.ph);
            printf("\t\t|                                                                   |\n");
            printf("\t\t|    ---------------  \t\t\t---------------                         |\n");
            printf("\t\t|    Admin Signature  \t\t\tBuyer Signature                           |\n");
            printf("\t\t|           Thank you.... Order done                                  |\n");
            printf("\t\t=====================================================================\n");
          break;

    default:
        printf("Wrong Input\n");
    }

    }
       printf("\n\t\t\Back To Main menu Enter (0):-->");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }



          }



int roket ()
{
     {
         float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            fflush(stdin);
            printf("Enter Your Roket Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
            fflush(stdin);
            printf("Enter Your Roket Password :");
            scanf("%[^\n]",&pay.pass);
            printf("\n\t\t\t--------------------Invoice-------------------\n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n\t\tRoket Number:%ld",pay.name,pay.phone,pay.price,pay.qt,pay.add,total,pay.ph);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");
          break;

    default:
        printf("Wrong Input\n");
          }
    }
printf("\n\t\t\Back To Main menu Enter (0):-->");

       int c;
    scanf("%d", &c);
    switch(c)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}



int nagad ()

{
    {
       float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            fflush(stdin);
            printf("Enter Your nagad Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
            fflush(stdin);
            printf("Enter Your nagad PassWord :");
            scanf("%[^\n]",&pay.pass);
            printf("\n\t\t\t--------------------Invoice-------------------\n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n\t\tnagad Number:%ld",pay.name,pay.phone,pay.price,pay.qt,pay.add,total,pay.ph);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");
          break;

    default:
        printf("Wrong Input\n");
    }

    }

   printf("\n\t\t\Back To Main menu Enter (0):-->");
   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

}
}


int Bank_Asia ()
{

            {
                float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            fflush(stdin);
            printf("Enter Your Account Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Account Holder Name:");
            scanf("%[^\n]",&pay.AN);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
           printf("\n\t\t\t--------------------Invoice-------------------\n");
           printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");

             break;

    default:
        printf("Wrong Input\n");




    }
            }



 printf("\n\t\t\Back To Main menu Enter (0):-->");

       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int islami_bank()
{

           {
               float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            fflush(stdin);
            printf("Enter Your Account Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Account Holder Name:");
            scanf("%[^\n]",&pay.AN);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
           printf("\n\t\t\t--------------------Invoice-------------------\n");
           printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");

             break;

    default:
        printf("Wrong Input\n");




    }
           }

printf("\n\t\t\Back To Main menu Enter (0):-->");

       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Duch_Bangla_Bank()
{


           {
               float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            fflush(stdin);
            printf("Enter Your Account Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Account Holder Name:");
            scanf("%[^\n]",&pay.AN);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
           printf("\n\t\t\t--------------------Invoice-------------------\n");
           printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");

             break;

    default:
        printf("Wrong Input\n");



    }
           }

printf("\n\t\t\Back To Main menu Enter (0):-->");

       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Mastercard()
{


           {
               float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
             fflush(stdin);
            printf("Enter Your CARD Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Your CARD CVC Number :");
            scanf("%ld",&pay.cvc);
            fflush(stdin);
            printf("Enter Your CARD Valid Time :");
            scanf("%ld",&pay.valid);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
           printf("\n\t\t\t--------------------Invoice-------------------\n");
           printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");

             break;

    default:
        printf("Wrong Input\n");



    }
           }

printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int visa ()
{

          {
               float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
             fflush(stdin);
            printf("Enter Your CARD Number :");
            scanf("%ld",&pay.ph);
            fflush(stdin);
            printf("Enter Your CARD CVC Number :");
            scanf("%ld",&pay.cvc);
            fflush(stdin);
            printf("Enter Your CARD Valid Time :");
            scanf("%ld",&pay.valid);
            fflush(stdin);
            printf("Enter Total Price :");
            scanf("%ld",&pay.tprice);
           printf("\n\t\t\t--------------------Invoice-------------------\n");
           printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
           printf("\nThank you.... Order done");
           printf("\n\t\t\t--------------------********-------------------\n");

             break;

    default:
        printf("Wrong Input\n");



    }
          }

printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Paypal()
{


           {
               float total;
            printf("\t\t\t------- Enter Your payment and Shipping Information ---------\n");
            fflush(stdin);
            printf("Enter Your Name:");
            scanf("%[^\n]",&pay.name);
            fflush(stdin);
            printf("Enter your Phone Number:");
            scanf("%ld",&pay.phone);
            fflush(stdin);
            printf("Enter Book price:");
            scanf("%ld",&pay.price);
            fflush(stdin);
            printf("Enter Book Quantity:");
            scanf("%ld",&pay.qt);
            fflush(stdin);
            printf("Enter your shipping Address:");
            gets(pay.add);
            total=(pay.price)*(pay.qt);
            printf("\n\t\t\t Please  verify your data? \n");
            printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
            printf("\t\t\tIf all information is Correct than press (1) for Conform\n");
            printf("\n\t\t\t Enter Here:  ");
            printf("\t\t\Back To Main menu Enter (0):-->");
            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
             printf("You need to login your paypal Account:\n");
             fflush(stdin);
             printf("Enter Your Email:");
             scanf("%[^\n]",&pay.email);
             fflush(stdin);
             printf("Enter Password:");
             scanf("%[^\n]",&pay.pass);
             fflush(stdin);
             printf("Enter Total Price :");
             scanf("%ld",&pay.tprice);
             printf("\n\t\t\t--------------------Invoice-------------------\n");
             printf("\n\t\tName:%s\n\t\tPhone Number:%ld\n\t\tPrice:%ld\n\t\tQuantity:%ld\n\t\tShipping Address:%s\n\t\tTotal Amount:%f\n",pay.name,pay.phone,pay.price,pay.qt,pay.add,total);
             printf("\nThank you.... Order done");
             printf("\n\t\t\t--------------------********-------------------\n");

               break;

             default:
               printf("Wrong Input\n");



    }
           }

printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}


/*.........................................................          payment End        ............................................................*/

int Contact_Us()

{
 printf("\n\t\t\t//////////////// ..::Our Phone Number : 0123456789 /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our Email : admin@lms.com  /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our fax : fax id .com  /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our address : Mirpur-2 || Dhaka || 120  /////////////////// \n");
 printf("\t\t\Back To Main menu Enter (0):-->");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Complain()
{

   printf("\n\t\t\ 1.Type Complain :");
   printf("\n\t\t\ 2.View Reply :");
   printf("\n\t\t\ 3.Main Menu :");
   printf("\n\t\t\ Enter what you want :");
   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        submit();
        break;
    case 2 :
        view_reply();
        break;
    case 3:
        USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }

}



int submit()
{
    char CMessage[20];
    FILE *fptr;
    fptr = fopen("Complain.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }

    fflush(stdin);

        printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
        gets(li.mes);
        fprintf(fptr, "Complain= %s\n", li.mes);

    fclose(fptr);


        printf("\n\t\t\t..::1.Conform ");
       // printf("\n\t\t\t..::2.Log Out ");
        printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        sent();
        break;

    default:
        printf("Wrong Input\n");

    }
    printf("\t\t\Back To Main menu Enter (0):-->");
       //int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int view_reply ()
{
  FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("reply.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}




int sent()
{
    printf("\t\t\t\t Message Submit Successful...");
    printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

}



/* ***********************************************************online Read ***************************************************************/

int CSE_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/1.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int CSE_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/2.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int CSE_book3()//3
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/3.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}







int CSE_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/4.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}



/** EEE ****/




int EEE_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/5.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int EEE_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/6.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int EEE_book3() //3
 {
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/7.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }

 }





int EEE_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/8.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}

/*** EEE End**** */



/** ENglish ****/


int Eng_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/9.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int Eng_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/10.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int Eng_book3(){//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/11.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int Eng_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/12.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}



/********** English end   *********/


/*************** History ************/


int his_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/13.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int his_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/14.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int his_book3(){ //3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/15.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int his_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/16.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}


/****************** History End ****************/

/********** Arc********/

int arc_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/17.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int arc_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/18.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int arc_book3(){//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/19.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int arc_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/20.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}


/************** Arc end ************/


int civ_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/21.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int civ_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/22.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int civ_book3(){ //3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/23.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int civ_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/24.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}
/****** civ end ********/

/************* ECO **************/

int eco_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/25.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int eco_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/26.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int eco_book3() {//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/27.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int eco_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/28.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }

}

/************* ECO End **************/



int show_book_upcoming()
{
    int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >>UPCOMING BOOK LIST<<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");


    printf("\n\t\t\tEnter you chose:");
    scanf("%d",&cata);
    if(cata==1)
     {
        printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/cse.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
        printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");


       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t|----------------------------------------------|\n");
            printf("\n\t|\t\tName            :%s\n\t\t\tPhone           :%ld           |\n\t|\t\tEmail           :%s\n|\t\t\tShipping Address:%s|\n|\t\t\tBook Id         :%s|\n|\t\t\tBook Name       :%s|",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t|----------------------------------------------|\n");
}

printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
       printf("\t\t\t\t\tThank you... \n\n");
        printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }



     }

    else if (cata==2)
    {
         printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eee.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);
                    found++;

                }

            }

            if(found!=0)

            {
                printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
        printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");
}
        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }



    }
    else if (cata==3)
    {
        printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eng.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {


                     printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);
                    found++;

                }

            }

            if(found!=0)

            {
                 printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
       printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
       printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");
}
        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }


    }
    else if (cata==4)
    {
         printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/his.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);
                    found++;

                }

            }

            if(found!=0)

            {
                 printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
       printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
       printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");

}

        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }


    }
    else if (cata==5)
    {
        printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/ach.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);
                    found++;

                }

            }

            if(found!=0)

            {
                 printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
       printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
       printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");

}

        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==6)
    {
         printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/civil.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
       printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
            printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");

}

        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==7)
    {
         printf("\n\t\t\t\  =============================================\n\t\t\t\t\tLIST OF Books\n\t\t\t\  =============================================\n\n\t\t  Name\t\t  Id No\t\t  Author\t\tSubject\n\t\t==================================================================\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eco.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t\t\t\t\tName\t: %s\n\t\t\t\t\tId\t: %ld\n\t\t\t\t\tAuthor\t: %s\n\t\t\t\t\tSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                 printf("\n\t\t==================================================================  [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
       printf("\n\t\t\tBack To Main menu Enter (0):-->\n\n\t\t\tIf you want PreOder then press 1  :");
       printf("\n\n\t\tDon't worry, You can cancel your pre-order at any time.\n");

       int oder;
       printf("Enter::");
       scanf("%d",&oder);
       if(oder==1)
          {
            char Name[20],book_id[20],mail[30],s_add[30],bname[20];
              long phone;

            fflush(stdin);
            printf("Enter Your Name:\n");
            gets(Name);
            fflush(stdin);
            printf("\nEnter Phone Number:");
            scanf("%ld",&phone);
            fflush(stdin);
            printf("\nEnter Your Email:");
            gets(mail);
            fflush(stdin);
            printf("\nShipping Address:");
            gets(s_add);
            fflush(stdin);
            printf("\nEnter Book Id:");
            gets(book_id);
            fflush(stdin);
            printf("\nEnter Book Name:");
            gets(bname);
             printf("\n\n\n\t\t----------------------------------------------\n");
            printf("\n\t\t\tName            :%s\n\t\t\tPhone           :%ld\n\t\t\tEmail           :%s\n\t\t\tShipping Address:%s\n\t\t\tBook Id         :%s\n\t\t\tBook Name       :%s",Name,phone,mail,s_add,book_id,bname);
            printf("\n\n\t\t----------------------------------------------\n");


}

        printf("\n\n\***An email will be sent to your email 7 days before the book is published with the details of the payment.***\n");
        printf("\t\t\t\t\tThank you... \n\n");
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    case 12:
        Admin_main_menu();
        break;
    default:
        printf("Wrong Input\n");

    }


    }



}


int search_book_u()
{
   int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >>SEARCH BOOK<<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");



    printf("\n\t\t\tEnter you chose:");
    scanf("%d",&cata);
    if(cata==1)
    {
         do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/cse.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

    }
    else if (cata==2)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eee.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if (cata==3)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eng.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
         USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if (cata==4)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/his.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==5)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/ach.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==6)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/civil.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
         USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==7)
    {

  do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eco.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

    }

}





/*#############################################################online Read End$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

/*///////////////////////////////////////////////////////////////////////////// User Section End //////////////////////////////////////////////////////*/


/*///////////////////////////////////////////////////////////////////////////// Admin Section Start //////////////////////////////////////////////////////*/

int Admin_main_menu()
{
      printf("\n\t\t\t1.Admin Dashboard \n\t\t\t2.User DashBoard\n\t\t\t3.Log Out ");
      printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        ADMIN_Dashboard();
        break;
    case 2 :
        USER_Dashboard();
        break;
    case 3 :
        log_out();
        break;
    default:
        printf("Wrong Input\n");
    }

}

int ADMIN_Dashboard()
{

    printf("\n\t\t\t<------------------------------>\n");
    printf("\t\t\t| ---------ADMIN PANEL-------- |\n");
    printf("\t\t\t| |    1.Book Section        | |\n");
    printf("\t\t\t| |    2.Search Book         | |\n");
    printf("\t\t\t| |    3.My Account          | |\n");
    printf("\t\t\t| |    4.User Feedback       | |\n");
    printf("\t\t\t| |    5.Log Out             | |\n");
    printf("\t\t\t| ---------------------------- |\n ");
    printf("\t\t\t*------------------------------*");
    printf("\n\t\t\t    Enter what you want:");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          Book_Section();
        break;
    case 2:
          Search_Book ();
        break;
    case 3:
          My_Account ();
        break;
    case 4:
        user_feedback();
        break;
    case 5:
        log_out();
        break;

    default:
        printf("Wrong Input\n");

    }




}

int Book_Section()
{
    printf("\n\n\t\t\t<------------------------------------>\n");
    printf("\t\t\t| ----------BOOK SECTION------------ |\n");
    printf("\t\t\t| |    1. Add New Book             | |\n");
    printf("\t\t\t| |    2. Show Book List           | |\n");
    printf("\t\t\t| |    3. Update Book Info         | |\n");
    printf("\t\t\t| |    4. Delete Old Info          | |\n");
    printf("\t\t\t| |    5. Log Out                  | |\n");
    printf("\t\t\t| ---------------------------------- |\n");
    printf("\t\t\t*------------------------------------*");
    printf("\n\t\t\t    Enter your Choice:");
    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Add_Book_info();
        break;
    case 2:
        show_Book_list();

        break;
    case 3:
        update_book();
        break;
    case 4:
        delete_info();
        break;
    case 5:
        log_out();
        break;

    default:
        printf("\t\t\tWrong Input\n");

    }

}

int Search_Book()
{
      int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>SEARCH BOOK<<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");


    printf("\nEnter you chose:");
    scanf("%d",&cata);
    if(cata==1)
    {
         do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/cse.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

    }
    else if (cata==2)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eee.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if (cata==3)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eng.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if (cata==4)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/his.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==5)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/ach.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==6)
    {
        do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/civil.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==7)
    {

  do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("book/eco.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

    }



}



int My_Account()
{

     printf("\t\t1.Add Your Information");
     printf("\n\t\t2.View Your Information");
     printf("\n\t\t Enter What You want:");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          update_account  ();
        break;
    case 2:
          view_account ();
        break;
    default:
        printf("Wrong Input\n");

    }

}



int update_account()

{
    char name[20];
    FILE *fptr;
    int id;

    float intake, section;
    fptr = fopen("myaccount.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("\t\t\tEnter Student id:");
    scanf("%d", &id);
    fprintf(fptr, "Student Id= %d\n", id);
    printf("\t\t\tEnter Your Name:");
    scanf("%s", name);
    fprintf(fptr, "Name= %s\n", name);
    printf("\t\t\tEnter the Intake:");
    scanf("%f", &intake);
    fprintf(fptr, "Intake= %.2f\n", intake);
    fclose(fptr);


    printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}
int view_account()
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("myaccount.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}





int log_out ()
{
    printf("\n\n\t\t\t*************Log Out Successful**************** \n");

}


int Add_Book_info()

{


    int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >> ADD BOOK<<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");

    printf("\n\t\t\tEnter What You Want: ");
    if(cata==1)
    {
        fp=fopen("book/cse.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }


    }
    else if (cata==2)
    {
       fp=fopen("book/eee.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }
  else if (cata==3)
    {
       fp=fopen("book/eng.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }

  else if (cata==4)
    {
       fp=fopen("book/his.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }
  else if (cata==5)
    {
       fp=fopen("book/ach.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }
  else if (cata==6)
    {
       fp=fopen("book/civil.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }
  else if (cata==7)
    {
       fp=fopen("book/eco.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

 }

}

int show_Book_list()
{
      int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >> SHOW BOOK LIST <<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");

    printf("\n\t\t\tEnter What You Want: ");
    scanf("%d",&cata);
    if(cata==1)
     {
        printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/cse.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
     }

    else if (cata==2)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eee.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==3)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eng.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==4)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/his.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==5)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/ach.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==6)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/civil.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==7)
    {
         printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book/eco.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }




}
int update_book()
{

    int cata;
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t    >> UPDATE BOOK <<");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>1.CSE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>4.History");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|----------------------------|");
    printf("\n\t\t\t>>7.Economic");
    printf("\n\t\t|----------------------------|");

    printf("\n\t\t\tEnter What You Want: ");
    scanf("%d",&cata);

    if(cata==1)
    {

        fp=fopen("book/cse.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/cse.dll");

        rename("temp.dat","book/cse.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
  else if (cata==2)
  {

        fp=fopen("/book/eee.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eee.dll");

        rename("temp.dat","book/eee.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
  }
    else if(cata==3)
    {

        fp=fopen("book/eng.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eng.dll");

        rename("temp.dat","book/eng.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }
    else if (cata==4)
    {

        fp=fopen("book/his.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/his.dll");

        rename("temp.dat","book/his.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if(cata==5)
    {

        fp=fopen("book/ach.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/ach.dll");

        rename("temp.dat","book/ach.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if(cata==6)
    {

        fp=fopen("book/civil.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/civil.dll");

        rename("temp.dat","book/civil.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

    else if (cata==7)
    {

        fp=fopen("book/eco.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);
        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eco.dll");

        rename("temp.dat","book/eco.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
    }

}




int delete_info()
{
    int cata;
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>1.CSE:");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>2.EEE");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>3.English");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>4.History:");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>5.Architecture ");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>6.Civil");
    printf("\n\t\t|-----------------------|");
    printf("\n\t\t\t>>7.Economic:");
    printf("\n\t\t|-----------------------|");
    printf("\nEnter you chose:");
    scanf("%d",&cata);

        if(cata==1)
        {
            fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/cse.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/cse.dll");

        rename("temp.dat","book/cse.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

        }

        else if(cata==2)
        {

            fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/eee.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eee.dll");

        rename("temp.dat","book/eee.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

        }
        else if(cata==3)
        {
            fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/eng.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eng.dll");

        rename("temp.dat","book/eng.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

        }

       else if(cata==4)
       {
           fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/his.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/his.dll");

        rename("temp.dat","book/his.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

       }

       else if(cata==5)
       {
           fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/ach.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/ach.dll");

        rename("temp.dat","book/ach.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

       }
       else if(cata==6)
       {
           fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/civil.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/civil.dll");

        rename("temp.dat","book/civil.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

       }
       else if(cata==7)
       {
           fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("book/eco.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book/eco.dll");

        rename("temp.dat","book/eco.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

       }

}

int user_feedback()
{

  printf("\t\t1.View Complain");
  printf("\n\t\t2.Reply");
  printf("\n\t\t\What You Want :>");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          view_complain ();
        break;
    case 2 :
        reply_complain();
        break;

    default:
        printf("Wrong Input\n");

    }
}

int view_complain()
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("Complain.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu ();
        break;
    default:
        printf("Wrong Input\n");

    }

}

int reply_complain()
{


     char rMessage[20];
    FILE *fptr;
    fptr = fopen("reply.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    /* printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
    scanf("%s", CMessage);
    fprintf(fptr, "Complain= %s\n", CMessage);*/

    fflush(stdin);

        printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
        gets(lr.rmes);
        fprintf(fptr, "Reply= %s\n", lr.rmes);

    fclose(fptr);


        printf("\n\t\t\t..::1.Conform ");
       // printf("\n\t\t\t..::2.Log Out ");
        printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        sent_reply();
        break;

    default:
        printf("Wrong Input\n");

    }


}

int sent_reply()
{

    printf("\n\t\t Reply Sent to User");
    printf("\n\t\tBack To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu ();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Admin_reg_sys()
{
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\t\t\t\t\t\t  **** 1.Registration **** ");
    printf("\n\t\t\t\t\t\t  **** 2.Login **** " );
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\t\t\t Please Enter What you want :" );

    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        aregiste();
        break;
    case 2:
        alogin();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }
}

/*///////////////////////////////////////////////////////////////////////////// Admin Section End //////////////////////////////////////////////////////*/



/*///////////////////////////////////////////////////////////////////////////// Main Function Start//////////////////////////////////////////////////////*/

int main ()


{


     printf("\n\n");

     printf("\n\n\t\t\t\t\t\t<-----------*********--------------->\n");
     printf("\t\t\t\t\t\t|      Library Management System    |\n");
     printf("\t\t\t\t\t\t<---------------*********----------->\n\n\n\n");



     printf("\t\t\t\t\t|*************** ********* ***** Welcome Massage ***************** ********************| \n");
    printf("\t\t\t\t\t|     The only thing that you absolutely have to know, is the location of the library  |\n");
    printf("\t\t\t\t\t|******************************** *** ***** ***** ****** **** *************************| \n\n\n\n\n\n");





    printf("\t\t\t\t\t\t<--------------------------------->\n");
    printf("\t\t\t\t\t\t| -----------********------------ |\n");
    printf("\t\t\t\t\t\t| |      1.Became a User        | |\n");
    printf("\t\t\t\t\t\t| |      2.Became an Admin      | |\n");
    printf("\t\t\t\t\t\t| -----------********------------ |");
    printf("\n\t\t\t\t\t\t*---------------------------------*\n");
    printf("\n\t\t\t\t\t\t\tEnter what you want:");




    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        user_reg_sys();
        break;
    case 2:
        Admin_reg_sys();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }


    return 0;

}

/*///////////////////////////////////////////////////////////////////////////// Main Function End //////////////////////////////////////////////////////*/



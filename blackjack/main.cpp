#include<bits/stdc++.h>
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
void calc_func();
int main();
void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<" \tEnter the following details\n"<<endl;
        cout<<"\tUSERNAME : ";
        cin>>user;
        cout<<"\tPASSWORD : ";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\n\tWELCOME "<<user<<" \n\tWe're glad that you're here.\n";
                cin.get();
               // cin.get();
                calc_func();
               // main();
        }
        else
        {
                cout<<"\n\tLOGIN ERROR\n \tPlease check your user-name and password and try again\n";
                main();
                return;
        }
}
void registr()
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();
        return;


}

void forgot()
{
        int ch;
        system("cls");
        cout<<"\tForgot Password ? We're here for help\n";
        cout<<"\t1.Search your id by User-name"<<endl;
        cout<<"\t2.Main menu"<<endl;
        cout<<"\tEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\n\tEnter your  user-name :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\tHurray, account found\n";
                                cout<<"\n\tYour password is  "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                                return;
                        }
                        else
                        {
                                cout<<"\n\tSorry, you are not registered in our database\n";
                                cout<<"\tpress 1 for registration "<<"\n";
                                int entry;
                                cin>>entry;
                                if(entry == 1)
                                {
                                    registr();
                                }
                                cin.get();
                                cin.get();
                                main();
                                return;
                        }
                        break;
                }

                case 2:
                {
                        cin.get();
                        main();
                        return;
                }
                default:
                        cout<<"\tSorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
                        return;
        }
}
bool check(int p,int d,int k,int & m,int mny,int ins)
{
    if(k==0 && p==21)
    {   //system("cls");
        cout<<"\tcongratulation you are a blackJack"<<endl;
        m=m+1.5*mny;
          cout<<"\tyou have total money: "<<m<<endl;
        return 1;
    }
    else if(k==1 && p>21)
    {  // system("cls");
        cout<<"\tyou have been bust\n";
        if(ins!=1)
            m-=mny;
              cout<<"\tyou have total money: "<<m<<endl;
        return 1;
    }
    else if(k==4 &&  d==21)
    {  //system("cls");
        cout<<"\tyou have been bust\n";
        if(ins!=1)
            m-=mny;
              cout<<"\tyou have total money: "<<m<<endl;
            return 1;
    }
    else if(k==2 && d==p)
    {
        cout<<"\tdraw\n"; return 1;
    }
    else if(k==2 && d>21)
    { //  system("cls");
        cout<<"\tyou have win\n";
        m+=mny;
          cout<<"\tyou have total money: "<<m<<endl;
        return 1;
    }
    else if(k==2 && d>p && d<=21)
    {   system("cls");
        cout<<"\tyou have lost\n";
        if(ins!=1)
            m-=mny;
        cout<<"\tyou have total money: "<<m<<endl;
        return 1;
    }
    return 0;
}
int main()
{
cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
cout<<"\t\t\t\t          **  WELCOME TO OUR CLUB  **                "<<endl;
cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;

        int choice;
        cout<<"\t1.LOGIN\n\n";
        cout<<"\t2.REGISTER\n\n";
        cout<<"\t3.FORGOT PASSWORD OR USERNAME\n\n";
        cout<<"\t4.Exit\n\n";
        cout<<"\tEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"\t THANNKS FOR PLAYING THE GAME\nThis program is created by @VISHAV @IZRAIL\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"\t Wrong Choice Intered\n"<<endl;
                        main();

        }
}
void calc_func()
{
cout<<"\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
cout<<"\t\t\t          **  WELCOME TO BLACKJACK GAME  **                "<<endl;
cout<<"\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
int total;char f;
cout<<"\t Deposit the total Money you want to play: ";
while(1)
{
cin>>total;
if(total<=0)
    cout<<"\t SORRY, you can't play without money\n\tPlease enter valid amount: ";
    else
        break;
}
system("cls");
cin.get();
while(1)
{
  cout<<"\tEnter the amount to start with : ";
  int mny;char mn;
 while(1)
 {
  cin>>mny;

  if(mny>total)
  {
    cout<<"\tYou can't play with more then your total Money to play or Please enter  valid money: ";
  }
  else if(mny<=0)
  {
      cout<<"\tyou cant play with 0 money \n Enter a valid amount:";
  }
  else
    break;
 }
 cin.get();
 cout<<endl;
cout<<"\tPress Enter to Generate your 1st 2 cards\t"<<endl;
cin.get();
int p_sum=0,d_sum=0;
srand(time(NULL));
int p_card1=rand()%11+1;
int p_card2=rand()%11+1;
//int card3,card4,card5;
p_sum=p_card1+p_card2;
cout<<"\tYour 1st card is: "<<p_card1<<endl<<" \tYour 2nd card is: "<<p_card2<<endl;
cout<<"\t Total value of your cards is: "<<p_sum<<endl<<endl;
cout<<"\t* * * * * * * * * Now it's MY turn * * * * * * * * * * *"<<endl<<endl;
int d_card1=rand()%11+1;
int d_card2=rand()%11+1;
d_sum+=d_card1;
cout<<"\tdealer's 1st card is "<<d_card1<<endl;
cout<<"\tdealer's Have total value of cards is: "<<d_sum<<endl;
cout<<"\t(note that dealer have also a 2nd card which is not seen now)\n\n";
int ins=0;
if(d_sum==11)
{
    cout<<"\t Would you like to take insurance\n1.yes\n2.No"<<endl;
    int a;cin>>a;
    if(a==1)
    {
       ins=1;
    }
}
bool j= check(p_sum,d_sum,0,total,mny,ins);
bool k=0;
if(j!=1)
{
int s=0;
while(s!=2 && k!=1)
{
cout<<"\t1.Hit\n\t2.stay"<<endl;
cout<<"\tselect your choice :";
cin>>s;
 if(s==1)
 {   system("cls");
    int p_card3=rand()%11+1;
      p_sum+=p_card3;
      cout<<"\tyour total card value is: "<<p_sum<<endl;
      cout<<"\tDealer's total card value is: "<<d_sum<<endl;
     k=check(p_sum,d_sum,1,total,mny,ins);
 }
 else if(s!=2)
    cout<<"invalid selection"<<endl;
}
if(k!=1)
{
cout<<"\t***************NOW DEALER'S TURN**************"<<endl;
d_sum+=d_card2;
cout<<"DEALER HAVE TOTAL CARD VALUE IS :"<<d_sum<<endl;
k=check(p_sum,d_sum,4,total,mny,ins);
while(k!=1)
{
    int d_card3=rand()%11+1;
    cout<<"\tDEALER TAKE "<<d_card3<<" CARD VALUE"<<endl;
    d_sum+=d_card3;
    cout<<"\tNOW DEALER HAVE TOTAL CARD VALUE IS: "<<d_sum<<endl;
    k=check(p_sum,d_sum,2,total,mny,ins);
    if(k==1) break;
}
}
}
if(total<=0)
{
    cout<<"\tYOU HAVE LOST YOUR ALL MONEY\n\n";
    cout<<"\tTHANKS FOR PLAYING THE GAME SEE YOU SOON"<<endl;
    return;
}
cout<<"\t 1.PRESS ANY KEY TO PLAY AGAIN\n\t2.PRESS 2 TO EXIT"<<endl;
char x;cin>>x;
if((int)x-'0'==2)
{
    cout<<"THANKS FOR PLAYING THE GAME SEE YOU SOON"<<endl;
    break;
}
cin.get();
}
}

#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>

using namespace std;

void encrypt(int a[],char str[],int n)
{

    unsigned int i,j;


    for(i=1;i<=n;i++)
    {
	for(j=0;j<strlen(str);j++)
	{
	    if((j+1)%2==0)
	    {
		if(((str[j]-a[i])<97 && (str[j]-a[i])>90))
		    str[j]=(char)122-(a[i]-(str[j]-97)-1);
		else if((str[j]-a[i])<65)
		    str[j]=(char)90-(a[i]-(str[j]-65)-1);
		else
		    str[j]=str[j]-a[i];


	    }
	    if((j+1)%2!=0)
	    {
		if((str[j]+a[i])>122)
		    str[j]=(char)97+(a[i]-(122-str[j])-1);
		else if((str[j]+a[i])>90 && (str[j]+a[i])<97 )
		    str[j]=(char)65+(a[i]-(90-str[j])-1);
		else
		    str[j]=str[j]+a[i];

	    }
	}

    }

    cout<<"\nencrypted message is= "<<str;
}


void decrypt(int a[],char str[],int n,char password[])
{
    unsigned int i,j;
	int l,k=0;
    char pass[20],message[100];
    for(i=1;i<=n;i++)
    {
	for(j=0;j<strlen(str);j++)
	{
	    if((j+1)%2!=0)
	    {
		if(((str[j]-a[i])<97 && (str[j]-a[i])>90))
		    str[j]=(char)122-(a[i]-(str[j]-97)-1);
		else if((str[j]-a[i])<65)
		    str[j]=(char)90-(a[i]-(str[j]-65)-1);
		else
		    str[j]=str[j]-a[i];


	    }
	    if((j+1)%2==0)
	    {
		if((str[j]+a[i])>122)
		    str[j]=(char)97+(a[i]-(122-str[j])-1);
		else if((str[j]+a[i])>90 && (str[j]+a[i])<97 )
		    str[j]=(char)65+(a[i]-(90-str[j])-1);
		else
		    str[j]=str[j]+a[i];
	    }
	}


    }
	l=strlen(str)-n;
	for(i=l;i<strlen(str);i++)
	{
	    pass[k++]=str[i];
	}
	pass[k]='\0';
		k=0;
	if(strcmp(password,pass)==0)
	{
	    for(i=0;i<strlen(str)-n;i++)
		message[k++]=str[i];
		message[k]='\0';
	    cout<<"\ndecrypted message is="<<strrev(message);
	    strcpy(str,message);
	}
	else
	{
	    cout<<"\nWrong Password";

	}

}

void fibonacci(int n,int a[])
{
    int first = 0, second = 1, next, c,i=0;
    for ( c = 0 ; c <= n ; c++ )
   {
      if ( c <= 1 )
      next = c;
      else
      {
	  next = first + second;
	  first = second;
	  second = next;
      }
      a[i++]=next;
   }


}

int main()
{
    x:
    char rev[120], password[20],str[100],fullstring[120];
    int i,x,n,a[20];
    fstream f,f1,f2,f3;
    char ch;

    cout<<"Enter choice \n1.Encryption\n2.Decryption ";
    cin>> n;
    if(n==1)
    {
	cout<<"Enter password key (upto 5 characters) :";
	cin>>password;
    string filename1;
	fibonacci(strlen(password),a);
    cout<<"Enter the file name to be encrypted : ";
    cin>>filename1;
    filename1 = filename1 + ".txt";
	f.open(filename1.c_str(),ios::in);
	f1.open("Encr.txt",ios::out);

	if(!f)
	{
	cout<<"Sorry,file does not exist";
	return 1;
	}


	while(f>>str)
	{
	cout<<str<<" "<<"here";

    x=strlen(str)-1;
	    i=0;
    while(x>=0)
    rev[i++]=str[x--];
    rev[i]='\0';


    strcpy(fullstring,rev);
    strcat(fullstring,password);

    encrypt(a,fullstring,strlen(password));
	f1<<fullstring;
	f1<<" ";
	}


    f.close();
    f1.close();

    }

    if(n==2)
    {
    cout<<"Enter password :";
    cin>>password;
    fibonacci(strlen(password),a);


    f.open("Encr.txt",ios::in);
	f1.open("Decr.txt",ios::out);
	if(!f)
	{
	cout<<"Sorry,file does not exist";
	return 1;
	}


	while(f>>str)
	{
	cout<<str<<" ";
    decrypt(a,str,strlen(password),password);
	f1<<str;
	f1<<" ";
	}

	f.close();
	f1.close();

    }

    int choice;

    cout<<"\n\n";
    cout<<"Enter your Choice\n1.Continue\n2.Exit";
    cin>>choice;
    if(choice==1)
    goto x;
    else
    exit(0);
    return 0;
}

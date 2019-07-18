#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

char collision;
int quada,quadb;

int getprime(int lim_up)
{
	//printf("\nin primefunction");

	int n,prime=1,i,flag;

	for(n=1; n<lim_up; n++)
	{
		flag = 1;
		for(i=2; i<n; i++)
			if(n%i == 0)
			{
				flag = 0;
				break;
			}
		if(flag==1)
			prime=n;
	}

	//printf("\nprime=%d",prime);
	return prime ;

}


int* maketable(int m)
{
	//printf("\nin maketable function");
	int* hashtable=(int*)malloc(m*m*sizeof(int));
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			*(hashtable+(i*m)+j)=INT_MAX;

	return hashtable;
}


void print(int* hashtable,int m,FILE* out)
{
	//printf("\nin print function");

	int i=0,j=0;


	for(i=0;i<m;i++)
	{	
		fprintf(out,"%d (",i);
		for(j=0;j<m;j++)
		{
			if(*(hashtable+i*m+j)==INT_MAX || *(hashtable+i*m+j)==INT_MIN)
				continue;

			fprintf(out,"%d,",*(hashtable+i*m+j)); 

		}
		fprintf(out,")\n");

	}
}


int search(int* hashtable,int k,int size)
{

	//printf("\nin search function%d",size);

	int index,i=0,j=0,temp,prime;
	index=k%size;
	int hindex=index;
	int flag=0;
	
	/*
	   flag 0=not found
	   flag 1=deleted successfully*/

	//if(*(hashtable+index*size+j)==NULL||*(hashtable+index*size+j)==INT_MIN)

	i=1;
	while(*(hashtable+(index*size)+j)!=INT_MAX&& flag!=1)
	{

		if(*(hashtable+(index*size)+j)==k)
		{
			flag=1;
		}


		switch(collision)
		{
			case'a'://printf("%d",*(hashtable+(index*size)+j));
					//printf("\nhere in a");
					index=(hindex+i)%size;
					//printf("\nindex=%d",index);
					break;

			case'b'://printf("\nhere in b");
					index=(hindex+quada*i+quadb*i*i)%size;
					break;

			case'c'://printf("\nhere in c");
					prime=getprime(size);
					temp=prime-(k%prime);
					index=(hindex+(i*temp))%size;	
					break;

			case'd'://printf("\nhere in d");
					j++;

					break;



		};

		i++;
	}	

	return flag;

}


void delete(int* hashtable,int k,int size)
{

	//printf("\nin delete function");

	int index,i=0,j=0,temp,prime;
	index=k%size;
	int flag=0;
	int hindex= index;
	/*
	   flag 0=not found
	   flag 1=deleted successfully*/

	//if(*(hashtable+index*size+j)==NULL||*(hashtable+index*size+j)==INT_MIN)

	i=1;
	while(*(hashtable+index*size+j)!=INT_MAX)
	{

		if(*(hashtable+index*size+j)==k)
		{
			flag=1;
			*(hashtable+index*size+j)=INT_MIN;
		}

		switch(collision)
		{
			case'a'://printf("\nhere in a");
					index=(hindex+i)%size;
					break;

			case'b'://printf("\nhere in b");
					index=(hindex+quada*i+quadb*i*i)%size;
					break;

			case'c'://printf("\nhere in c");
					prime=getprime(size);
					temp=prime-(k%prime);
					index=(hindex+(i*temp))%size;	
					break;

			case'd'://printf("\nhere in d");
					j++;

					break;



		};

		i++;
	}	
}

int* insert(int* hashtable,int k,int size)
{
	//printf("\nin insert function");

	int index,i=0,j=0,temp,prime;
	index= k%size;
	int hindex=index;


	//if(*(hashtable+index*size+j)==NULL||*(hashtable+index*size+j)==INT_MIN)

	i=1;
	while(*(hashtable+index*size+j)!=INT_MAX&& i<=size)
	{

		switch(collision)
		{
			case'a'://printf("\nhere in a");
					index=(hindex+i)%size;
					break;

			case'b'://printf("\nhere in b,%d,",index);
					index=(hindex+(quada*i)+(quadb*i*i))%size;
					break;

			case'c'://printf("\nhere in c");
					prime =getprime(size);
					temp=prime-(k%prime);
					index=(hindex+(i*temp))%size;	
					break;

			case'd'://printf("\nhere in d");
					j++;

					break;



		};

		i++;
	}

	//printf("\nkey=%d",k);

	*(hashtable+index*size+j)=k;

	return hashtable;

}

int getdigits(char* str)
{
	//printf("\nin getdigits function");

	//printf("\n%lu",strlen(str));

	int i,m=0;

	for(i=0;i<(strlen(str)-1);i++)
		m=(str[i]-'0')+(10*m);

	return m;
}

int main()
{
	int* hashtable;
	hashtable=(int*)malloc(sizeof(int)*10*10);
	int m,size=0,i,j,flagd=0;
	FILE* in;
	in=fopen("input.txt","r");
	
	FILE* out=fopen("output.txt","w");

	if(in==NULL)
	{
		printf("\nFile doesn't exist");
		exit(0);
	}

	char ch[100],digits[100];

	while(fgets(ch,99,in)!=NULL)
	{
		switch(ch[0])
		{
			case'a':flagd=1;
					collision='a';
					fgets(ch,99,in);
					size=getdigits(ch);
					//printf("\n%d",size);
					//printf("\n%s",ch);
					hashtable=maketable(size);
					break;

			case'b':
					flagd=1;
					fgets(ch,99,in);
					size=getdigits(ch);
					hashtable=maketable(size);

					collision='b';
					fgets(ch,99,in);
					printf("%s",ch);
					for(i=0;ch[i]!=' '&&ch[i]!='\n';i++)
						digits[i]=ch[i];

					digits[i]='\n';
					digits[i+1]='\0';

					i++;
	
					quada=getdigits(digits);

					for(j=0;ch[i]!='\n'&&ch[i]!=' ';i++,j++)
						digits[j]=ch[i];

					digits[j]='\n';
					digits[j+1]='\0';

					quadb=getdigits(digits);

					//printf("\nquada=%d,quadb=%d",quada,quadb);
					break;

			case'c':flagd=1;
					fgets(ch,99,in);
					size=getdigits(ch);
					hashtable=maketable(size);
					collision='c';
					break;

			case'd':if(flagd==0)
					{
						flagd=1;
						fgets(ch,99,in);
						size=getdigits(ch);
						hashtable=maketable(size);
						collision='d';
					}
					else
					{
						for(i=2,j=0;ch[i]!='\0';i++,j++)
							digits[j]=ch[i];

						digits[j]='\0';
						m=getdigits(digits);
						delete(hashtable,m,size);
					}

					break;

			case'i':for(i=2,j=0;ch[i]!='\0';i++,j++)
						digits[j]=ch[i];

					digits[j]='\0';
					//printf("\n%s",digits);
					m=getdigits(digits);
					//printf("%d",m);
					//printf("%dsize",size);
					hashtable=insert(hashtable,m,size);

					break;

			case's':for(i=2,j=0;ch[i]!='\0';i++,j++)
						digits[j]=ch[i];

					digits[j]='\0';
					m=getdigits(digits);
					
					//printf("\n%d",m);

					if(search(hashtable,m,size))
						fprintf(out,"1\n");
					else
						fprintf(out,"-1\n");
					break;

			case'p':print(hashtable,size,out);
					break;

			case't':exit(0);

			default:
					printf("not a proper entry");
					break;
		};


	}
}

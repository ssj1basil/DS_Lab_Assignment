#include<stdio.h>
#include<stdlib.h>   
#include<ctype.h>     
#include<string.h>


char stack[1000];
int top = -1;

void push(char item)
{
	if(top >= 999)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top]=item;
	}
}

char pop()
{
	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		return stack[top--];
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return 3;
	}
	else if(symbol == '*' || symbol == '/')
	{
		return 2;
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void InfixToPostfix(char infix_exp[])
{ 
	int i=0,j=0;
	char x;
	push('(');                         
	strcat(infix_exp,")");             
	while(infix_exp[i] != '\0')        
	{
		if(infix_exp[i] == '(')
		{
			push(infix_exp[i]);
		}
		else if(isalpha(infix_exp[i]))
		{ 
			printf("%c ",infix_exp[i]);          
			j++;
		}
		else if(is_operator(infix_exp[i]) == 1)       
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(infix_exp[i]))
			{
				printf("%c ",x);                 
				j++;
				x = pop();                      
			}
			push(x);
		
			push(infix_exp[i]);                 
		}
		else if(infix_exp[i] == ')')        
		{
			x = pop();                  
			while(x != '(')                
			{
				printf("%c ",x); 
				j++;
				x = pop();
			}
		}
		else if(infix_exp[i]==' ')
		{
			i++;
			continue;
		}	
		else
		{ 
	
			printf("\ninvalid.\n");      
			getchar();
			exit(1);
		}
		i++; 
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		return;
	}
}

int main()
{
	FILE*fp=fopen("input.txt","r");
	FILE*ptr=fopen("input.txt","r");
	FILE*fw=fopen("input.txt","r");
	FILE*ft=fopen("out.txt","w");
	char infix[1000],ch;
	int no_of_lines=0,count=0;       
	while(!feof(fw))
    {
    	if(fgetc(fw)=='\n')
    	{
    		no_of_lines++;
    	}	
    }
	for(int i=0;i<no_of_lines;i++)
    {
    	top=-1;
    	count=0;
    	while(getc(ptr)!='\n')
    	{
  		  	count++;
    	}	
		fgets(infix,count+1,fp);
		ch=fgetc(fp);
		InfixToPostfix(infix);
		printf("\n");             
	}	
		
	return 0;
}






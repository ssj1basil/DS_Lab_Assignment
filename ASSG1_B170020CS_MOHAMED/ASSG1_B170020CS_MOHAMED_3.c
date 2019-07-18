#include<stdio.h>
 #include<ctype.h>
 # define MAXSTACK 100        
 # define POSTFIXSIZE 100     
FILE * f1,*f2;
 int stack[MAXSTACK];
 int top = -1 ;
 int pop()
 {
     int item;
     if(top <0)
     {
        
     }
     else
     {
         item = stack[top];
         top = top - 1;
         return item;
     }
 }
void push(int item)
 {
     if(top >= MAXSTACK -1)
     {
         printf("stack over flow");
         return;
     }
     else
     {
         top = top + 1 ;
         stack[top]= item;
     }
 }

 
 void EvalPostfix(char postfix[])
 {

    int i ;
    char ch;
    int val;
    int A, B ;
    for (i = 0 ; postfix[i] != '\n'; i++)
    {
        ch = postfix[i];
        int num;
        if(postfix[i]==' ')
         continue;
        else if (isdigit(postfix[i]))
        {
            num=0;
              while(isdigit( postfix[i]))  
            { 
            num=num*10 + (int)( postfix[i]-'0'); 
                i++; 
            } 
            i--; 
            push(num);
        }
        else
        {
            A = pop();
            B = pop();

            switch (ch) 
            {
                case '*':
                val = B * A;
                break;

                case '/':
                val = B / A;
                break;

                case '+':
                val = B + A;
                break;

                case '-':
                val = B - A;
                break;
            }

            push(val);
        }
    }
    fprintf(f2, "  %d \n", pop()) ;
 }

 int main()
 {
    int h=0;
     f1=fopen("input3.txt","r");
     f2=fopen("output3.txt","w");
    int i;
    char postfix[POSTFIXSIZE];
    while(!feof(f1))
    {   
        for (i = 0 ; i <= POSTFIXSIZE - 1 ; i++)
        {
            fscanf(f1,"%c", &postfix[i]);
            if ( postfix[i] == '\n' ) 
            { break; } 
        }
        EvalPostfix(postfix);   
    }
 }

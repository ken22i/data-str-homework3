#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct MyStack{
	int top;           //���|����
	char a[MAX];       //���|�D��
	
	bool IsEmpty();    //�P�_���|�O�_���šA�O�h�^��1�A�_�h0
	bool IsFull();     //�P�_���|�O�_�����A�O�h�^��1�A�_�h0
	void Push(char);   //�N�@�Ӧr���Ƕi���|��
	char Pop();        //�N�@�Ӧr���q���|�����X�æ^��
	MyStack()		   //�غc�l
	{
		top = -1;
	}
}; 

bool CheckQuote(char*);
char* es(char*);
void reverseString(char*, int, int);
//==========================================
int main(){
	MyStack S1;
	char a[MAX];
	char b[MAX];
	FILE* fptr;
	FILE* wptr;
	fptr=fopen("input.txt","r");
	wptr=fopen("out.txt","w");
	while(!feof(fptr)){
		//fscanf(fptr,"%[^\n]\n",a);
		fgets(a,100,fptr);
		printf("%s\n",a);
		fprintf(wptr,"%s\n",es(a));
	}
	fclose(fptr);
	fclose(wptr);

		
}
//=========================================
bool MyStack::IsEmpty()
{
	if(top==-1)
		return true;
		
	else
		return false;
	
}
//=========================================
bool MyStack::IsFull()
{
	if(top==MAX-1)		
		return true;
	else
		return false;
}
//=========================================
void MyStack::Push(char ch)
{
	if(IsFull())
	{
		printf("The stack is Full! Cannot push!\n");
	}
	else
	{
		top++;
		a[top]=ch;
	}
}
//=========================================
char MyStack::Pop()
{
	char ch;
	if(IsEmpty())
	{
		printf("The stack is Empty! Cannot pop!\n");
		return 0;
	}
	else
	{
		ch=a[top];
		top--;
		return ch;	
	}	
}

bool CheckQuote(char *s)
{
	MyStack S;
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			S.Push(s[i]);
		}
		else
		{
			if(S.IsEmpty())
			{
				return false;
			}
			else
			{		
				if(s[i]==')')
				{
					if(S.Pop()!='(')
						return false; 
				}
				else if(s[i]==']')
				{
					if(S.Pop()!='[')
						return false; 
				}
				else
				{
					if(S.Pop()!='{')
						return false; 
				}
			}
		}
		i++;
	}
	if(!S.IsEmpty())
		return false;
	else
		return true;
}
char* es(char* str){
	MyStack s1;
	char result[MAX];
	char tem;
	int i=0,j=0,len,ecnt=0;
	len=strlen(str);
	while(i!=len){
		s1.Push(str[i]);
		
		if(str[i]=='e'){
			ecnt++;
		}
		else if(ecnt>0){
			ecnt++;
		}
		if(str[i]=='s'&&ecnt>0){
			do{
				ecnt--;
			}while(s1.Pop()!='e');


		}
		i++;
		
	}
	
	while(!s1.IsEmpty()){
		result[j]=s1.Pop();
		j++;
		
	}
	reverseString(result,0,strlen(result)-1);
	return result;
}
void reverseString(char* s, int from, int to){

    char t;
    while(from < to){

        t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }

}
    


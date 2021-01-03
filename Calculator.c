#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	printf("enter + for Addtion\n - for subtraction\n * for multiplication\n / for division");
	scanf("%d %d",&a,&b);
	fflush (stdin);
	scanf("%c",&ch);
	switch(ch)
	{
		case '+' :
			printf("Addition of two values if:%d",a+b);
			break;
		case '-' :
			printf("Subtraction of values if:%d",a-b);
			break;
		case '*':
			printf("Multiplaction of values is:%d",a*b);
			break;
		case '/':
			printf("Division of number is:%f",(float)a/b);
			break;
		default :
			printf("enter given number only");
			

}
}

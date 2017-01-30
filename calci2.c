#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define PI 3.14159265
struct cmplx{
  float real;
  float im;
  float mod;
  float arg;
};
float det(struct cmplx p);
int bin_dec(int num);
int bin(int n);
float eval(char exp[]);
int testNum(char c);
int main()
{
  float n,i,sum=0,a,b,prod=1,m,ang,an,ans;
  int mode,cmplxmode,r,c,r1,c1,matmode,d,u,v,w,basemod,angmode,flag=0;
  float **A,**B,**C;
  char exp[50];
  struct cmplx p,q,add;
   char op;
  while(1){
    printf("Enter the mode:\n1.simple calculations\t2.complex numbers\n3.matrices\t4.Decimal-binary-hexadecimal conversion\n5.trigonometric\t6.inverse trigonometric\t7.hyperbolic\n8.logarithmic\t9.exit\n\n");
    scanf("%d",&mode);
    switch(mode){
    case 1:printf("Enter the expression(without spaces): ");
      scanf("%s",exp);
      ans = eval(exp);
      printf("Answer = %f\n",ans);
      break;
      /*case 1: printf("Enter the operation you want to perform: '+','-','*','/','%','^'\n");
      getchar();
      scanf("%c",&op);
      switch(op){
      case '+': printf("Enter the number of operands: ");
	scanf("%f",&n);
	printf("Enter the operands\n");
	for(i=0;i<n;i++){
	  scanf("%f",&m);
	  sum+=m;
	}
	printf("sum=%f",sum);
      break;
      case '-':printf("Enter the operand 1 and operand 2: ");
       	scanf("%f%f",&a,&b);
	printf("Difference = %f\n",a-b);
	break;
      case '*':printf("Enter the number of operands: ");
	scanf("%f",&n);
	printf("Enter the operands\n");
	for(i=0;i<n;i++){
	  scanf("%f",&m);
	  prod*=m;
	}
	printf("product = %f",prod);
	break;
      case '/':printf("Enter numerator and denominator: ");
	scanf("%f%f",&a,&b);
	printf("result = %f\n",a/b);
	break;
      case '%':printf("Enter the numerator and denominator: ");
	scanf("%d%d",&c,&d);
	printf("Reminder = %d\n",c%d);
	break;
      case '^':printf("Enter the base and power: ");
	scanf("%f%f",&a,&b);
	printf("a^b = %f",pow(a,b));
	break;
      }
      break;*/
    case 2:printf("Enter the operation number:\n");
      printf("1.addition\t2.subtraction\t3.multiplication\t4.division\n5.modulus\t6.argument\n");
      scanf("%d",&cmplxmode);
      switch(cmplxmode){
      case 1:printf("Enter the number of complex numbers to add: ");
	scanf("%f",&n);
	add.real=add.im=0;
	for(i=0;i<n;i++){
	  printf("Enter the real and imaginery part of the element %d: ",(int)i+1);
	  scanf("%f%f",&p.real,&p.im);
	  add.real+=p.real;
	  add.im+=p.im;
	}
	printf("The sum = (%f) + (%f)i",add.real,add.im);
	break;
      case 2:printf("Enter the real and imaginery parts of first number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Enter the real and imaginery parts of second number\n");
	scanf("%f%f",&q.real,&q.im);
	printf("The difference = (%f) + (%f)i\n",p.real-q.real,p.im-q.im);
	break;
      case 3:printf("Enter the real and imaginery parts of first number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Enter the real and imaginery parts of second number\n");
	scanf("%f%f",&q.real,&q.im);
	printf("The product = (%f) + (%f)i\n",(p.real*q.real-p.im*q.im),(p.real*q.im+p.im*q.real));
	break;
      case 4:printf("Enter the real and imaginery parts of first number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Enter the real and imaginery parts of second number\n");
	scanf("%f%f",&q.real,&q.im);
	printf("The result of division = (%f)+(%f)i",(p.real*q.real+p.im*q.im)/(det(q)*det(q)),(p.im*q.real-p.real*q.im)/(det(q)*det(q)));
	break;
      case 5:printf("Enter the real and imaginery parts of the complex number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Modulus = %f",det(p));
	break;
      case 6:printf("Enter the real and imaginery parts of the complex number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Argument = %f",atan(p.im/p.real)*180.0/PI);
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 3:printf("Enter operation number to be performed:\n");
      printf("1.addition\t2.subtraction\t3.multiplication\t4.transpose\n");
      scanf("%d",&matmode);
      switch(matmode){
      case 1:printf("Enter the number of rows and columns of the matrices: ");
	scanf("%d%d",&r,&c);
	A=(float**)calloc(r,sizeof(float*));
	B=(float**)calloc(r,sizeof(float*));
	for(u=0;u<r;u++){
	  A[u]=(float*)calloc(c,sizeof(float));
	  B[u]=(float*)calloc(c,sizeof(float));
	}
	printf("Enter the values of the first matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&A[u][v]);
	  }
	}
	printf("Enter the values of the second matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&B[u][v]);
	  }
	}
	printf("The sum is:");
	for(u=0;u<r;u++){
	  printf("\n");
	  for(v=0;v<c;v++){
	    printf("%f\t",A[u][v]+B[u][v]);
	  }
	}
	free(A);
	free(B);
	break;
      case 2:printf("Enter the number of rows and columns of the matrices: ");
	scanf("%d%d",&r,&c);
	A=(float**)calloc(r,sizeof(float*));
	B=(float**)calloc(r,sizeof(float*));
	for(u=0;u<r;u++){
	  A[u]=(float*)calloc(c,sizeof(float));
	  B[u]=(float*)calloc(c,sizeof(float));
	}
	printf("Enter the values of the first matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&A[u][v]);
	  }
	}
	printf("Enter the values of the second matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&B[u][v]);
	  }
	}
	printf("The difference is:");
	for(u=0;u<r;u++){
	  printf("\n");
	  for(v=0;v<c;v++){
	    printf("%f\t",A[u][v]-B[u][v]);
	  }
	}
	free(A);
	free(B);
	break;
      case 3:printf("Enter the number of rows and columns of the matrices: ");
	scanf("%d%d%d%d",&r,&c,&r1,&c1);
	if(c!=r1){
	  printf("Math Error!\n");
	  break;
	}
	A=(float**)calloc(r,sizeof(float*));
	B=(float**)calloc(r1,sizeof(float*));
	C=(float**)calloc(r,sizeof(float*));
	for(u=0;u<r;u++){
	  A[u]=(float*)calloc(c,sizeof(float));
	  B[u]=(float*)calloc(c1,sizeof(float));
	  C[u]=(float*)calloc(c1,sizeof(float));
	}
	printf("Enter the values of the first matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&A[u][v]);
	  }
	}
	printf("Enter the values of the second matrix: ");
	for(u=0;u<r1;u++){
	  for(v=0;v<c1;v++){
	    scanf("%f",&B[u][v]);
	  }
	}
	for(u=0;u<r;u++){
	  for(w=0;w<c1;w++){
	    for(v=0;v<c;v++){
	      C[u][w]+=A[u][v]*B[v][w];
	    }
	  }
	}
	for(u=0;u<r;u++){
	  printf("\n");
	  for(v=0;v<c1;v++){
	    printf("%f\t",C[u][v]);
	  }
	}
	free(A);
	free(B);
	free(C);
	break;
	case 4: printf("Enter the number of rows and columns of the matrices: ");
	scanf("%d%d",&r,&c);
	A=(float**)calloc(r,sizeof(float*));
	for(u=0;u<r;u++){
	  A[u]=(float*)calloc(c,sizeof(float));
	}
	printf("Enter the values of the matrix: ");
	for(u=0;u<r;u++){
	  for(v=0;v<c;v++){
	    scanf("%f",&A[u][v]);
	  }
	}
	printf("The transpose of the matrix is:");
	for(u=0;u<c;u++){
	  printf("\n");
	  for(v=0;v<r;v++){
	    printf("%f\t",A[v][u]);
	  }
	}
	free(A);
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 4:printf("Enter input format\n");
      printf("1.decimal\t2.binary\t3.hexadecimal\n");
      scanf("%d",&basemod);
      printf("Enter number: ");
      switch(basemod){
      case 1: scanf("%d",&c);
	break;
      case 2: scanf("%d",&c);
	c=bin_dec(c);
	if(c==-1)
	  flag=-1;
	break;
      case 3:scanf("%x",&c);
      }
      if(flag==-1){
	flag=0;
	break;
      }
      printf("Enter output format\n");
      printf("1.decimal\t2.binary\t3.hexadecimal\n");
      scanf("%d",&basemod);
      switch(basemod){
      case 1: printf("Number in decimal = %d\n",c);
	break;
      case 2: printf("Number in binary = %d\n",bin(c));
	break;
      case 3: printf("Number in hexadecimal = %x\n",c);
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 5:printf("Enter the trigonometric function to be used\n");
      printf("1.sin\t2.cos\t3.tan\t4.sec\t5.cosec\t6.cot\n");
      scanf("%d",&mode);
      printf("Enter units of input:\n1.degrees2.radians\t3.gradians\n");
      scanf("%d",&angmode);
      printf("Enter the value of the angle: ");
      scanf("%f",&ang);
      an=ang;
      switch(angmode){
      case 1: ang*=PI/180;
	break;
      case 3: ang*=PI/200;
	break;
      default:printf("Invalid!\n");
      }
      switch(mode){
      case 1:printf("sin(%f) = %f\n",an,sin(ang));
	break;
      case 2:printf("cos(%f) = %f\n",an,cos(ang));
	break;
      case 3:printf("tan(%f) = %f\n",an,tan(ang));
	break;
      case 4:printf("sec(%f) = %f\n",an,1/cos(ang));
	break;
      case 5:printf("cosec(%f) = %f\n",an,1/sin(ang));
	break;
      case 6:printf("cot(%f) = %f\n",an,1/tan(ang));
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 6:printf("Enter the function to be used:\n");
      printf("1.sin inv\t2.cos inv\t3.tan inv\n4.cosec inv\t5.sec inv\t6.cot inv\n");
      scanf("%d",&mode);
      printf("Enter the input value: ");
      scanf("%f",&an);
      switch(mode){
      case 1:ang=asin(an);
	break;
      case 2:ang=acos(an);
	break;
      case 3:ang=atan(an);
	break;
      case 4:ang=asin(1/an);
	break;
      case 5:ang=acos(1/an);
	break;
      case 6:ang=atan(1/an);
	break;
      default:printf("Invalid!\n");
      }
      printf("Enter output units:\n1.degrees\t2.radians\t3.gradians\n");
      scanf("%d",&mode);
      switch(mode){
      case 1:printf("result = %f\n",ang*180/PI);
	break;
      case 2:printf("result = %f\n",ang);
	break;
      case 3:printf("result = %f\n",ang*200/PI);
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 7:printf("Enter the operation:\n1.sinh\t2.cosh\t3.tanh\t4.cosech\t5.sech\t6.coth\n");
      scanf("%d",&mode);
      printf("Enter input: ");
      scanf("%f",&ang);
      switch(mode){
      case 1: printf("sinh(%f) = %f\n",ang,sinh(ang));
	break;
      case 2:printf("cosh(%f) = %f\n",ang,cosh(ang));
	break;
      case 3:printf("tanh(%f) = %f\n",ang,tanh(ang));
	break;
      case 4: printf("cosech(%f) = %f\n",ang,1/sinh(ang));
	break;
      case 5:printf("sech(%f) = %f\n",ang,1/cosh(ang));
	break;
      case 6:printf("coth(%f) = %f\n",ang,1/tanh(ang));
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 8:printf("Enter base:\n1.e\t2.10\n");
      scanf("%d",&mode);
 
     
      switch(mode){
      case 1: printf("Enter input: ");
	scanf("%f",&ang);
	printf("ln(%f) = %f\n",ang,log(ang));
	break;
      case 2: printf("Enter input: ");
	scanf("%f",&ang);
	printf("log(%f) = %f\n",ang,log10(ang));
	break;
      default:printf("Invalid!\n");
      }
      break;
    case 9:exit(0);
    default:printf("Invalid mode\n");
    }
    printf("\n\n");
  }
  return 0;
}
float det(struct cmplx p){
  return sqrt(p.real*p.real+p.im*p.im);
}	
int bin_dec(int num)
{ 
  int dec_val = 0, base = 1, rem;
  while (num > 0)
    {
      rem = num % 10;
      if(rem!= 1 && rem!=0 ){
	printf("Invalid Input!\n");
	return -1;
      }
      dec_val = dec_val + rem * base;
      num = num / 10 ;
      base = base * 2; 
    }
  return dec_val;
}
int bin(int n)
{
  int remainder; 
  int binary = 0, i = 1;
  while(n != 0) {
    remainder = n%2;
    n = n/2;
    binary= binary + (remainder*i);
    i = i*10;
  }
  return binary;
}
int testNum(char c)
{
  if(c>=48 && c<=57)
    return 1;
  return 0;
}
int order(char c)
{
  if(c=='+' || c=='-')
    return 1;
  if(c=='*' || c=='/')
    return 2;
  if(c=='^')
    return 3;
}
float calc(int a,int b, char c)
{
  switch(c){
  case '+':return a+b;
    break;
  case '-':return a-b;
    break;
  case '*':return a*b;
    break;
  case '/':return a/b;
    break;
  case '^':return pow(a,b);
    break;
  default:printf("Invalid!\n");
  }
}
float eval(char exp[])
{
  float num[50];
  char oper[50];
  char temp[50];
  int i=0,j=0,k=0,l=0;
  char c;
  while((c=exp[i])!='\0'){
    if(testNum(exp[i])==1){
	temp[j]=c;
	j++;
	if(testNum(exp[i+1])==0){
	  sscanf(temp,"%f",&num[k]);
	  k++;
	  for(j=0;j<strlen(temp);j++){
	    temp[j]='\0';
	  }
	  j=0;
	}
      }
    else{
      while(l>0 && order(c)<=order(oper[l-1])){
	num[k-2]=calc(num[k-2],num[k-1],oper[l-1]);
	k--;
	l--;
      }
      oper[l]=c;
      l++;
    }
    i++;
  }
  while(l>0){
    num[k-2]=calc(num[k-2],num[k-1],oper[l-1]);
    k--;
    l--;
  }
  return num[0];
}
		  
      

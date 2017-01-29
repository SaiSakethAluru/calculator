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
float det(struct cmplx p){
  return sqrt(p.real*p.real+p.im*p.im);
}
int bin_dec(int num)
{
  int binary_val, decimal_val = 0, base = 1, rem;
  binary_val = num;
  while (num > 0)
    {
      rem = num % 10;
      decimal_val = decimal_val + rem * base;
      num = num / 10 ;
      base = base * 2; 
    }
  return decimal_val;
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
int main()
{
  float n,i,sum=0,a,b,prod=1,m;
  int mode,cmplxmode,r,c,r1,c1,matmode,d,u,v,w,basemod;
  float **A,**B,**C;
  struct cmplx p,q,add;
   char op;
  while(1){
    printf("Enter the mode:\n1.simple calculations\t2.complex numbers\n3.matrices\t4.base-n conversion\t5.exit\n");
    scanf("%d",&mode);
    switch(mode){
    case 1: printf("Enter the operation you want to perform: '+','-','*','/','%'\n");
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
      }
      break;
    case 2:printf("Enter the operation number: ");
      printf("1.addition\t2.subtraction\t3.multiplication\t4.division\n5.modulus\t6.argument\n");
      scanf("%d",&cmplxmode);
      switch(cmplxmode){
      case 1:printf("Enter the number of complex numbers to add: ");
	scanf("%f",&n);
	printf("Enter the real and imaginery parts of the numbers one by one:\n");
	add.real=add.im=0;
	for(i=0;i<n;i++){
	  scanf("%f%f",&p.real,&p.im);
	  add.real+=p.real;
	  add.im+=p.im;
	}
	printf("The sum = %f + %fi",add.real,add.im);
	break;
      case 2:printf("Enter the real and imaginery parts of first and second numbers\n");
	scanf("%f%f%f%f",&p.real,&p.im,&q.real,&q.im);
	printf("The difference = %f + %fi\n",p.real-q.real,p.im-q.im);
	break;
      case 3:printf("Enter the real and imaginery parts of first and second numbers\n");
	scanf("%f%f%f%f",&p.real,&p.im,&q.real,&q.im);
	printf("The product = %f + %fi\n",(p.real*q.real-p.im*q.im),(p.real*q.im+p.im*q.real));
	break;
      case 4:printf("Enter the real and imaginery parts of first and second numbers\n");
	scanf("%f%f%f%f",&p.real,&p.im,&q.real,&q.im);
	printf("The result of division = %f+%fi",(p.real*q.real+p.im*q.im)/det(q),(p.im*q.real-p.real*q.im)/det(q));
	break;
      case 5:printf("Enter the real and imaginery parts of the complex numbers\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Modulus = %f",det(p));
	break;
      case 6:printf("Enter the real and imaginery parts of the complex number\n");
	scanf("%f%f",&p.real,&p.im);
	printf("Argument = %f",atan(p.im/p.real)*180.0/PI);
	break;
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
      }
    case 4:printf("Enter input format\n");
      printf("1.decimal\t2.binary\t3.hexadecimal\n");
      scanf("%d",&basemod);
      printf("Enter number: ");
      switch(basemod){
      case 1: scanf("%d",&c);
	break;
      case 2: scanf("%d",&c);
	c=bin_dec(c);
	break;
      case 3:scanf("%x",&c);
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
      }
      break;
    case 5:exit(0);
    }
    printf("\n\n");
  }
  return 0;
}
	

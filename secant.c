#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double function(double x);

int main(int argc, char* argv[]){


int kmax,i=1;
double y,y0,y1, m, newx,first,second, x0, x1, epsilon;

if(argc>1){
x0=atof(argv[1]);
x1=atof(argv[2]);
epsilon=atof(argv[3]);
kmax=atoi(argv[4]);
}

else{
fprintf(stderr,"Error: specify (1) first guess, (2) second guess, \
(3) stopping threshold, and (4) a maximum number of iterations\n");
return 1;
}

y0=function(x0);
y1=function(x1);

while(fabs(0-y1)>epsilon && i<kmax)
{

//printf("y1=%f\n",y1);
m=(y1-y0)/(x1-x0);
//printf("m=%f\n",m);
newx=(x1-(function(x1)*(1/m)));
x0=x1;
x1=newx;
y0=function(x0);
y1=function(x1);
i++;
printf("iteration %d: x=%f,  error=%f\n",i,x0,fabs(y1));
}




return 0;
}



double function(double x){
double xnew;
xnew=((x*x)-576);
return xnew;}


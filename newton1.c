#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double function(double x);

int main(int argc, char* argv[]){


int kmax,i=0;
double y,y0,y1, m, newx,first,second, x0, x1, epsilon;

if(argc>1){
x0=atof(argv[1]);
epsilon=atof(argv[2]);
kmax=atoi(argv[3]);
}

else{
fprintf(stderr,"Error: specify (1) first guess, (2) stopping threshold,\
and (4) a maximum number of iterations\n");
return 1;
}

y0=function(x0);

while(fabs(0-y0)>epsilon && i<kmax)
{
m=2*x0;
newx=((m*x0)-(y0))/(m);
x0=newx;
y0=function(x0);
printf("iteration %d: x=%f,  error=%f\n",i,x0,fabs(y0));
i++;
}




return 0;
}



double function(double x){
double xnew;
xnew=((x*x)-31);
return xnew;}


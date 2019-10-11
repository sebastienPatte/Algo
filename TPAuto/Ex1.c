#include <stdio.h>
#include <stdlib.h>
/*************************************************/
/*                                               */
/*              sucre syntaxique               	 */
/*                      						 */
/*************************************************/
#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !


int fact(int val)
{
	if(val == 0)
		return 1;
	else
		return val*fact(val-1);
}

double e()
{
	double res = 0;
	int n = 15;
	for(int i=0; i<n; i++)
	{
		res+=(1.0/fact(i));

	}
	return res;
}

float Puissance(float x, int n)
{
	float res=1;
	for (int i = 0; i < n; ++i)
	{
		res*=x;
	}
	return res;
}

double Ackermann(double m,double n)
{
	if(m == 0)
	{
		return n+1;
	}else{
		if(m>0)
		{
			if(n==0)
			{
				return Ackermann(m-1,1);
			}else{
				return Ackermann(m-1,Ackermann(m,n-1));
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n=10;
	printf("e = %lf\n",e());
	printf("Puissance(1.1,10) : %lf\n",Puissance(1.1,10));
	printf("Puissance(1.001,1000) : %lf\n",Puissance(1.001,1000));
	printf("Puissance(1+Puissance(10,-6),Puissance(10,6)) : %lf\n",Puissance(1+Puissance(10,-6),Puissance(10,6)));
	printf("Puissance(1+Puissance(10,-9),Puissance(10,9)) : %lf\n",Puissance(1+Puissance(10,-9),Puissance(10,9)));
	printf("Ackermann(1,n) : %lf\n",Ackermann(1,n));
	printf("Ackermann(2,n) : %lf\n",Ackermann(2,n));
	printf("Ackermann(3,n) : %lf\n",Ackermann(3,n));
//	printf("Ackermann(4,n) : %lf\n",Ackermann(4,n));
	return 0;
}
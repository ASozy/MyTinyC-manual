#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int n = 0, i = 0;
	unsigned int msk = 1;
	
	while( 1 )  // infinite loop
	{
		printf("\n\nInput integer number or 0 to stop: ");
		scanf("%d", &n);

		if( n == 0 ) break;
		
		for( 
		       i = 0, msk = 1 << sizeof(int)*8-1, printf("BinRep: "); // start actions
			   i < sizeof(int)*8;                                     // continue?
			   msk >>= 1, i++                                         // next step 
			)
		{
	    	if( i%4 == 0 ) printf(" ");
			printf("%d", ((n & msk) == 0? 0 : 1));
		}
	}	
	return(0);	
}
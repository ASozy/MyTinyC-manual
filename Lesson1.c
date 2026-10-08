#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//--------------------------------------------------------
int main(int argc, char *argv[])
//void main(void)
{
	printf("Приложение: %s\n\n", argv[0]);

    // объявление переменных 
	int a, b; 
	char c;
	float f;
	
	printf("Test 1\n");  
	a = 1; b = 2; c = 'A'; f = 0.5;  // начальные значения
	a += b*b + a*a; 
	b = 10*f/5*a; 
	c += a; 
	f = a/(b+1)*10.;
	printf("\ta=%d b=%d c=%c f=%f\n", a, b, c, f); // вывод int, int, char и float
    getch();  // ждем нажатия любой клавиши
    
	printf("Test 2\n");
	a = 1; b = 2; c = 'A'; f = 0.5; 
	a = 'C' - c; 
	b *= 43%(a+b); 
	c += f * 3; 
	f *= 1/a;
	printf("\ta=%d b=%d c=%c f=%f\n", a, b, c, f);
    getch();
	
	printf("Test 3\n");
	a = 1; b = 2; c = 'A'; f = 0.5; 
	a = c; 
	b*=b; 
	c -= ('A'-'a'); 
	f *= 1./a;
	printf("\ta=%d b=%d c=%c f=%f\n", a, b, c, f);
    getch();
	
	printf("Test 4\n");
	a = 1; b = 2; c = 'A'; f = 0.5;
	a = b + b--; 
	c = 48; 
	f *= (a * (b+=5) * f);
	printf("\ta=%d b=%d c=%c f=%f\n", a, b, c, f);
    getch();

	printf("Test 5\n");
	a = 1; b = 2; c = 'A'; f = 0.5;
	a = (b = f*2) + 5; 
	b = a++ * ++a;
	c = '\0'; 
	f *= sin(M_PI/2);
	printf("\ta=%d b=%d c=%c f=%f\n", a, b, c, f);
	
	return 0;
}
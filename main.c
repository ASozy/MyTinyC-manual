#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------
void CapToLowVV1(char *s)
{   // with "sliding pointer" p
	char *p;
	printf("in 1: %s\n", s);
	for (*p = s; *p != '\0'; p++)
	{
		if (*p >= 'A' && *p <= 'Z') *p = (*p - 'A' + 'a');
		else if (*p >= 'a' && *p <= 'z') *p = (*p - 'a' + 'A');
	}
	return;
}

//---------------------------------------------------------------
void CapToLowVV2(char *s)
{   // string as array - use index
	int i;
	printf("in 2: %s\n", s);
	for ( i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = '0';  // 'A' - 'a';
		else if (s[i] >= 'a' && s[i] <= 'z') s[i] = '1'; // 'A' - 'a';
	}
	return;
}




//---------------------------------------------------------------
int main(void)
{
	char *s;
	s = "ABC-abc";
	printf("orig: %s\n", s);
	CapToLowVV1(s);
	printf("var 1: %s\n", s);

	s = "ABC-abc";
	CapToLowVV2(s);
	printf("var 2: %s\n", s);


	return 0;
}

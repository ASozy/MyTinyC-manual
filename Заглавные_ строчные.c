#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------
void CapToLowVV1(char *s)
{   // with "sliding pointer" p
	char *p;
	for(p = s; *p != '\0'; p++)
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
	for( i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= 'A' - 'a';
		else if (s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
	}
	return;
}

//---------------------------------------------------------------
char *CapToLowVV3(char *s)
{   // use copy, s doesn’t change
	int i;
	char *s1 = malloc(sizeof(s));
	for( i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s1[i] = s[i] - ('A' - 'a');
		else if (s[i] >= 'a' && s[i] <= 'z') s1[i] = s[i] + ('A' - 'a');
		else s1[i] = s[i];
	}
	return(s1);
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

	s = "ABC-abc";
	printf("var 3: %s -> %s\n", s, CapToLowVV3(s));

	getch(); // wait for any key pressed

	return 0;
}

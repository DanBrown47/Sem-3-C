#include<stdio.h>
#include<string.h>

void main()
{
	int str_length,pattern_length,j,i,count=0;
	char str[30],pattern[30];
	printf("\n Enter a string \t");
	scanf("%s",str);
	printf(" Enter a pattern to match\t");
	scanf("%s",pattern);

	str_length = strlen(str);
	pattern_length = strlen(pattern);
	printf("Pattern matched at positions \t");
	for(i=0 ; i< str_length;i++)
	{
		for(j=0 ; j < pattern_length; j++)
		{
			if(str[i + j] == pattern[j])
			count++;
		}
		if(count == pattern_length)
		{
			printf("%d\t", i+1);
		}
		count = 0;
	}
	printf("\n");
}
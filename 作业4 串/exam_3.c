#include <stdio.h>

#define ElemType char
#define Maxsize 100
#define True 1
#define Flase 0

typedef struct
{
	ElemType ch[Maxsize];
	int len;
} SString;

int initStr(SString *sstring)
{
	sstring->len = 0;
	scanf("%s", sstring->ch);
	while (sstring->ch[sstring->len] != '\0')
	{
		sstring->len++;
	}
}

void commonStr(SString s1, SString s2)
{
	SString tempStr;
	tempStr.len = 0;
	int i, j, temp;
	int start;
	for (i = 0; i < s1.len; i++)
	{
		for (j = 0; j < s2.len; j++)
		{
			if (s1.ch[i] == s2.ch[j])
			{
				for (temp = 0; s1.ch[i + temp] == s2.ch[j + temp]; temp++)
				{
					if (s1.ch[i + temp] == '\0' || s2.ch[j + temp] == '\0')
					{
						break;
					}
				}
				if (temp > tempStr.len)
				{
					start = i;
					tempStr.len = temp;
				}
			}
		}
	}

	for (i = 0; i < tempStr.len; i++)
	{
		tempStr.ch[i] = s1.ch[start + i];
	}
	if (tempStr.len == 0)
	{
		printf("no");
	}
	else
	{
		printf("%s", tempStr.ch);
	}
}

int main(int argc, char const *argv[])
{
	SString s1, s2;
	initStr(&s1);
	initStr(&s2);
	commonStr(s1, s2);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
#define ElemType char
#define True 1

typedef struct Node
{
	ElemType data;
	struct Node *LeftChild;
	struct Node *RightChild;
} BinaNode, *BinaTree;

// void initStr(ElemType * inStr, ElemType * postStr){
// 	char str[200];
// 	int number;
// 	gets(str);
// 	sscanf(str, "%s %s", inStr, postStr);
// 	printf("The character input was: '%s'+ '%s'\n", inStr, postStr);
// }

int initStr(ElemType *inStr, ElemType *postStr)
{
	ElemType temp;
	int flag = 0;
	int i = 0, j = 0, len = 0;
	while (True)
	{
		scanf("%c", &temp);
		if (temp == ' ')
		{
			flag = 1;
			continue;
		}
		if (flag == 0)
		{
			inStr[i] = temp;
			i++;
			len++;
		}
		else if (flag == 1)
		{
			postStr[j] = temp;
			j++;
			if (j == len)
			{
				return len;
			}
		}
	}
}

void creatBinaTree(ElemType *inStr, ElemType *postStr, int strlen)
{
	char root;
	root = postStr[strlen - 1];
}

int main(int argc, char const *argv[])
{
	ElemType inStr[100], postStr[100];
	int strLen;
	strLen = initStr(inStr, postStr);
	creatBinaTree(inStr, postStr, strLen);
	return 0;
}

// #include <stdio.h>  //引入标准输入输出库
// void main( ) {
//     char ch[100];
// 		char a[100], b[100];
//     printf ("Input a character: ");   //输入提示信息
//     gets(ch);  // 从标准输入控制台中读取字符
// 		sscanf(ch, "%s %s", a, b);
//     printf ("The character input was: '%s'+ '%s'\n", a, b);  // 输出字符
// }
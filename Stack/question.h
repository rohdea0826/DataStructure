#pragma once

//元素出栈、入栈顺序的合法性。如入栈的序列(1,2,3,4,5)，出栈序列为
//(4, 5, 3, 2, 1)

#include "Stack.h"

//in.size == out.size
int IsValid(char in[], char out[], int size)
{
	int ii = 0, io = 0;
	Stack s;
	InitialStack(&s);

	while (ii < size)
	{
		if (in[ii] == out[io])
		{
			ii++;
			io++;
		}
		else
		{
			if (s.count != 0 && GetTop(&s) == out[io])
			{
				PopStack(&s);
				io++;
			}
			else
			{
				PushStack(&s, in[ii]);
				ii++;
			}
		}
	}
	//进的序列已经全部结束
	while(s.count != 0)
	{
		if (GetTop(&s) != out[io])
		{
			return 0;
		}
		PopStack(&s);
		io++;
	}
	return 1;
}

void TestValid()
{
	char *in = "abcdefg";
	char *out1 = "decfbga";
	char *out2 = "fegdacb";
	char *out3 = "efdgbca";
	char *out4 = "cdbefag";

	printf("%s\n", IsValid(in, out1, sizeof(in)) ? "合法" : "不合法");
	printf("%d\n", IsValid(in, out4, sizeof(in)));

}




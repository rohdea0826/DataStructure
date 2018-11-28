#pragma once

//Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ������(1,2,3,4,5)����ջ����Ϊ
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
	//���������Ѿ�ȫ������
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

	printf("%s\n", IsValid(in, out1, sizeof(in)) ? "�Ϸ�" : "���Ϸ�");
	printf("%d\n", IsValid(in, out4, sizeof(in)));

}




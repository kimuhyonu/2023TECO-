#pragma once
#include <stdio.h>

void printSub(int a)
{
	if (a > 0)
	{
		for (size_t i = 1; i <= (1 << a); i++)
		{
			printf("{");
			for (size_t j = 0; j < a; j++)
			{
				if (i & (1 << j))
				{
					printf(" O ");
				}
				else
				{
					printf(" X ");
				}
			}
			printf("}  %d\n", i);
		}
	}
}

void printb(unsigned int v) {
	unsigned int mask = (int)1 << (sizeof(v) * 7);
	putchar('0');
	putchar('x');
	do putchar(mask & v ? '1' : '0');
	while (mask >>= 1);
	putchar('\n');
}

void printBit() 
{
	// ��Ʈ �������� �ּ� ���� 0 1
	// 1����Ʈ 8��Ʈ
	// 1����Ʈ - char
	// 2����Ʈ - short, word
	// 4����Ʈ - int, float, long(32��Ʈ ȯ��)
	// 8����Ʈ - double, long long(32��Ʈ ȯ��)
	// 0000 0000 - 255
	// 0000 0000 0000 0000 - 65535

	char a;// -128 127
	short b;//-32768 32767
	int c; // -2147483648 2147483647
	long d; // long�� int�� �ü������ ũ�Ⱑ �ٸ���
	long long e;
	float f;//10�� 38��
	double g;//10 308��
	unsigned char a1;// 0 255
	unsigned short b2;//0 65535
	unsigned int c3; // 0 41...
	unsigned long d4;
	unsigned long long e5;

	// signed unsigned?
	// signed - ����Ʈ ��ȣ�� �ִ°�
	// unsigned - ��ȣ�� ���°�

	// char
	// 1000 0000 -
	// 0000 0000 +

	// 10�� ����
	// 1�� 10�� ������ 9
	// ��ǻ�ʹ� ���̳ʽ��� �𸥴�(����)

	// ��Ʈ������ ������ ���հ� ����

	// AND & - ������
	// 1 1 - 1
	// 1 0 - 0 
	// 0 1 - 0
	// 0 0 - 0

	// OR | - ������
	// 1 1 - 1
	// 1 0 - 1
	// 0 1 - 1
	// 0 0 - 0

	// NOT !
	// 1 - 0
	// 0 - 1

	// ��Ÿ���⿬����
	// XOR ^ -
	// 1 1 - 0
	// 1 0 - 1
	// 0 1 - 1
	// 0 0 - 0
	
	// SHIFT LEFT <<
	// 0010  �� 00100 �� 0100

	// SHIFT RIGHT >>
	// 0010  �� 001 �� 0001

	// i��° ��Ʈ�� ON�ΰ�?	if (bit & (1 << i))
	// char a    0010 0011
	//           0000 0010
	//           0000 0010 - bool true 

	// i��° ��Ʈ�� OFF�ΰ�? if (!(bit & (1 << i)))

	// i��° ��Ʈ�� ON�Ѵ�	bit�� = (1 << i)
	// 1010 0001
	// 0000 1000 or
	// 1010 1001 

	// i��° ��Ʈ�� OFF�Ѵ�	bit &= ~(1 << i)
	// 1010 0001
	// 1111 1110 and
	// 1010 0000

	// ��Ʈ�� � ON�Ǿ��ִ°�?	_popcount(bit)  --c++
	// 1010 1001
	// for and

	// bit�� i��° ��Ʈ�� ON�� ��	bit��(1 << i)
	// bit�� i��° ��Ʈ�� OFF�� ��	bit & ~(1 << i)

	// ��Ʈ�����ϴ� ����

	// ó���ӵ��� ���� - 
	// �뷮�� �����
	// 0x8000 and true �� �������� ������ ���ȱ���
	
	
	// ��Ʈ���� ����
	// 1. Ȧ���� �Ǻ��ϴ� ���
	// Ȧ�� & 0x01 Ȧ��

	// 2. ¦���� �Ǻ��ϴ� ���
	// !(¦�� & 0x01)

	// 3. 4�� ���� ���� ������ ���ϴ� ���
	// 1111  0011 &
	// ���� and 0x03
	// 2�� ������ ���� ����

	// 4. a�� b�� ���� ���� �ٲٴ� ���
	// a = a ^ b;
	// b = a ^ b;
	// a = a ^ b;
	int aaa = 11;
	int bbb = 15;
	aaa = aaa ^ bbb;
	bbb = aaa ^ bbb;
	aaa = aaa ^ bbb;
	

	// ����. N���� ������ �κ������� ��� ���Ͻÿ�
	// 0 0 0 0
	// 1 << 0 1
	// 1 << 1 2
	// 1 << 2 4
	// 1 << 3 8
	// 1 << 4 16
	// 1 << N 2N

	return 0;
}
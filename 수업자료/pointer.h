#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printCharArr(char** p_CharArr, int cnt) 
{
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", p_CharArr[i]);
	}
}


int* pointerPrint()
{
	// ����޸�(Virtual Memory)��?
	// OS�� �޸𸮸� ����/�����ϴ� ���
	// ���� ���α׷��� ������ �޸𸮸� ���� ����ϴ� ���� �ƴ� OS�� ��� ��ġ�� �޸𸮸� ����Ѵ�
	/*int a = 10;
	int* pa = &a;
	printf("%d",a);*/

	// �����Ͷ�?
	// ������ �޸� �ּҰ��� �����ϴ� "����"

	// ������ �ĺ��� *
	// �������� ���ʿ� �ٴ´�(Left Value)
	// ������ ������ �������� ��Ÿ���� "�ĺ���"
	// ��� �� ) int* p_a;      int *p_a;
	

	// ������ ������ *
	// ������ ������ ���ʿ� �پ� ����Ѵ�(Right Value)
	// ������ ������ ���� �ּҰ��� �����ϴ� ���� �����ϴ� "������"
	// ��� �� ) printf("%d", *p_a);    *p_a = 10;
	

	// ���� ������ &
	// ������ ������ ���ʿ� �پ� ����Ѵ�(Right Value)
	// ������ ������ ���� �ּҰ��� �����ϴ� ���� �����ϴ� "������"
	// ��� �� ) printf("%d", *p_a);    *p_a = 10;
	int intA = 10;
	int* p_intA = &intA;
	*p_intA = 11;
	printf("intA�� �ּ� 0x%08x\n", &intA);
	printf("intA�� �� %d\n", intA);
	printf("p_intA�� �ּ� 0x%08x\n", &p_intA);
	printf("p_intA�� �� 0x%08x\n", p_intA);



	// �迭�� �ǹ�
	// �迭 ������ ���� �迭 ���� ��ġ�� �ּ�
	int arrA[4] = { 1, 2, 3, 4 };

	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// arrA�迭������ 2��° �׸��� �ٲ۴�
	int* p_arrA = arrA;
	arrA[1] = 99;
	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// p_arrA�� ���� �迭�ּ��� 2��° �׸��� �ٲ۴�
	*(p_arrA + 1) = 55;
	for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");

	// �迭�� ù��° �׸��� 0������ ������?

	// ���ڿ��� char�� �迭�̴�
	char p_stringA[16] = "string is Array";
	printf("p_stringA�� �� %s\n",p_stringA);
	printf("p_stringA�� ���ڱ��� %d\n", strlen(p_stringA));

	char* p_stringB = "string is Array";
	printf("p_stringB�� �� %s\n", p_stringB);
	printf("p_stringB�� ���ڱ��� %d\n", strlen(p_stringB));

	*(p_stringA + 10) = 'a';
	printf("p_stringA�� �� %s\n", p_stringA);
	//*(p_stringB + 10) = 'a';
	printf("p_stringB�� �� %s\n", p_stringB);

	// ���������ʹ� �迭�� �迭�� ��
	char* p_charArr[] = { "double pointer", "is just", "Array of Array" };
	char** pp_charArr = p_charArr;
	printCharArr(pp_charArr,3);

	// �� ���ڿ� �迭�� �ƴ� ���ڿ� ������ �迭(����������)�ΰ�?
	char charArrOrigin[][20] = { "double pointer","is just", "Array of Array" };

	// Shallow Copy VS Deep Copy�� ���� �����غ���
	

	// �����Ҵ�
	// �� �����Ҵ��� �ϴ°�?

	// �Ʒ��� ������ �������� �ʴ� ������?
	/*int stNum;
	printf("�л����� �Է��� �ּ���. ");
	scanf("%d", &stNum);
	int arScore[stNum];*/

	// Stack VS Heap

	
	// malloc (size)
	//{
	//	// �޸� �Ҵ�
	//	int* allocA = malloc(sizeof(int));
	//	// �޸� ����
	//	free(allocA);
	//}
	// calloc (cnt, size)
	//{
	//	// �޸� �Ҵ�
	//	int* allocB = calloc(10,sizeof(int));
	//	// �޸� ����
	//	free(allocB);
	//}
	// realloc (ptr, size)
	//{
	//	char* allocC = (char*)malloc(4);

	//	// allocC ���
	//	char* backupBuffer = allocC;

	//	// realloc ���н�
	//	if (NULL == (allocC = (char*)realloc(allocC, 8)))
	//	{
	//		// ������� �޸� ������ ��
	//		free(backupBuffer);
	//		fprintf(stderr, "Memory allocation is failed");

	//		// ������� ���� �� ��
	//		allocC = backupBuffer;
	//	}
	//}
	// new? �� ���ؼ� �����غ���

	int* arrB = malloc(sizeof(int));
	*arrB = 10;
	//free(arrB);

	// int retA = 10;
	// return &retA;
	return arrB;
	// ���� 1. int������ ������ �迭�� ������ �μ��� �޾� �ش� �������� ������ �����ϴ� �Լ��� �ۼ��Ͻÿ�

	// ���� 2. char������ ���� A�� �� "String is difficult" B�� �� "string is not inefficient"
	//         ���� ������ ���ڰ� ���� ��� ����ϴ� �Լ��� �ۼ��Ͻÿ�

	// ���� 3. ���ͷ��� �ƴ� ���ڿ��� ������ ���ڿ� �迭 �����͸� �ۼ��ϰ� 2��° ���ڿ��� 2��° ���ڸ� �ٲٴ� �Լ��� �ۼ��Ͻÿ�
	//         ���ڿ� �迭 ���� : "pointer" "is nothing" "very easy man"

	// ���� 4. �޸𸮸� �Ҵ��� ���� �Ҵ��� ����� �����ؾ� ������ ������ ���� �޸� �ּ� ������ ������ �Ǵ� ������ �����Ͻÿ�
}
	

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// ����ü ���� ��
struct structSample
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
};

// ����ü ���� + ���� ���� ��
struct structSample2
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
}ss2;

// ����ü ���� + ����ü�� ��Ī ����(��Ī�� struct �ĺ��ڰ� �ʿ� ������)
typedef struct structSample3
{
	int a;
	short b;
	char c;
	int* pa;
	char* pstring;
}structSample3;


#pragma region MagicianStruct
// ������ ����ü
typedef struct item
{
	char* name;		// �̸�
	int power;		// ����
	int level;		// ���뷹��
	int durability;	// ������
}item;

// ������ �������� ������ ���¸� ��Ÿ���� ����ü�� ��
typedef struct MagicianStruct
{
	char* name;		// �̸�
	int level;		// ����
	int healthPoint;// ü��
	int mana;		// ����
	item* items;	// ������ �����۸��
	int itemCnt;    // ������ ������ ����
}Magician;
#pragma endregion

#pragma region MagicianFunc
// ������ �߰� �Լ�
// �μ� - ����������ּ�  �����۸�  ����  ����  ������
void addItemForMagician(Magician* Magician, const char* itemName, int power, int level, int durability)
{
	// �Է¹��� ���� ������ ��Ͽ� �߰�
	char* pTmpName = (char*)malloc(sizeof(char) * 99);
	strcpy_s(pTmpName, strlen(itemName) + 1, itemName);
	Magician->items[Magician->itemCnt].name = pTmpName;
	Magician->items[Magician->itemCnt].power = power;
	Magician->items[Magician->itemCnt].level = level;
	Magician->items[Magician->itemCnt].durability = durability;
	Magician->itemCnt++;
}

// ������ ���� ����
// �μ� - ����������ּ�  �����۸�
void deleteItemForMagician(Magician* Magician, char* itemName)
{
	for (size_t i = 0; i < Magician->itemCnt; i++)
	{
		// �����۸��� ������ ���
		if (strcmp(itemName, Magician->items[i].name) == 0)
		{
			printf("�����۸� '%s'��(��) �����Ͽ����ϴ�\n", itemName);
			// �������� ����
			free(Magician->items[i].name);
			Magician->items[i].power = 0;
			Magician->items[i].level = 0;
			Magician->items[i].durability = 0;
			// �κ��丮 ��ġ ����
			for (size_t j = i + 1; j < Magician->itemCnt; j++)
			{
				Magician->items[j - 1] = Magician->items[j];
			}
			Magician->itemCnt--;
			Magician->items[Magician->itemCnt].name = NULL;
			Magician->items[Magician->itemCnt].power = 0;
			Magician->items[Magician->itemCnt].level = 0;
			Magician->items[Magician->itemCnt].durability = 0;
			return;
		}
	}
	printf("�����۸� '%s'��(��) �����ϰ� ���� �ʽ��ϴ�\n", itemName);
	return;
}

// ������ ��ü ����
// �μ� - ����������ּ�
void deleteAllItemForMagician(Magician* Magician)
{
	for (size_t i = 0; i < Magician->itemCnt; i++)
	{
		// �������� ����
		printf("�����۸� '%s'��(��) �����Ͽ����ϴ�\n", Magician->items[i].name);
		free(Magician->items[i].name);
		Magician->items[i].power = 0;
		Magician->items[i].level = 0;
		Magician->items[i].durability = 0;
	}
	return;
}

// ĳ���� ����
// �μ� - ����������ּ�
void deleteMagician(Magician* Magician)
{
	printf("'%s'��(��) �����մϴ�\n");
	// �̸� �Ҵ� ����
	free(Magician->name);
	// ������ �Ҵ� ����
	deleteAllItemForMagician(Magician);
	// ĳ���� ����ü �Ҵ�����
	free(Magician);
}

// ĳ������ �������
// �μ� - ����������ּ�
void printStatusMagician(Magician* Magician)
{
	printf("*****************************\n");
	printf("\n");
	printf("�̸� : %s\n", Magician->name);
	printf("���� : Lv %d\n", Magician->level);
	printf("ü�� : HP %d\n", Magician->healthPoint);
	printf("���� : MP %d\n", Magician->mana);
	printf("\n");
	// ���� ������ ���
	printItems(Magician->items, Magician->itemCnt);
	printf("\n");
	printf("*****************************\n");
}

// ������ ������Ȳ ���
// �μ� - ������ �ּ�    ������ ����
void printItems(item* pItem, int itemCnt)
{
	printf("������ ���� ���� %d��\n", itemCnt);
	for (size_t i = 0; i < itemCnt; i++)
	{
		printf("---------------------\n");
		printf("\n");
		printf("�����۸� : %s\n", pItem[i].name);
		printf("���ݷ� : %d\n", pItem[i].power);
		printf("���뷹�� : %d\n", pItem[i].level);
		printf("������ : %d\n", pItem[i].durability);
		printf("\n");
		printf("---------------------\n");
	}
}
#pragma endregion




void pointerPrint2()
{
	// ����ü
	// �ϳ� �̻��� ������ ���� ���ο� �ڷ����¸� ��Ÿ���� '����� ����' �ڷ���
	// �ϳ��� ���������δ� ��ü�� ǥ���ϱ⿡�� ����

	// ����ü ���� ���� ��
	struct structSample ss1;
	structSample3 ss3;

	// ����ü ������
	structSample3* p_ss3;

	// ����ü Ȱ�� ��
	ss2.a = 1;
	ss2.c = 'a';
	char tmpc[] = "char pointer in struct\n";
	int tmpd = 11;
	ss2.pstring = tmpc;
	ss2.pa = &tmpd;
	printf("ss2�� a: %d   c: %c  int: %d  string: %s\n",ss2.a, ss2.c, *ss2.pa, ss2.pstring);

	// ����ü ������ Ȱ���� ��
	// (*).
	structSample3 tmpss3;
	p_ss3 = &tmpss3;
	(*p_ss3).a = 2;
	(*p_ss3).c = 'a';
	(*p_ss3).pstring = tmpc;
	(*p_ss3).pa = &tmpd;
	printf("ss3�� a: %d   c: %c  int: %d  string: %s\n", (*p_ss3).a, (*p_ss3).c, *((*p_ss3).pa), (*p_ss3).pstring);



	// ->
	p_ss3->a = 3;
	p_ss3->c = 'b';
	char tmpc2[] = "struct pointer\n";
	p_ss3->pstring = tmpc2;
	int tmpd2 = 21;
	p_ss3->pa = &tmpd2;
	printf("ss3�� a: %d   c: %c  int: %d  string: %s\n", p_ss3->a, p_ss3->c, *(p_ss3->pa), p_ss3->pstring);


	// ������ �������� ������ ���¸� ��Ÿ���� ����ü�� ��


	// ������ ����ü �ʱ�ȭ
#pragma region Magician1
	// �����縦 �������� ������ ������ ���¸� �����ϴ� ����ü�� �����Ҵ� �Ѵ�
	Magician* p_user1 = (Magician*)malloc(sizeof(Magician));
	// �������� ������ �ʱ�ȭ
	p_user1->items = (item*)malloc(sizeof(item*) * 99);
	p_user1->itemCnt = 0;
#pragma endregion

	// �̸��� �Է� �ޱ�
#pragma region Magician2
	char* tmpName = (char*)malloc(sizeof(char) * 99);
	printf("ĳ������ �̸��� �Է��� �ֽʽÿ�. \n");
	scanf_s("%s", tmpName, 99);
	p_user1->name = tmpName;
	printf("\n����� ĳ���� �̸��� %s �Դϴ� \n", p_user1->name);
#pragma endregion

	// �⺻ ���� ����(���� HP MANA)
#pragma region Magician3
	// ���� ����
	p_user1->level = 1;
	// HP����
	p_user1->healthPoint = 100;
	// ��������
	p_user1->mana = 200;
#pragma endregion

	// �⺻������ ����
#pragma region Magician4
	addItemForMagician(p_user1, "basicWand", 10, 1, 100);
	addItemForMagician(p_user1, "basicStaff", 30, 5, 100);
	addItemForMagician(p_user1, "basicShield", 10, 1, 100);
	addItemForMagician(p_user1, "basicCloth", 10, 1, 100);
	addItemForMagician(p_user1, "basicShoes", 10, 1, 100);
#pragma endregion
	
	// ĳ������ �������
#pragma region Magician5
	printf("����� ĳ���ʹ� �������̸� ���´� �Ʒ��� �����ϴ�\n");
	printStatusMagician(p_user1);
#pragma endregion

	// ������,ĳ���� ����
#pragma region Magician6
	// ������ ����
	printf("������ �������� �Է��ϼ���\n");
	char tmpDelItemName[99];
	scanf_s("%s", tmpDelItemName, 99);
	deleteItemForMagician(p_user1, tmpDelItemName);

	// ĳ������ �������
	printStatusMagician(p_user1);

	// ĳ���� ����
	deleteMagician(p_user1);
#pragma endregion

	// ���� do while���� Ȱ���Ͽ� �ؽ�Ʈ �Է� ��� ������ �ۼ��Ͻÿ�

	// �䱸���� 1. ĳ���ʹ� �̸� ���� HP �����̻��� ���°� �����Ѵ�
	// �䱸���� 2. ���ʹ� �̸� ���� ���ݷ� HP�� ���°� �����Ѵ�
	// �䱸���� 3. �������� �̸� ���뷹�� ���� �������� �����Ѵ�
	// �䱸���� 4. ĳ������ ���ݷ��� �����ϰ� �ִ� �������� ������ �����̴�
	// �䱸���� 5. ���ӿ��� ĳ���� ����Ȯ��,���� ����Ȯ��, ������Ȯ��, ���, ���ᰡ �����Ѵ�
	// �䱸���� 6. ����� ���͸� �����ϸ� Ȯ�������� ĳ���ʹ� ���Ϳ��� ������� �Դ´�
	// �䱸���� 7. ���Ϳ��� ������� ������ Ȯ�������� �����̻� ������ �����̻��� Bit�� �ٷ��
	// �䱸���� 8. �����̻��� ������ �ּ� 4���� �̻��̴�
	// �䱸���� 9. �����̻��� ������ �ּ� 4���� �̻��̴�
	// �䱸���� 10. ������ HP�� 0�� �Ǹ� Ȯ�������� �������� ��´�
	// �䱸���� 11. ���Ͱ� ������ �� ���� ���Ͱ� �����Ѵ�
	// �䱸���� 12. ĳ������ HP�� 0�� �Ǹ� ������ ����ȴ�
	
	return;
}

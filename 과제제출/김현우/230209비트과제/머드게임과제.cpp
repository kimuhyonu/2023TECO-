#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//기본 구조

// 아이템은 이름 착용레벨 위력 내구도가 존재한다
typedef struct item
{
	char* name;
	int level;
	int power; 
	int durability;

}item;

//상태이상의 종류는 최소 4가지 이상이다
typedef struct state
{
	char state[4];
	
	

}state;

// 캐릭터는 이름 레벨 HP 상태이상의 상태가 존재한다
typedef struct characterST
{
	char* name;
	int level;
	int healthPoint;
	int itemCnt;
	int damage;
	item* items;
	state* states;

}character;
// 몬스터는 이름 레벨 공격력 HP의 상태가 존재한다
typedef struct monsterST
{
	char* name;
	int level;
	int damage;
	int healthPoint;

}monster;

	//기능

void addItemForCharacter(character* character, const char* itemName, int itemPower, int itemLevel, int itemdurability)
{
	// 입력받은 값을 아이템 목록에 추가
	char* pTmpName = (char*)malloc(sizeof(char) * 99);
	strcpy_s(pTmpName, strlen(itemName) + 1, itemName);
	character->items[character->itemCnt].name = pTmpName;
	character->items[character->itemCnt].power = itemPower;
	character->items[character->itemCnt].level = itemLevel;
	character->items[character->itemCnt].durability = itemdurability;
	character->itemCnt++;
	character->damage = itemPower;
}


//전투 

//사냥은 몬스터를 공격하며 확률적으로 캐릭터는 몬스터에게 대미지를 입는다
void BattleForMonster(character* character, monster* monster) 
{
	int count=0;
	int hit;
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여
	hit= rand()%10;

	if (monster->healthPoint > 0) 
	{
				printf("케릭터의 공격\n");
				printf("%d만큼 데미지를 줬습니다.\n", character->damage);
				monster->healthPoint -= character->damage;
				printf("몬스터의 현재 체력%d\n", monster->healthPoint);
				if (monster->healthPoint <= 0) {
					printf("몬스터가 죽었습니다.\n\n");
					count=1;
					
				}
	}
	else if (hit< 3)
	{
				printf("%d만큼 데미지를 입었습니다..\n", monster->damage);
				character->healthPoint -= monster->damage;
				printf("케릭터의 현재 체력%d\n", character->healthPoint);
	}
	
	
			
	
	
		
	
}



//상태출력

// 인수 - 캐릭터상태주소
void printStatuscharacter(character* character)
{
	printf("*****************************\n");
	printf("\n");
	printf("이름 : %s\n", character->name);
	printf("레벨 : Lv %d\n", character->level);
	printf("체력 : HP %d\n", character->healthPoint);
	printf("공격력 : Atk %d\n", character->damage);
	/*printf("상태 : State %s\n", character->states);*/
	printf("\n");
	printf("\n");
	printf("*****************************\n");
}

// 인수 - 몬스터상태주소
void printStatuscharacter(monster* monster)
{
	printf("*****************************\n");
	printf("\n");
	printf("레벨 : Lv %d\n", monster->level);
	printf("체력 : HP %d\n", monster->healthPoint);
	printf("공격력 : Atk %d\n", monster->damage);
	printf("\n");
	printf("\n");
	printf("*****************************\n");
}




int main() {

	character* user = (character*)malloc(sizeof(character));
	monster* mons = (monster*)malloc(sizeof(monster));
	user->items = (item*)malloc(sizeof(item*) * 99);
	user->itemCnt = 0;

	char* tmpName = (char*)malloc(sizeof(char) * 99);
	printf("캐릭터의 이름을 입력해 주십시오. \n");
	scanf_s("%s", tmpName, 99);
	user->name = tmpName;
	printf("\n당신의 캐릭터 이름은 %s 입니다 \n", user->name);
	// 레벨설정
	user->level = 1;
	// HP설정
	user->healthPoint = 50;
	//몬스터 설정
	mons->level = 10;
	mons->healthPoint = 40;
	mons->damage = 5;
	//초기 아이템 지급
	addItemForCharacter(user, "BasicSword", 10, 1, 10);


	printf("\n당신의 캐릭터에게 기본무기 %s 가 지급되었습니다 \n", user->items->name);


	do {

		int hotkey;
		printf("\n메뉴를 선택해주세요.\n[1]번 케릭터상태 \n[2]번 몬스터상태 \n[3]번 아이템확인 \n[4]번 사냥 \n[5]번 종료 \n");
		scanf_s("%d", &hotkey);
		
		switch (hotkey) {
		//게임에는 캐릭터 상태확인,몬스터 상태확인, 아이템확인, 사냥, 종료가
			//캐릭터 상태확인
		case 1:

			printf("당신의 캐릭터의 상태는 아래와 같습니다\n");
			printStatuscharacter(user);
			break;
			
			//몬스터 상태확인
		case 2:
			
			printStatuscharacter(mons);
			break;
			//아이템확인
		case 3:
			//미구현
			
			break;
			
		case 4:
			//사냥
			BattleForMonster(user,mons);
			
			break;
		case 5:
			//종료
			user->healthPoint = 0;
			break;
		default:
			printf("잘못입력하였습니다.");
		}

				

		
	} while (user->healthPoint > 0);
	{
		free(user);

		printf("GAMEOVER");
	}


	return 0;
}

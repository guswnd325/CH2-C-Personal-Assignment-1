#include <Windows.h>
#include "main.h"
#define MENU_FIRST_INDEX 0
#define MENU_LAST_INDEX 6

int main(void)
{
	Character character;

	character.SetPotion(5, character.GetPotionRef(HPPotion), character.GetPotionRef(MPPotion));
	
	while (true)
	{
		while (!character.IsInitialized(HP))
		{
			int hp;

			Console::Clear();
			cout << "플레이어의 HP를 입력하세요(51 이상) → ";
			cin >> hp;

			if (hp <= 50)
			{
				Console::InputError();
			}
			else
			{
				character.SetStatus(HP, hp);
				Console::Clear();
				cout << "체력 설정 완료...";
				Console::Delay(0.5);
				break;
			}
		}

		while (!character.IsInitialized(MP))
		{
			int mp;

			Console::Clear();
			cout << "플레이어의 MP를 입력하세요(51 이상) → ";
			cin >> mp;

			if (mp <= 50)
			{
				Console::InputError();
			}
			else
			{
				character.SetStatus(MP, mp);
				Console::Clear();
				cout << "마나 설정 완료...";
				Console::Delay(0.5);
				break;
			}
		}

		while (!character.IsInitialized(AttackDamage))
		{
			int attackDamage;

			Console::Clear();
			cout << "플레이어의 공격력을 입력하세요(1 이상) → ";
			cin >> attackDamage;

			if (attackDamage <= 0)
			{
				Console::InputError();
			}
			else
			{
				character.SetStatus(AttackDamage, attackDamage);
				Console::Clear();
				cout << "공격력 설정 완료...";
				Console::Delay(0.5);
				break;
			}
		}
		
		while (!character.IsInitialized(DefensePower))
		{
			int defensePower;

			Console::Clear();
			cout << "플레이어의 방어력을 입력하세요(1 이상) → ";
			cin >> defensePower;

			if (defensePower <= 0)
			{
				Console::InputError();
			}
			else
			{
				character.SetStatus(DefensePower, defensePower);
				Console::Clear();
				cout << "방어력 설정 완료...";
				Console::Delay(0.5);
				break;
			}
		}


		Console::Clear();
		cout << "1.체력 증가(20)" << endl;
		cout << "2.마나 증가(20)" << endl;
		cout << "3.공격력 증가(2배)" << endl;
		cout << "4.방어력 증가(2배)" << endl;
		cout << "5.스탯 확인" << endl;
		cout << "6.레벨 업" << endl;
		cout << "0.종료" << endl;

		cout << "수행하고자 하는 로직의 번호를 입력하세요 -> ";

		int index = 0;
		cin >> index;
		
		if (cin.fail() || !(index >= MENU_FIRST_INDEX && index <= MENU_LAST_INDEX)) {
			Console::InputError();
			continue;
		}

		if (index == 0) {
			return 0;
		}

		Console::Clear();
		character.Process(index);
		Console::Delay(1.5);
	}

	return 0;
}
#include <iostream>
#include <limits>

#define endl '\n'
#define NOT_INITIALIZED -1

using namespace std;

enum Status
{
	HP,
	MP,
	AttackDamage,
	DefensePower,
	Agility
};

enum PotionType
{
	HPPotion,
	MPPotion
};

class Character
{
private:
	int status[5] = {NOT_INITIALIZED, NOT_INITIALIZED, NOT_INITIALIZED, NOT_INITIALIZED, 1};
	int potions[2] = { 5, 5 };
	int level = 1;

public:

	int* GetPotionRef(PotionType index) 
	{
		return &potions[(int)index];
	}

	void Process(int index)
	{
		switch (index)
		{
		case 1:
			UseHPPotion(20);
			break;
		case 2:
			UseMPPotion(20);
			break;
		case 3:
			SetAttackDamage(status[(int)AttackDamage] * 2);
			break;
		case 4:
			SetDefensePower(status[(int)DefensePower] * 2);
			break;
		case 5:
			ShowStatus();
			break;
		case 6:
			LevelUp();
			break;
		}
	}
	void SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
	{
		*p_HPPotion = count;
		*p_MPPotion = count;
	}

	void AddPotion(PotionType type, int value)
	{
		potions[(int)type] += value;
	}

	bool IsInitialized(Status index)
	{
		if (status[(int)index] == NOT_INITIALIZED)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void ShowStatus()
	{
		cout << "== Player Status ==" << endl;
		cout << "[Level] : " << level << endl;
		cout << "[HP] : " << status[(int)HP] << endl;
		cout << "[MP] : " << status[(int)MP] << endl;
		cout << "[Attack Damage] : " << status[(int)AttackDamage] << endl;
		cout << "[Defense Power] : " << status[(int)DefensePower] << endl;
		cout << "[HP PotionCount] : " << potions[(int)HPPotion] << endl;
		cout << "[MP PotionCount] : " << potions[(int)MPPotion] << endl;
		cout << "[Agility] : " << status[(int)Agility] << endl;
	}

	void UseMPPotion(int value)
	{
		if (potions[MPPotion] >= 1)
		{
			cout << "마나 포션을 사용했습니다." << endl;
			cout << "[MP] : " << status[(int)MP] << " → " << status[(int)MP] + value << endl;
			cout << "[MP Potion Count] : " << potions[(int)MPPotion] << " → " << potions[(int)MPPotion] -1 << endl;
			AddPotion(MPPotion, -1);
			status[(int)MP] += value;
		}
		else
		{
			cout << "마나 포션이 부족합니다." << endl;
		}
	}

	void UseHPPotion(int value)
	{
		if (potions[HPPotion] >= 1)
		{
			cout << "체력 포션을 사용했습니다." << endl;
			cout << "[HP] : " << status[(int)HP] << " → " << status[(int)HP] + value << endl;
			cout << "[HP Potion Count] : " << potions[(int)HPPotion] << " → " << potions[(int)HPPotion] -1 << endl;
			AddPotion(HPPotion, -1);
			status[(int)HP] += value;
		}
		else
		{
			cout << "체력 포션이 부족합니다." << endl;
		}
	}

	void LevelUp()
	{
		cout << "레벨 업!" << endl;
		cout << "[Level] : " << level << " → " << level + 1 << endl;
		cout << "[HP Potion Count] : " << potions[(int)HPPotion] << " → " << potions[(int)HPPotion] + 1 << endl;
		cout << "[MP Potion Count] : " << potions[(int)MPPotion] << " → " << potions[(int)MPPotion] + 1 << endl;
		
		AddAgility(10);
		AddPotion(HPPotion, 1);
		AddPotion(MPPotion, 1);
		level += 1;
	}

	void SetAttackDamage(int value)
	{
		cout << "공격력 증가" << endl;
		cout << "[Attack Damage] : " << status[(int)AttackDamage] << " → " << value << endl;
		AddAgility(5);
		status[(int)AttackDamage] = value;
	}

	void SetDefensePower(int value)
	{
		cout << "방어력 증가" << endl;
		cout << "[Defense Power] : " << status[(int)DefensePower] << " → " << value << endl;
		AddAgility(5);
		status[(int)DefensePower] = value;
	}

	void AddAgility(int value)
	{
		cout << "[Agility] : " << status[(int)Agility] << " → " << status[(int)Agility] + value << endl;
		status[(int)Agility] += value;
	}

	void SetStatus(Status index, int value)
	{
		status[(int)index] = value;
	}
};

class Console
{
public:
	static void Clear()
	{
		system("cls");
	}

	static void Delay(float delaySecond)
	{
		Sleep((DWORD)(delaySecond * 1000));
	}

	static void InputError()
	{
		Clear();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
		cout << "※ 올바른 값을 입력해주세요! ※";
		Console::Delay(1);
	}
};


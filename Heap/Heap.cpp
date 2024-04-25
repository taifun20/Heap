
#include <iostream>
#include <random>
#include"Enemy_.h"

int Player_Health_{ 100 };
int Player_Coins_{ 10 };
int Player_XP_{ 0 };

void CE_Destroy_Enemy_(Enemy_* LV_Enemy_)
{
	delete LV_Enemy_;
}

void CE_Spawn_Enemy_()
{
	Enemy_* LV_Enemy_ = new Enemy_();
	int LV_Health_{ 0 };

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(5, 15);
	LV_Health_ = distribution(rd);

	if (Player_Health_ >= LV_Health_)
	{
		Player_Health_ -= LV_Health_ / 2;
		std::cout << "	GAME: You eliminated one enemy, your health is now " << Player_Health_ << std::endl;
		CE_Destroy_Enemy_(LV_Enemy_);

		Player_XP_ += 1;
		Player_Coins_ += 2;

		if (Player_Coins_ >= 4)
		{
			std::cout << "	GAME: You both 2 bandages with a cost of 4!" << std::endl;
			Player_Coins_ -= 4;
			Player_Health_ += 4;
			std::cout << "	GAME: Your health is now " << Player_Health_ << std::endl << std::endl;

		}else
		{
			std::cout << "	GAME: You dont have any coins, come back when you're a little mmm richer !" << std::endl << std::endl;
		}


	}
	else
	{
		Player_Health_ = 0;
		std::cout << "	GAME: Mission failed, we go next time!" << std::endl;
		CE_Destroy_Enemy_(LV_Enemy_);

		std::cout << "	GAME: You got " << Player_XP_ << " XP" << std::endl << std::endl;
	}
}

void CE_Mission_01_()
{
	while (Player_Health_ > 0)
	{
		CE_Spawn_Enemy_();
	}
}

int main()
{
	CE_Mission_01_();
}

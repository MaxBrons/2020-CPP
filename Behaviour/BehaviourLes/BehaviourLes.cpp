// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string>
#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"
#include "Vector2d.h"

double delay = .1;
double previousFrameTime = 0.0;
int maxWidth = 50;
int maxHeight = 50;

std::vector<std::string> scene;
bool running = true;

int main()
{
	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, { 2,2 }, "E");
	Character enemy(Character::AvailableBehaviours::CHASE, {23, 23}, "C", & player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::vector<Character*> characters{ &player, &enemy };

	//deze scene vullen met _
	previousFrameTime = clock();
	//de game zelf
	while (running) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay) {
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;
			for (Character* aCharacter : characters)
			{
				aCharacter->Update();
				COORD position = { aCharacter->GetPosition().GetX(), aCharacter->GetPosition().GetY() };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				std::cout << aCharacter->GetIcon();
			}
			previousFrameTime = clock();
		}
		if (characters.at(0)->GetPosition().GetX() == characters.at(1)->GetPosition().GetX() - 2) {
			player.Setbehaviour(Character::AvailableBehaviours::CHASE);
			enemy.Setbehaviour(Character::AvailableBehaviours::EVADE);
			//running = false;
		}
	}
	std::cin.get();
}
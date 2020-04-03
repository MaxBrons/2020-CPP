// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>
#include <vector>
#include <string>
#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

double delay = .1;
double previousFrameTime = 0.0;
int maxWidth = 100;
std::vector<std::string,std::string> scene;
bool running = true;
int main()
{
	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, new Vector2d(0,20), "E");
	Character enemy(Character::AvailableBehaviours::CHASE, new Vector2d(0, 40), "C", &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::vector<Character*> characters{ &player, &enemy };

	//een scene van 100 breed aanmaken
	scene.resize(50);

	//deze scene vullen met _
	previousFrameTime = clock();
	//de game zelf
	while (running) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay) {
			std::fill(scene.begin(), scene.end(), "_");
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;
			for (Character* aCharacter : characters) {
				//scene.at(aCharacter->Update()) = aCharacter->GetIcon();
			}
			/*for (std::string s : scene) {
				std::cout << s;
			}*/

			//[x][y]
			std::vector<std::vector<std::string>> newScene{
				{"~","`","&"},
				{"*","$","^"}
			};

			for (int x = 0; x < newScene.size(); x++)
			{
				for (int y = 0; y < newScene.at(x).size(); y++) {

				}
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
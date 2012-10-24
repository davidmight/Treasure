/*CS2014 Lab12
 
 Name: David Byrne
 Student ID: 09068783
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "BT_Player.cpp"
using namespace std;

class BT_Moderator {
private:
	Treasure ** player1;
	Treasure ** player2;
public:
	BT_Moderator();
	Treasure ** build_board();
	void record_treasure_placements(BT_Player playa, int num);
	int check_invalid(BT_Player player_1, BT_Player player_2);
	bool check_board(BT_Player player, int numb);
};
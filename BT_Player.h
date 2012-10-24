/*CS2014 Lab12
 
 Name: David Byrne
 Student ID: 09068783
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

enum Treasure{
	Empty,GoldenBench,BronzeSar,SilverChest,DocuChest,MerlinBeard,HIT
};

class BT_Player {
private:
	// various private declarations
	Treasure ** myTreasure;
	int theResult;
public:
	BT_Player();
	void start_new_game();
	void place_bench(bool& horizontal, int& row_start, int& col_start);
	void place_sarcophagus(bool& horizontal, int& row_start, int& col_start);
	void place_silver(bool& horizontal, int& row_start, int& col_start);
	void place_document(bool& horizontal, int& row_start, int& col_start);
	void place_beard(bool& horizontal, int& row_start, int& col_start);
	bool dig(int& row, int& column);
	void record_find(bool hit);
	void record_game_result(int result); // 1 win, 0 draw, -1 lose
	Treasure ** get_board();
};
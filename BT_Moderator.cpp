/*CS2014 Lab12
 
 Name: David Byrne
 Student ID: 09068783
 
*/

#include "BT_Moderator.h"

BT_Moderator :: BT_Moderator(){
	BT_Player players[2];
	
	for (int i = 0; i < 2; i++) {
		players[i].start_new_game();
		// call each of the 'place' methods in turn
		record_treasure_placements(players[i], i);
	}
	
	int result1, result2 = 0;
	int turn = 0;
	int sel_row = 0;
	int sel_col = 0;
	bool game_over = false;
	if(check_invalid(players[0], players[1]) == 0){
		game_over = true;
		cout << "Player 1 has to due Player 2 invalid placement.";
		result1 = 1;
		result2 = -1;
	}else if(check_invalid(players[0], players[1]) == 1){
		game_over = true;
		cout << "Player 2 has to due Player 1 invalid placement.";
		result2 = 1;
		result1 = -1;
	}else if(check_invalid(players[0], players[1]) == 2){
		game_over = true;
		cout << "The game is a draw as both teams has invalid placements.";
		result1 = 0;
		result2 = 0;
	}
	
	while ( !game_over ) {
		/* initialize random seed: */
		srand ( time(NULL) );
		/* generate secret number: */
		sel_row = rand() % 9 + 0;
		sel_col = rand() % 9 + 0;
		if(players[turn].dig(sel_row, sel_col) == true){
			game_over = true;
			if(turn == 0){
				cout << "Player 1 has won the game brah!";
				result1 = 1;
				result2 = -1;
			}else{
				cout << "Player 2 has won the game brah!";
				result2 = 1;
				result1 = -1;
			}
		}
		turn = !turn;
		
	}
	players[0].record_game_result(result1);
	players[1].record_game_result(result2);
	
}

Treasure ** BT_Moderator :: build_board(){
	Treasure ** myTreasure = new Treasure * [10];
	
	//Setting all positions in the grid to be empty
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			myTreasure[i][j] = Empty;
		}
	}
	return myTreasure;
}

void BT_Moderator :: record_treasure_placements(BT_Player playa, int num){
	if(num == 0){
		player1 = playa.get_board();
	}else{
		player2 = playa.get_board();
	}
}

bool BT_Moderator :: check_board(BT_Player player, int numb){
	int bench_count = 0;
	int sarcophagus_count = 0;
	int silver_count = 0;
	int document_count = 0;
	int beard_count = 0;
	if(numb == 0){
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(player1[i][j] == GoldenBench){
					bench_count++;
				}
				if(player1[i][j] == BronzeSar){
					sarcophagus_count++;
				}
				if(player1[i][j] == SilverChest){
					silver_count++;
				}
				if(player1[i][j] == DocuChest){
					document_count++;
				}
				if(player1[i][j] == MerlinBeard){
					beard_count++;
				}
			}
		}
	}else{
		for(int m=0; m<10; m++){
			for(int n=0; n<10; n++){
				if(player2[m][n] == GoldenBench){
					bench_count++;
				}
				if(player2[m][n] == BronzeSar){
					sarcophagus_count++;
				}
				if(player2[m][n] == SilverChest){
					silver_count++;
				}
				if(player2[m][n] == DocuChest){
					document_count++;
				}
				if(player2[m][n] == MerlinBeard){
					beard_count++;
				}
			}
		}
	}
	if(bench_count != 5 || 
	   sarcophagus_count != 4 || 
	   silver_count != 3 ||
	   document_count != 3 ||
	   beard_count != 2){
		return true;
	}
	return false;
}

int BT_Moderator :: check_invalid(BT_Player player_1, BT_Player player_2){
	if (check_board(player_1, 0) == true || check_board(player_2, 1) == true) {
		if (check_board(player_1, 0) == true && check_board(player_2, 1) == false) {
			return 0;
		}else if (check_board(player_1, 0) == false && check_board(player_2, 1) == true) {
			return 1;
		}else{
			return 2;
		}
	}
	return 3;
}
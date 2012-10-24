#include "BT_Player.h"

BT_Player :: BT_Player(){
	Treasure ** myTreasure = new Treasure * [10];
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			myTreasure[i][j] = Empty;
		}
	}
	myTreasure = myTreasure;
}

void BT_Player :: start_new_game(){
	bool axisb;
	int axisnum;
	int row = 0;
	int col = 0;
	int counter = 0;
	
	while(counter != 4){
		/* initialize random seed: */
		srand ( time(NULL) );
		/* generate secret number: */
		axisnum = rand() % 1 + 0;
		if(axisnum = 1){
			axisb = true;
		}else{
			axisb = false;
		}
		row = rand() % 9 + 0;
		col = rand() % 9 + 0;
		
		switch (counter) {
			case 0:
				place_bench(axisb, row, col);
				break;
			case 1:
				place_sarcophagus(axisb, row, col);
				break;
			case 2:
				place_silver(axisb, row, col);
				break;
			case 3:
				place_document(axisb, row, col);
				break;
			case 4:
				place_beard(axisb, row, col);
				break;
			default:
				break;
		}
		counter++;
	}
}

bool BT_Player :: dig(int& row, int&column){
	if(myTreasure[row][column] != Empty){
		myTreasure[row][column] = HIT; 
		return true;
	}
	return false;
}

void BT_Player :: place_bench(bool& horizontal, int& row_start, int& col_start){
	if(horizontal == false){
		for(int i=col_start; i<col_start+5; i++){
			myTreasure[row_start][i] = GoldenBench;
		}
	}else{
		for (int j=row_start; j<row_start+5; j++) {
			myTreasure[j][col_start] = GoldenBench;
		}
	}
}

void BT_Player :: place_sarcophagus(bool& horizontal, int& row_start, int& col_start){
	if(horizontal == false){
		for(int i=col_start; i<col_start+4; i++){
			myTreasure[row_start][i] = BronzeSar;
		}
	}else{
		for (int j=row_start; j<row_start+4; j++) {
			myTreasure[j][col_start] = BronzeSar;
		}
	}
}

void BT_Player :: place_silver(bool& horizontal, int& row_start, int& col_start){
	if(horizontal == false){
		for(int i=col_start; i<col_start+3; i++){
			myTreasure[row_start][i] = SilverChest;
		}
	}else{
		for (int j=row_start; j<row_start+3; j++) {
			myTreasure[j][col_start] = SilverChest;
		}
	}
}

void BT_Player :: place_document(bool& horizontal, int& row_start, int& col_start){
	if(horizontal == false){
		for(int i=col_start; i<col_start+3; i++){
			myTreasure[row_start][i] = DocuChest;
		}
	}else{
		for (int j=row_start; j<row_start+3; j++) {
			myTreasure[j][col_start] = DocuChest;
		}
	}
}

void BT_Player :: place_beard(bool& horizontal, int& row_start, int& col_start){
	if(horizontal == false){
		for(int i=col_start; i<col_start+2; i++){
			myTreasure[row_start][i] = MerlinBeard;
		}
	}else{
		for (int j=row_start; j<row_start+2; j++) {
			myTreasure[j][col_start] = MerlinBeard;
		}
	}
}

Treasure ** BT_Player :: get_board(){
	return myTreasure;
}

void BT_Player :: record_game_result(int result){
	theResult = result;
}
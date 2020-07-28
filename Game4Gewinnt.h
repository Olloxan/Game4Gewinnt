#pragma once

// #################################################
// Loop:
//		BeginNextTurn
//		GetGameState
//		ShiftPixel
//		Release
//		GetGamestate
// #################################################

class Game4Gewinnt
{
public: 
	Game4Gewinnt();

	// returns current match field
	int* GetMatchField();
	int GetCurrentPixelPos();
	int GetLastPixelPos();

	// Set new Pixel in Toprow, if not possible
	// Gamestate is draw
	int BeginNextTurn();

	int GetGameState();
	int GetCurrentPlayer();

	// React to button press
	void ShiftPixelRight();
	void ShiftPixelLeft();
	void ReleasePixel();

	void Reset();

	// Debug
	void FillGame();

private:
	
	// internal Matchfield of size 8x8 as a singe 64 field Array
	static const int _MatchFieldSize = 64;
	static const int _MatchFieldWidth = 8;
	static const int _MatchFieldHeight = 8;
	int _MatchField[_MatchFieldSize];
	
	// Two Players, Player 1 and Player 2
	int _CurrentPlayer;
	
	// 0 - Game running
	// 1 - Player 1 won
	// 2 - Player 2 won
	// 3 - Draw
	int _GameState;

	int _LastPixelPos;
	int _CurrentPixelPos;

	void CheckGameWon();

	int CheckHorizontal();
	int CheckVertical();
	int CheckDiagonal_LeftDown();
	int CheckDiagonal_RightDown();

	bool IsNotBottomBorder(int down);
	bool IsNotTopBorder(int up);
	bool IsNotLeftBorder(int left);
	bool IsNotRightBorder(int right);
	bool IsSamePlayer(int left);

	void InitGame();
	void InitMatchField();

	// Debug
	void FillBlock(int blockHeight);
};
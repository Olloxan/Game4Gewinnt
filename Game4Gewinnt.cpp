#include "Game4Gewinnt.h"

Game4Gewinnt::Game4Gewinnt()
{
	InitGame();
}

int* Game4Gewinnt::GetMatchField()
{
	return _MatchField;
}

int Game4Gewinnt::BeginNextTurn()
{
	for (int i = 0; i < _MatchFieldWidth; i++)
	{
		if (_MatchField[i] == 0)
		{
			_CurrentPixelPos = i;
			_MatchField[i] = _CurrentPlayer;
			_GameState = 0;
			return _GameState;
		}
	}	
	return 3;
}

int Game4Gewinnt::GetGameState()
{
	return _GameState;
}

int Game4Gewinnt::GetCurrentPlayer()
{
	return _CurrentPlayer;
}

void Game4Gewinnt::ShiftPixelRight()
{	
	int temp = _CurrentPixelPos;
	int shift = 1;
	for (int i = _CurrentPixelPos; i < _MatchFieldWidth-1; i++)
	{		
		if (_MatchField[i + 1] == 0)
		{
			_CurrentPixelPos += (shift);
			_MatchField[temp] = 0;
			_MatchField[i+1] = _CurrentPlayer;
			break;
		}		
		shift++;
	}
}

void Game4Gewinnt::ShiftPixelLeft()
{
	int temp = _CurrentPixelPos;
	int shift = 1;
	for (int i = _CurrentPixelPos; i > 0; i--)
	{
		if (_MatchField[i - 1] == 0)
		{
			_CurrentPixelPos -= (shift);
			_MatchField[temp] = 0;
			_MatchField[i - 1] = _CurrentPlayer;
			break;
		}
		shift++;
	}
}

void Game4Gewinnt::ReleasePixel()
{
	for (int i = _MatchFieldHeight-1; i >= 0; i--)
	{
		if (_MatchField[_CurrentPixelPos + i*_MatchFieldWidth] == 0)
		{			
			_MatchField[_CurrentPixelPos + i * _MatchFieldWidth] = _CurrentPlayer;
			_MatchField[_CurrentPixelPos] = 0;
			_CurrentPixelPos += i * _MatchFieldWidth;
			break;
		}
	}
	CheckGameWon();
	_CurrentPlayer = _CurrentPlayer == 1 ? 2 : 1;
}

void Game4Gewinnt::Reset()
{
	InitGame();
}
//################# Private #################
void Game4Gewinnt::InitGame()
{
	_CurrentPlayer = 1;
	_GameState = 0;
	InitMatchField();
}

void Game4Gewinnt::InitMatchField()
{
	for (int i = 0; i < _MatchFieldSize; i++)
	{
		_MatchField[i] = 0;
	}
}

void Game4Gewinnt::CheckGameWon()
{
	int connectedPixels = 0;
	int temp = 0;
	connectedPixels = CheckHorizontal();
	temp = CheckVertical(); 
	connectedPixels = connectedPixels > temp ? connectedPixels : temp;
	temp = CheckDiagonal_LeftDown();
	connectedPixels = connectedPixels > temp ? connectedPixels : temp;
	temp = CheckDiagonal_RightDown();
	connectedPixels = connectedPixels > temp ? connectedPixels : temp;
	if (connectedPixels == 4)
	{
		_GameState = _CurrentPlayer;
	}
}

int Game4Gewinnt::CheckDiagonal_RightDown()
{
	int left = _CurrentPixelPos, right = _CurrentPixelPos;
	for (int i = 0; i < 4; i++)
	{
		left = IsNotLeftBorder(left) && IsNotTopBorder(left) ? IsSamePlayer(left - _MatchFieldWidth - 1) ? left - _MatchFieldWidth - 1 : left : left;
		right = IsNotRightBorder(right) && IsNotBottomBorder(right) ? IsSamePlayer(right + _MatchFieldWidth + 1) ? right + _MatchFieldWidth + 1 : right : right;
	}
	return (right - left) / 9 + 1;
}

int Game4Gewinnt::CheckDiagonal_LeftDown()
{
	int left = _CurrentPixelPos, right = _CurrentPixelPos;
	for (int i = 0; i < 4; i++)
	{
		left = IsNotLeftBorder(left) && IsNotBottomBorder(left) ? IsSamePlayer(left + _MatchFieldWidth - 1) ? left + _MatchFieldWidth - 1 : left : left;
		right = IsNotRightBorder(right) && IsNotTopBorder(right) ? IsSamePlayer(right - _MatchFieldWidth + 1) ? right - _MatchFieldWidth + 1 : right : right;
	}
	return (left - right) / 7 + 1;
}

int Game4Gewinnt::CheckHorizontal()
{	
	int left = _CurrentPixelPos, right = _CurrentPixelPos;
	for (int i = 0; i < 4; i++)
	{
		left = IsNotLeftBorder(left) ? IsSamePlayer(left - 1) ? --left : left : left;
		right = IsNotRightBorder(right) ? IsSamePlayer(right + 1) ? ++right : right : right;		
	}
	return right - left;
}

int Game4Gewinnt::CheckVertical()
{
	int up = _CurrentPixelPos, down = _CurrentPixelPos;
	for (int i = 0; i < 4; i++)
	{
		up = IsNotTopBorder(up) ? IsSamePlayer(up - _MatchFieldWidth) ? up - _MatchFieldWidth : up : up;
		down = IsNotBottomBorder(down) ? IsSamePlayer(down + _MatchFieldWidth) ? down + _MatchFieldWidth : down : down;
	}
	return (down - up) / 8 + 1;
}

bool Game4Gewinnt::IsNotBottomBorder(int down)
{
	return down + _MatchFieldWidth < _MatchFieldSize;
}

bool Game4Gewinnt::IsNotTopBorder(int up)
{
	return up - _MatchFieldWidth > 0;
}

bool Game4Gewinnt::IsNotLeftBorder(int left)
{
	return left % _MatchFieldWidth > 0;
}

bool Game4Gewinnt::IsNotRightBorder(int right)
{
	return right % _MatchFieldWidth < _MatchFieldWidth - 1;
}

bool Game4Gewinnt::IsSamePlayer(int left)
{
	return _MatchField[left] == _CurrentPlayer;
}



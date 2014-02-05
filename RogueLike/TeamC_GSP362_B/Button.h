
#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


struct Button
{
	int X, Y, Width, Height;
	RECT Me;

	Button(){
		X = 0;
		Y = 0;
		Width = 0;
		Height = 0;
		Me.top = 0;
		Me.bottom = 0;
		Me.left = 0;
		Me.right = 0;
	}

	Button(int aX, int aY, int aWidth, int aHeight){
		X = aX;
		Y = aY;
		Width = aWidth;
		Height = aHeight;
		Me.top = Y;
		Me.bottom = Y + Height;
		Me.left = X;
		Me.right = X + Width;
	}

	void MoveButton(int x, int y){
		X = x;
		Y = y;
		Me.top = Y;
		Me.bottom = Y + Height;
		Me.left = X;
		Me.right = X + Width;
	}

	bool IsCursorOnMe(long aX, long aY){
		if(aX > Me.left && aX < Me.right && aY > Me.top && aY < Me.bottom){
			return true;
		}
		return false;
	}

	void CalcRECT(){
		Me.top = Y;
		Me.bottom = Y + Height;
		Me.left = X;
		Me.right = X + Width;
	}
};
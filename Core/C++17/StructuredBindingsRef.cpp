/**
 * \file
 * \brief
 *
 * \todo
 */


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x;
	int y;
};

// Driver code
int main( )
{
	Point p = { 1,2 };

	// Structure binding
	auto &[x_coord, y_coord] = p;

    // cout << "type: " << typeid( decltype([x_coord, y_coord]) ).name() << endl;

	x_coord = 7;
	y_coord = 8;

	cout << "X Coordinate : " << x_coord << endl;
	cout << "Y Coordinate : " << y_coord << endl;

  	cout << "p.x : " << p.x << endl;
	cout << "p.y : " << p.y << endl;

	return 0;
}

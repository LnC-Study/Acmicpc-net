#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string original_cube[6][3] = {
	{"www","www","www"},
	{"ggg","ggg","ggg"},
	{"ooo","ooo","ooo"},
	{"bbb","bbb","bbb"},
	{"rrr","rrr","rrr"},
	{"yyy","yyy","yyy"}
};

string this_cube[6][3];
string **cube;

int convert_to_side[6][6] = {
	{0,1,2,3,4,5},
	{1,2,0,4,5,3},
	{2,3,0,1,5,4},
	{3,4,0,2,5,1},
	{4,1,0,3,5,2},
	{5,1,4,3,2,0}
};

void cpy_original_cube() {

	for(int i = 0 ; i < 6; i++)
		for (int j = 0; j < 3; j++) 
			this_cube[i][j] = original_cube[i][j];
		
}

void counter_clockwise_rotate(int dir) {
	vector<string> tmp = vector<string>(3, string("",3));

	for (int i = 0, k = 2; i < 3; i++, k--)
		for (int j = 2; j >= 0; j--) {
			tmp[i][j] = this_cube[dir][j][k];
		}

	for (int i = 0; i < 3; i++) {
		this_cube[dir][i] = tmp[i];
	}

}

void clockwise_rotate(int dir) {
	vector<string> tmp = vector<string>(3, string("", 3));

	for(int i = 0, k = 2 ; i < 3; i++, k--)
		for (int j = 0; j < 3; j++) {
			tmp[j][k] = this_cube[dir][i][j];
		}

	for (int i = 0; i < 3; i++) {
		this_cube[dir][i] = tmp[i];
	}
}

void clockwise_side_rotate() {
	string tmp = cube[4][0];

	for (int i = 3; i >= 1; i--) {
		cube[i + 1][0] = cube[i][0];
	}

	cube[1][0] = tmp;
}

void counter_clockwise_side_rotate() {
	string tmp = cube[1][0];

	for (int i = 1; i < 4; i++) {
		cube[i][0] = cube[i + 1][0];
	}

	cube[4][0] = tmp;
}

void cube_direction_change(int dir) {

	for (int i = 0; i < 6; i++)
		cube[i] = this_cube[convert_to_side[dir][i]];
	
	switch (dir)
	{
	case 0:break;
	case 1:
		clockwise_rotate(0);
		clockwise_rotate(4);
		clockwise_rotate(5); 
		counter_clockwise_rotate(2);
		break;
	case 2:
		clockwise_rotate(5);
		clockwise_rotate(5);
		clockwise_rotate(1);
		counter_clockwise_rotate(3);
		break;
	case 3:
		counter_clockwise_rotate(0);
		counter_clockwise_rotate(4);
		counter_clockwise_rotate(5);
		clockwise_rotate(2);
		break;
	case 4:
		counter_clockwise_rotate(1);
		clockwise_rotate(0);
		clockwise_rotate(0);
		clockwise_rotate(3);
		break;
	case 5:
		counter_clockwise_rotate(1);
		counter_clockwise_rotate(1);
		counter_clockwise_rotate(2);
		counter_clockwise_rotate(2);
		counter_clockwise_rotate(3);
		counter_clockwise_rotate(3);
		counter_clockwise_rotate(4);
		counter_clockwise_rotate(4);
		break;
	}
}

void cube_rotation_revert(int dir) {
	switch (dir)
	{
	case 0:break;
	case 1:
		counter_clockwise_rotate(0);
		counter_clockwise_rotate(4);
		counter_clockwise_rotate(5);
		clockwise_rotate(2);
		break;
	case 2:
		counter_clockwise_rotate(5);
		counter_clockwise_rotate(5);
		counter_clockwise_rotate(1);
		clockwise_rotate(3);
		break;
	case 3:
		clockwise_rotate(0);
		clockwise_rotate(4);
		clockwise_rotate(5);
		counter_clockwise_rotate(2);
		break;
	case 4:
		clockwise_rotate(1);
		counter_clockwise_rotate(0);
		counter_clockwise_rotate(0);
		counter_clockwise_rotate(3);
		break;
	case 5:
		clockwise_rotate(1);
		clockwise_rotate(1);
		clockwise_rotate(2);
		clockwise_rotate(2);
		clockwise_rotate(3);
		clockwise_rotate(3);
		clockwise_rotate(4);
		clockwise_rotate(4);
		break;
	}
}

void data_in() {

	int T;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &T);

	cube = (string**)malloc(sizeof(string*) * 6);

	for (int i = 0; i < T; i++) {
		cpy_original_cube();
		int n;
		scanf("%d ", &n);

		for (int j = 0; j < n; j++) {
			char command[3]; int dir;
			scanf("%s ", command);

			switch (command[0])
			{
			case 'U':cube_direction_change(0); dir = 0; break;
			case 'L':cube_direction_change(1); dir = 1; break;
			case 'B':cube_direction_change(2); dir = 2; break;
			case 'R':cube_direction_change(3); dir = 3; break;
			case 'F':cube_direction_change(4); dir = 4; break;
			case 'D':cube_direction_change(5); dir = 5; break;
			}

			switch (command[1])
			{
			case '+':
				clockwise_rotate(dir);
				clockwise_side_rotate();
				break;
			case '-':
				counter_clockwise_rotate(dir);
				counter_clockwise_side_rotate();
				break;
			}

			cube_rotation_revert(dir);

		}

		for (int j = 0; j < 3; j++) {
			cout << this_cube[0][j] << endl;
		}
	}
}

int main() {
	data_in();
}

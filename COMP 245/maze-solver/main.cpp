#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

bool isMoveValid(char maze[80][80], Coordinate position, Coordinate max) {
    if (position.Row < 0 || position.Column < 0 || position.Row > max.Row || position.Column > max.Column)
        return false;
    if (maze[position.Row][position.Column] != '0' && maze[position.Row][position.Column] != 'E')
        return false;
    return true;
}

int main() {

    ifstream fin;
    fin.open("maze.dat");
    if (!fin) {
        cout << "input file (maze.dat) does not exist... exiting" << endl;
        return 1;
    }

    ofstream fout;
    fout.open("maze.out");
    fout << "Solutions to A-MAZE-ING Stacks Assignment" << endl << "Jerred Shepherd" << endl << endl;

    int currentMaze = 0;

    while (true) {
        currentMaze++;
        cout << "Starting maze " << currentMaze << endl;

        char maze[80][80];
        int mazeRows = 0;
        int mazeColumns = 0;
        Coordinate maxPosition;
        Coordinate currentPosition;
        Stack moveStack;
        bool possible;

        fin >> mazeRows;
        fin >> mazeColumns;

        if (mazeRows == -1 || mazeColumns == -1) {
            cout << "We're out of mazes" << endl;
            break;
        }

        fout << "MAZE NUMBER " << currentMaze << endl << endl;

        maxPosition.Row = mazeRows - 1;
        maxPosition.Column = mazeColumns - 1;

        cout << "Reading in next maze" << endl;
        for (int row = 0; row < mazeRows; row++) {
            for (int column = 0; column < mazeColumns; column++) {
                fin >> maze[row][column];
            }
        }

        fin >> currentPosition.Row;
        fin >> currentPosition.Column;

        cout << "Starting position:" << endl;
        cout << currentPosition.Row << " " << currentPosition.Column << endl;

        while (true) {

            if (maze[currentPosition.Row][currentPosition.Column] == 'E') {
                possible = true;
                cout << "Solution to maze " << currentMaze << " found" << endl;
                break;
            }

            cout << "Checking coords" << endl;
            cout << "Current Position: " << currentPosition.Row << " " << currentPosition.Column << endl;

            Coordinate north, east, south, west;

            north.Row = currentPosition.Row;
            north.Column = currentPosition.Column + 1;

            east.Row = currentPosition.Row + 1;
            east.Column = currentPosition.Column;

            south.Row = currentPosition.Row;
            south.Column = currentPosition.Column - 1;

            west.Row = currentPosition.Row - 1;
            west.Column = currentPosition.Column;

            if (isMoveValid(maze, north, maxPosition)) {
                if (!moveStack.Push(north)) {
                    cout << "Memory error" << endl;
                    return true;
                } else {
                    cout << "Pushed " << north.Row << " " << north.Column << endl;
                }
            }

            if (isMoveValid(maze, east, maxPosition)) {
                if (!moveStack.Push(east)) {
                    cout << "Memory error" << endl;
                    return true;
                } else {
                    cout << "Pushed " << east.Row << " " << east.Column << endl;
                }
            }

            if (isMoveValid(maze, south, maxPosition)) {
                if (!moveStack.Push(south)) {
                    cout << "Memory error" << endl;
                    return true;
                } else {
                    cout << "Pushed " << south.Row << " " << south.Column << endl;
                }
            }

            if (isMoveValid(maze, west, maxPosition)) {
                if (!moveStack.Push(west)) {
                    cout << "Memory error" << endl;
                    return true;
                } else {
                    cout << "Pushed " << west.Row << " " << west.Column << endl;
                }
            }

            maze[currentPosition.Row][currentPosition.Column] = '.';

            if (!moveStack.IsEmpty()) {
                currentPosition = moveStack.Pop();
            } else {
                cout << "Maze cannot be solved" << endl;
                possible = false;
                break;
            }

        }

        cout << "Printing solved maze to output file" << endl;
        for (int row = 0; row < mazeRows; row++) {
            for (int column = 0; column < mazeColumns; column++) {
                fout << maze[row][column];
            }
            fout << endl;
        }

        if (possible) {
            fout << endl << "There IS a way out!" << endl << endl;
        } else {
            fout << endl << "There IS NOT a way out!" << endl << endl;
        }

    }

    fin.close();
    fout.close();

    return 1;
}

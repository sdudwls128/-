#include <bangtal>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
using namespace bangtal;

bool checkIn(int x, int y, int hideX, int hideY) {
    return ((x == hideX && abs(y - hideY) == 150) || (abs(x - hideX) == 150 && y == hideY));
}

int main()
{
    srand((unsigned int)time(NULL));
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

    auto scene1 = Scene::create("원본", "Images/원본.png");
    auto startButton = Object::create("Images/start.png", scene1, 250, 40);
    auto scene2 = Scene::create("배경", "Images/배경.png");

    startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        scene2->Scene::enter();
        return true;
        });

    // 각 퍼즐의 x, y 좌표를 저장해놓은 배열
    int locationX[9] = { 75, 225, 375, 75, 225, 375, 75, 225, 375 };
    int locationY[9] = { 300, 300, 300, 150, 150, 150, 0, 0, 0 };

    // 각 퍼즐을 생성해 초기 위치에 놓는다.
    ObjectPtr puzzles[9] = { Object::create("Images/1.png", scene2, locationX[0], locationY[0]),
                    Object::create("Images/2.png", scene2, locationX[1], locationY[1]),
                    Object::create("Images/3.png", scene2, locationX[2], locationY[2]),
                    Object::create("Images/4.png", scene2, locationX[3], locationY[3]),
                    Object::create("Images/5.png", scene2, locationX[4], locationY[4]),
                    Object::create("Images/6.png", scene2, locationX[5], locationY[5]),
                    Object::create("Images/7.png", scene2, locationX[6], locationY[6]),
                    Object::create("Images/8.png", scene2, locationX[7], locationY[7]),
                    Object::create("Images/9.png", scene2, locationX[8], locationY[8]) };

    // 중복이 없는 난수를 생성해 배열에 넣는다.
    int random[9];
    int i, j;
    for (i = 0; i < 9; i++) {
        random[i] = rand() % 9;
        for (j = 0; j < i; j++) {
            if (random[i] == random[j]) {
                i--;
                break;
            }
        }
    }

    //퍼즐을 섞는다.
    for (i = 0; i < 9; i++) {
        puzzles[i]->locate(scene2, locationX[random[i]], locationY[random[i]]);
    }

    // 무작위로 하나의 퍼즐을 숨긴다.
    int hidePuzzle = rand() % 9;
    int hideX = locationX[random[hidePuzzle]];
    int hideY = locationY[random[hidePuzzle]];
    puzzles[hidePuzzle]->hide();

    int tmpX = 0;
    int tmpY = 0;

    // 퍼즐 맞추기
    puzzles[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[0]];
        tmpY = locationY[random[0]];

        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            // 숨겨진 퍼즐과 클릭한 퍼즐의 자리를 바꿈
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            // 두 퍼즐의 위치를 표시하는 변수를 바꿈
            locationX[random[0]] = hideX;
            locationY[random[0]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[1]];
        tmpY = locationY[random[1]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[1]] = hideX;
            locationY[random[1]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[2]];
        tmpY = locationY[random[2]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[2]] = hideX;
            locationY[random[2]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[3]];
        tmpY = locationY[random[3]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[3]] = hideX;
            locationY[random[3]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[4]];
        tmpY = locationY[random[4]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[4]] = hideX;
            locationY[random[4]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[5]];
        tmpY = locationY[random[5]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[5]] = hideX;
            locationY[random[5]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[6]];
        tmpY = locationY[random[6]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[6]] = hideX;
            locationY[random[6]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[7]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[7]];
        tmpY = locationY[random[7]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[7]] = hideX;
            locationY[random[7]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    puzzles[8]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tmpX = locationX[random[8]];
        tmpY = locationY[random[8]];
        if (checkIn(tmpX, tmpY, hideX, hideY)) {
            puzzles[hidePuzzle]->locate(scene2, tmpX, tmpY);
            object->locate(scene2, hideX, hideY);

            locationX[random[8]] = hideX;
            locationY[random[8]] = hideY;
            hideX = tmpX;
            hideY = tmpY;
        }
        return true;
        });

    startGame(scene1);

    return 0;
}
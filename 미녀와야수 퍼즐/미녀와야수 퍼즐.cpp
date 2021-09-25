#include <bangtal>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
using namespace bangtal;


ScenePtr scene;
ObjectPtr game_original[12];
ObjectPtr game_board[12];
ObjectPtr start;
ObjectPtr endButton;
TimerPtr timer;

float animationTime = 0.01f;
int mixCount = 10;
int blank;

int game_index(ObjectPtr piece) {
	for (int i = 0; i < 12; i++) {
		if (game_board[i] == piece)
			return i;
	}
	return -1;	// INVALID PIECE
}

int index_to_x(int index) {
	return 161 + 240 * (index % 4);
}

int index_to_y(int index) {
	return 479 - 239 * (index / 4);
}

void game_move(int index) {
	// index <-> blank
	auto piece = game_board[index];
	game_board[index] = game_board[blank];
	game_board[index]->locate(scene, index_to_x(index), index_to_y(index));
	game_board[blank] = piece;
	game_board[blank]->locate(scene, index_to_x(blank), index_to_y(blank));
	blank = index;
}

bool check_move(int index) {
	if (blank % 4 > 0 && index == blank - 1) return true;
	if (blank % 4 < 3 && index == blank + 1) return true;
	if (blank / 3  > 0 && index == blank - 4) return true;
	if (blank / 3 < 3 && index == blank + 4) return true;
	return false;
}

int random_move() {
	int index = rand() % 12;
	while (!check_move(index)) {
		index = rand() % 12;
	}
	return index;
}

void start_game() {
	mixCount = 10;
	timer->set(animationTime);
	timer->start();

	blank = rand() % 12;
	game_board[blank]->hide();
}

bool check_end() {
	for (int i = 0; i < 12; i++) {
		if (game_board[i] != game_original[i])
			return false;
	}
	return true;
}

void end_game() {
	game_board[blank]->show();
	showMessage("Completed!!");
	start->setImage("Images/restart.png");
	start->show();
	
	endButton->show();
	endButton->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		endGame();
		return 0;
		});
}

void init_game() {
	scene = Scene::create("미녀와야수 퍼즐", "Images/배경.png");

	char path[20];
	for (int i = 0; i < 12; i++) {
		sprintf_s(path, "Images/%d.png", i + 1);
		game_board[i] = Object::create(path, scene, index_to_x(i), index_to_y(i));
		game_board[i]->setOnMouseCallback([&](auto piece, auto x, auto y, auto action)->bool {
			int index = game_index(piece);
			if (check_move(index)) {
				game_move(index);

				if (check_end()) {
					end_game();
				}
			}
			return true;
			});
		game_original[i] = game_board[i];
	}
	endButton = Object::create("Images/end.png", scene, 590, 30);
	endButton->hide();

	start = Object::create("Images/start.png", scene, 590, 100);
	start->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
		endButton->hide();
		start->hide();
		start_game();
		return true;
		});

	timer = Timer::create(animationTime);
	timer->setOnTimerCallback([&](auto)->bool {
		game_move(random_move());

		mixCount--;
		if (mixCount > 0) {
			timer->set(animationTime);
			timer->start();
		}

		return true;
		});

	startGame(scene);
}

int main() {
	srand((unsigned int)time(NULL));
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	init_game();

	return 0;
}
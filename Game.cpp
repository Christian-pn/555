#include "DxLib.h"

typedef enum {
	eScene_Menu,    //メニュー画面
	eScene_Game,    //ゲーム画面
	eScene_Config,  //設定画面
} eScene;

static int Scene = eScene_Menu;    //現在の画面(シーン)

//シーンを更新する
void UpdateScene() {
	DrawString(0, 20, "Gキーでゲーム画面、Cキーで設定、Mキーでメニュー画面になります。", GetColor(255, 255, 255));
	if (CheckHitKey(KEY_INPUT_G) != 0) {
		Scene = eScene_Game;
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		Scene = eScene_Config;
	}
	if (CheckHitKey(KEY_INPUT_M) != 0) {
		Scene = eScene_Menu;
	}
}

//メニュー画面
void Menu() {
	DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
}

//ゲーム画面
void Game() {
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
}

//設定画面
void Config() {
	DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		switch (Scene) {//現在のシーンにあった処理をする
		case eScene_Menu://現在のシーンがメニューなら
			Menu();//メニュー画面
			break;
		case eScene_Game://現在のシーンがゲームなら
			Game();//ゲーム画面
			break;
		case eScene_Config://現在のシーンが設定なら
			Config();//設定画面
			break;
		}

		UpdateScene();//シーンを更新する

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
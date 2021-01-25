#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetGraphMode(1300, 870, 0);
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定

	SetMouseDispFlag(TRUE);
    SceneMgr sceneMgr;
    sceneMgr.Initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//画面更新 & メッセージ処理 & 画面消去

	
		Keyboard_Update();    //キーボードの更新
        sceneMgr.Update();  //更新
        sceneMgr.Draw();    //描画

    }

    sceneMgr.Finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}
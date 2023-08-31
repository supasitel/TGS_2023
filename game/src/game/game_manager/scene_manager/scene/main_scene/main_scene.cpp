#include "main_scene.h"
#include "../../../unit/unit.h"
#include "game/game_manager/game_manager.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	//背景のゲームオブジェクト生成
	(CBackGround*)aqua::CreateGameObject<CBackGround>(this);

	//タイマーのゲームオブジェクト生成
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//不正解ターゲットを10体生成
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
	}

	//正解ターゲットのゲームオブジェクト生成
	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);

	IGameObject::Initialize();
}

//更新
void CMainScene::Update(void)
{
	IGameObject::Update();
}

#include "main_scene.h"
#include "../../../enemy/enemy.h"
#include "../../../target/target.h"


//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	CTarget* target = aqua::CreateGameObject<CTarget>(this);
}

//更新
void CMainScene::Update(void)
{
}

//描画
void CMainScene::Draw(void)
{
	IGameObject::Draw();
}

//解放
void CMainScene::Finalize(void)
{
	IGameObject::Finalize();
}

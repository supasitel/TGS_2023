#include "title_scene.h"

//コンストラクタ
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//初期化
void CTitleScene::Initialize(void)
{
	m_BackGround.Create("data\\magic_circle.png");
}

//更新
void CTitleScene::Update(void)
{
	using namespace aqua::keyboard;

	if (Trigger(KEY_ID::SPACE))
	{
		Change(SCENE_ID::MAIN);
	}
}

//描画
void CTitleScene::Draw(void)
{
	m_BackGround.Draw();
}

//解放
void CTitleScene::Finalize(void)
{
	m_BackGround.Delete();
}

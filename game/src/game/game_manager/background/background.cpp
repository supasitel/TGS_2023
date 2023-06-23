#include "background.h"

//コンストラクタ
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BackGround")
{
}

//初期化
void CBackGround::Initialize(void)
{
	//背景生成
	m_BackGround.Create("data\\magic_circle.png");
	//背景の位置
	m_BackGround.position = aqua::CVector2::ZERO;
}

//描画
void CBackGround::Draw(void)
{
	m_BackGround.Draw();
}

//解放
void CBackGround::Finalize(void)
{
	m_BackGround.Delete();
}

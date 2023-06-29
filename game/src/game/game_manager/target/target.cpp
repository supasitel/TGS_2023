#include "target.h"

const int CTarget::m_width = 264;	//幅
const int CTarget::m_height = 300;	//高さ

//コンストラクタ
CTarget::CTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Target")
{
}

//初期化
void CTarget::Initialize(void)
{
	//ターゲット
	m_Target.Create("data\\cake.png");
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Target.GetTextureHeight() / 2.0f;
}

//更新
void CTarget::Update(void)
{
}

//描画
void CTarget::Draw(void)
{
	m_Target.Draw();
}

//解放
void CTarget::Finalize(void)
{
	m_Target.Delete();
}

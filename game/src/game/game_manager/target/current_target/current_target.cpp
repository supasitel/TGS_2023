#include "current_target.h"

const int CCurrentTarget::m_width = 100;	//幅
const int CCurrentTarget::m_height = 138;	//高さ
const unsigned int CCurrentTarget::m_default_color = 0xffffffff;
const unsigned int CCurrentTarget::m_clicked_color = 0xffeeffff;

//コンストラクタ
CCurrentTarget::CCurrentTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"CurrentTarget")
{
}

//初期化
void CCurrentTarget::Initialize(void)
{
	//ターゲット(正解)の生成
	m_CurrentTarget.Create("data\\current.png");
	//ターゲットの位置
	m_CurrentTarget.position.x = aqua::Rand(aqua::GetWindowWidth() - m_width);
	m_CurrentTarget.position.y = aqua::Rand(aqua::GetWindowHeight() - m_height);
}

//更新
void CCurrentTarget::Update(void)
{
	////aqua::mouseの省略
	//using namespace aqua::mouse;

	//aqua::CPoint mpos = GetCursorPos();

	////ターゲット(正解)上にカーソルがない場合
	//if (mpos.x<m_CurrentTarget.position.x && mpos.x>m_CurrentTarget.position.x + m_width ||
	//	mpos.y<m_CurrentTarget.position.y && mpos.y>m_CurrentTarget.position.y + m_height)
	//{
	//	SetColor(m_default_color);
	//	return;
	//}
	////ターゲット(正解)上にカーソルがある場合
	//else
	//{
	//	SetColor(m_default_color);
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{
	//		SetColor(m_clicked_color);
	//	}
	//}
}

//描画
void CCurrentTarget::Draw(void)
{
	m_CurrentTarget.Draw();
}

//解放
void CCurrentTarget::Finalize(void)
{
	m_CurrentTarget.Delete();
}

//色
void CCurrentTarget::SetColor(const aqua::CColor&& color)
{
	m_CurrentTarget.color = color;
}

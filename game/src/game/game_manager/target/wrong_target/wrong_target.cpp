#include "wrong_target.h"

const unsigned CWrongTarget::m_clicked_color = 0xffeeffff;	//クリック時の色
const unsigned CWrongTarget::m_default_color = 0xffffffff;	//選択前の色
const int CWrongTarget::m_width = 100;						//幅
const int CWrongTarget::m_height = 138;						//高さ

//コンストラクタ
CWrongTarget::CWrongTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "WrongTarget")
{
}

//初期化
void CWrongTarget::Initialize(void)
{
	//ターゲット（不正解）の生成
	m_WrongTarget.Create("data\\wrong.png");
	//生成位置
	m_WrongTarget.position.x = aqua::Rand(aqua::GetWindowWidth() - m_width);
	m_WrongTarget.position.y = aqua::Rand(aqua::GetWindowHeight() - m_height);
}

//更新
void CWrongTarget::Update(void)
{
	////aqua::mouseの省略
	//using namespace aqua::mouse;

	//aqua::CPoint mpos = GetCursorPos();

	////カーソルがターゲット(不正解)上にない場合
	//if (mpos.x<m_WrongTarget.position.x && mpos.x>m_WrongTarget.position.x + m_width ||
	//	mpos.y<m_WrongTarget.position.y && mpos.y>m_WrongTarget.position.y + m_height)
	//{
	//	//選択前の色にする
	//	SetColor(m_default_color);
	//	return;
	//}
	////カーソルがターゲット(不正解)上にある場合
	//else
	//{
	//	//選択前の色にする
	//	SetColor(m_default_color);

	//	//左ボタンを押したら選択後の色にする
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{
	//		SetColor(m_clicked_color);
	//	}
	//}
}

//描画
void CWrongTarget::Draw(void)
{
	m_WrongTarget.Draw();
}

//解放
void CWrongTarget::Finalize(void)
{
	m_WrongTarget.Delete();
}

//色
void CWrongTarget::SetColor(const aqua::CColor&& color)
{
	m_WrongTarget.color = color;
}

#include "game_over.h"

const int COver::m_width = 522;		//幅
const int COver::m_height = 100;	//高さ

//コンストラクタ
COver::COver(aqua::IGameObject* parent)
	:IScene(parent, "GameOverScene")
{
}

//初期化
void COver::Initialize(void)
{
	//メッセージ
	m_Message.Create(40, 2);
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.text = "タイトルに戻る";
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;

	//ゲームオーバー
	m_Over.Create(70, 2);
	m_Over.edge_color = aqua::CColor::BLACK;
	m_Over.text = "GameOver";
	m_Over.position = { 450,100 };

	//ボタン
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//背景
	m_BackGround.Create("data\\game_over.png");
	m_BackGround.position = aqua::CVector2::ZERO;
}

//更新
void COver::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	//マウスカーソルがボタンの外側にある場合
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//ボタン（発光）の削除
		m_ButtonBlack.Delete();

		//ボタンの可視化
		m_Button.visible = true;
	}
	else
	{
		//ボタンの不可視化
		m_Button.visible = false;

		//ボタン（発光）
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;
	
		//左ボタンを離したらタイトルに移行
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//描画
void COver::Draw(void)
{
	m_BackGround.Draw();
	m_Over.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//解放
void COver::Finalize(void)
{
	m_BackGround.Delete();
	m_Message.Delete();
	m_Over.Delete();
}

#include "game_clear.h"

const int CClearScene::m_width = 522;	//幅
const int CClearScene::m_height = 100;	//高さ

//コンストラクタ
CClearScene::CClearScene(aqua::IGameObject* parent)
	:IScene(parent, "ClearScene")
{
}

//初期化
void CClearScene::Initialize(void)
{
	//背景
	m_BackGround.Create("data\\green_ground.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//ゲームクリア
	m_Clear.Create(70, 2);
	m_Clear.edge_color = aqua::CColor::BLACK;
	m_Clear.text = "GameClear";
	m_Clear.position = { 450,250 };

	//ボタン
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//メッセージ
	m_Message.Create(40, 2);
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.text = "タイトルに戻る";
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;
}

//更新
void CClearScene::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	//マウスカーソルがボタンの外側にある場合
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//発光しているボタンの削除
		m_ButtonBlack.Delete();

		//ボタンを可視状態にする
		m_Button.visible = true;
	}
	else
	{
		//ボタンを不可視状態にする
		m_Button.visible = false;

		//発光しているボタン
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;

		//離したらタイトルに移行
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//描画
void CClearScene::Draw(void)
{
	m_BackGround.Draw();
	m_Clear.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//解放
void CClearScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Clear.Delete();
	m_Message.Delete();
}

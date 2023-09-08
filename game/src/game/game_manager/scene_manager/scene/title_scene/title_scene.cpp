#include "title_scene.h"
#include "../../scene_manager.h"

const int CTitleScene::m_width = 522;	//幅
const int CTitleScene::m_height = 100;	//高さ

//コンストラクタ
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent, "TitleScene")
{
}

//初期化
void CTitleScene::Initialize(void)
{
	//背景
	m_BackGround.Create("data\\title_ground.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//タイトル
	m_Title.Create(70, 2);
	m_Title.position.x = (float)aqua::GetWindowWidth() / 3.75f - (float)m_Title.GetTextWidth() / 3.75f;
	m_Title.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Title.GetFontHeight() / 4.0f;
	m_Title.text = "ペンギンの捕獲";

	//ボタン
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//メッセージ
	m_Message.Create(40, 2);
	m_Message.text = "ゲームを始める";
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;
}

//更新
void CTitleScene::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//マウスカーソル座標の取得
	aqua::CPoint mpos = GetCursorPos();

	//マウスカーソルが黒ボタンの外側にある場合
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//発光している黒ボタンの削除  
		m_ButtonBlack.Delete();

		//黒ボタンを可視状態にする
		m_Button.visible = true;
	}
	//マウスカーソルが黒ボタンの上にある場合
	else
	{
		//黒ボタンを不可視状態にする
		m_Button.visible = false;

		//発光している黒ボタンの生成
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - m_ButtonBlack.GetTextureHeight() / 1.25f;
		
		//左ボタンを離したらゲームメインに移行
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::EXPLANATION);
		}
	}
}

//描画
void CTitleScene::Draw(void)
{
	m_BackGround.Draw();
	m_Title.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//解放
void CTitleScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Title.Delete();
	m_Message.Delete();
}

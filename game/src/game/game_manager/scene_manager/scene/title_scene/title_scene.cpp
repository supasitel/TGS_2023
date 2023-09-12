#include "title_scene.h"
#include "../../scene_manager.h"

const int CTitleScene::m_width = 522;	//2種類のボタンの幅
const int CTitleScene::m_height = 100;	//2種類のボタンの高さ

//コンストラクタ
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent, "TitleScene")
{
}

//初期化
void CTitleScene::Initialize(void)
{
	//背景の生成
	m_BackGround.Create("data\\title_ground.png");
	//背景の位置
	m_BackGround.position = aqua::CVector2::ZERO;

	//タイトルの生成
	m_Title.Create(70, 2);
	//タイトルの位置
	m_Title.position.x = (float)aqua::GetWindowWidth() / 3.75f - (float)m_Title.GetTextWidth() / 3.75f;
	m_Title.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Title.GetFontHeight() / 4.0f;
	//タイトルテキスト
	m_Title.text = "ペンギンの捕獲";

	//ボタンの生成
	m_Button.Create("data\\button_black.png");
	//ボタンの位置
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//メッセージの生成
	m_Message.Create(40, 2);
	//メッセージテキスト
	m_Message.text = "ゲームを始める";
	//メッセージのエッジの色
	m_Message.edge_color = aqua::CColor::BLACK;
	//メッセージの位置
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

	//マウスカーソルがボタンの外側にある場合
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//発光しているボタンの削除  
		m_ButtonBlack.Delete();

		//ボタンを可視状態にする
		m_Button.visible = true;
	}
	//マウスカーソルが黒ボタンの上にある場合
	else
	{
		//ボタンを不可視状態にする
		m_Button.visible = false;

		//発光しているボタンの生成
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		//発光しているボタンの位置
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - m_ButtonBlack.GetTextureHeight() / 1.25f;
		
		//マウスの左ボタンを離したらルール説明シーンに変更
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::EXPLANATION);
		}
	}
}

//描画
void CTitleScene::Draw(void)
{
	//背景の描画
	m_BackGround.Draw();
	//タイトルの描画
	m_Title.Draw();
	//ボタンの描画
	m_Button.Draw();
	//ボタン(発光)の描画
	m_ButtonBlack.Draw();
	//メッセージの描画
	m_Message.Draw();
}

//解放
void CTitleScene::Finalize(void)
{
	//背景の解放
	m_BackGround.Delete();
	//タイトルの解放
	m_Title.Delete();
	//メッセージの解放
	m_Message.Delete();
}

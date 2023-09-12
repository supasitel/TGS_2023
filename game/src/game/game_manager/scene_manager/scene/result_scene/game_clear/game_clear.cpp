#include "game_clear.h"

const int CClearScene::m_width = 522;	//2種類のボタンの幅
const int CClearScene::m_height = 100;	//2種類のボタンの高さ

//コンストラクタ
CClearScene::CClearScene(aqua::IGameObject* parent)
	:IScene(parent, "ClearScene")
{
}

//初期化
void CClearScene::Initialize(void)
{
	//背景の生成
	m_BackGround.Create("data\\result_ground.png");
	//背景の位置
	m_BackGround.position = aqua::CVector2::ZERO;

	//ゲームクリアラベルの生成
	m_Clear.Create(70, 2);
	//ゲームクリアラベルのエッジの色
	m_Clear.edge_color = aqua::CColor::BLACK;
	//ゲームクリアラベルテキスト
	m_Clear.text = "GameClear";
	//ゲームクリアラベルの位置
	m_Clear.position = { 450,250 };

	//ボタンの生成
	m_Button.Create("data\\button_black.png");
	//ボタンの位置
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//メッセージの生成
	m_Message.Create(40, 2);
	//メッセージのエッジの色
	m_Message.edge_color = aqua::CColor::BLACK;
	//メッセージテキスト
	m_Message.text = "タイトルに戻る";
	//メッセージの位置
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;
}

//更新
void CClearScene::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;
	
	//マウス座標の取得
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

		//発光ボタンの生成
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		//発光ボタンの位置
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;

		//マウスの左ボタンを離したらタイトルシーンに変更
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//描画
void CClearScene::Draw(void)
{
	//背景の描画
	m_BackGround.Draw();
	//ゲームクリアラベルの描画
	m_Clear.Draw();
	//ボタンの描画
	m_Button.Draw();
	//発光ボタンの描画
	m_ButtonBlack.Draw();
	//メッセージの描画
	m_Message.Draw();
}

//解放
void CClearScene::Finalize(void)
{
	//背景の解放
	m_BackGround.Delete();
	//ゲームクリアラベルの解放
	m_Clear.Delete();
	//メッセージの解放
	m_Message.Delete();
}

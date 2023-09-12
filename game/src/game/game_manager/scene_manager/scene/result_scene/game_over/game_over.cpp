#include "game_over.h"

const int CGameOver::m_width = 522;		//2種類のボタンの幅
const int CGameOver::m_height = 100;	//2種類のボタンの高さ

//コンストラクタ
CGameOver::CGameOver(aqua::IGameObject* parent)
	:IScene(parent, "GameOverScene")
{
}

//初期化
void CGameOver::Initialize(void)
{
	//メッセージの生成
	m_Message.Create(40, 2);
	//メッセージのエッジの色
	m_Message.edge_color = aqua::CColor::BLACK;
	//メッセージテキスト
	m_Message.text = "タイトルに戻る";
	//メッセージの位置
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;

	//ゲームオーバーラベルの生成
	m_GameOver.Create(70, 2);
	//ゲームオーバーラベルのエッジの色
	m_GameOver.edge_color = aqua::CColor::BLACK;
	//ゲームオーバーラベルテキスト
	m_GameOver.text = "GameOver";
	//ゲームオーバーラベルの位置
	m_GameOver.position = { 450,100 };

	//ボタンの生成
	m_Button.Create("data\\button_black.png");
	//ボタンの位置
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//背景の生成
	m_BackGround.Create("data\\game_over.png");
	//背景の位置
	m_BackGround.position = aqua::CVector2::ZERO;
}

//更新
void CGameOver::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//マウス座標の取得
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

		//ボタン（発光）の生成
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		//ボタン（発光）の位置
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
void CGameOver::Draw(void)
{
	//背景の描画
	m_BackGround.Draw();
	//ゲームオーバーラベルの描画
	m_GameOver.Draw();
	//ボタンの描画
	m_Button.Draw();
	//ボタン（発光）の描画
	m_ButtonBlack.Draw();
	//メッセージの描画
	m_Message.Draw();
}

//解放
void CGameOver::Finalize(void)
{
	//背景の解放
	m_BackGround.Delete();
	//メッセージの解放
	m_Message.Delete();
	//ゲームオーバーラベルの解放
	m_GameOver.Delete();
}

#include "explanation_scene.h"

//コンストラクタ
CExplanationScene::CExplanationScene(aqua::IGameObject* parent)
	:IScene(parent, "Explanation")
{
}

//初期化
void CExplanationScene::Initialize(void)
{
	//背景の生成
	m_BackGround.Create("data\\explanation.png");
	//背景の位置
	m_BackGround.position = aqua::CVector2::ZERO;

	//説明ラベルの生成
	m_Explanation.Create(37, 2);
	//説明ラベルのエッジの色
	m_Explanation.edge_color = aqua::CColor::BLACK;
	//説明ラベルテキスト
	m_Explanation.text = "・制限時間内に下記のペンギンをクリックしたらゲームクリア!";
	//説明ラベルの位置
	m_Explanation.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Explanation.GetTextWidth() / 2.0f;
	m_Explanation.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Explanation.GetFontHeight() / 4.0f;

	//ペンギンの生成
	m_Target.Create("data\\current.png");
	//ペンギンの位置
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 1.75f - (float)m_Target.GetTextureHeight() / 1.75f;

	//メッセージの生成
	m_Message.Create(35, 2);
	//メッセージのエッジの色
	m_Message.edge_color = aqua::CColor::BLACK;
	//メッセージテキスト
	m_Message.text = "・左クリックしたらゲームが始まるよ";
	//メッセージの位置
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Message.GetTextWidth() / 2.0f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Message.GetFontHeight() / 1.25f;

}

//更新
void CExplanationScene::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//マウスの左ボタンを離したらゲームメインシーンの変更
	if (Released(BUTTON_ID::LEFT))
	{
		Change(SCENE_ID::MAIN);
	}
}

//描画
void CExplanationScene::Draw(void)
{
	//背景の描画
	m_BackGround.Draw();
	//説明ラベルの描画
	m_Explanation.Draw();
	//ペンギンの描画
	m_Target.Draw();
	//メッセージの描画
	m_Message.Draw();
}

//解放
void CExplanationScene::Finalize(void)
{
	//背景の解放
	m_BackGround.Delete();
	//説明ラベルの解放
	m_Explanation.Delete();
	//ペンギンの解放
	m_Target.Delete();
	//メッセージの解放
	m_Message.Draw();
}

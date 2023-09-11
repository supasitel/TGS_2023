#include "explanation_scene.h"

//コンストラクタ
CExplanationScene::CExplanationScene(aqua::IGameObject* parent)
	:IScene(parent, "Explanation")
{
}

//初期化
void CExplanationScene::Initialize(void)
{
	//背景
	m_BackGround.Create("data\\explanation.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//説明
	m_Explanation.Create(37, 2);
	m_Explanation.edge_color = aqua::CColor::BLACK;
	m_Explanation.text = "・制限時間内に下記のペンギンをクリックしたらゲームクリア!";
	m_Explanation.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Explanation.GetTextWidth() / 2.0f;
	m_Explanation.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Explanation.GetFontHeight() / 4.0f;

	//ペンギン
	m_Target.Create("data\\current.png");
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 1.75f - (float)m_Target.GetTextureHeight() / 1.75f;

	//メッセージ
	m_Label.Create(35, 2);
	m_Label.edge_color = aqua::CColor::BLACK;
	m_Label.text = "・左クリックしたらゲームが始まるよ";
	m_Label.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Label.GetTextWidth() / 2.0f;
	m_Label.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Label.GetFontHeight() / 1.25f;

}

//更新
void CExplanationScene::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//左ボタンを離したらメインシーンに移行
	if (Released(BUTTON_ID::LEFT))
	{
		Change(SCENE_ID::MAIN);
	}
}

//描画
void CExplanationScene::Draw(void)
{
	m_BackGround.Draw();
	m_Explanation.Draw();
	m_Target.Draw();
	m_Label.Draw();
}

//解放
void CExplanationScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Explanation.Delete();
	m_Target.Delete();
	m_Label.Draw();
}

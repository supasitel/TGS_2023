#include "explanation_scene.h"

//�R���X�g���N�^
CExplanationScene::CExplanationScene(aqua::IGameObject* parent)
	:IScene(parent, "Explanation")
{
}

//������
void CExplanationScene::Initialize(void)
{
	//�w�i
	m_BackGround.Create("data\\explanation.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//����
	m_Explanation.Create(37, 2);
	m_Explanation.edge_color = aqua::CColor::BLACK;
	m_Explanation.text = "�E�������ԓ��ɉ��L�̃y���M�����N���b�N������Q�[���N���A!";
	m_Explanation.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Explanation.GetTextWidth() / 2.0f;
	m_Explanation.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Explanation.GetFontHeight() / 4.0f;

	//�y���M��
	m_Target.Create("data\\current.png");
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 1.75f - (float)m_Target.GetTextureHeight() / 1.75f;

	//���b�Z�[�W
	m_Label.Create(35, 2);
	m_Label.edge_color = aqua::CColor::BLACK;
	m_Label.text = "�E���N���b�N������Q�[�����n�܂��";
	m_Label.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Label.GetTextWidth() / 2.0f;
	m_Label.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Label.GetFontHeight() / 1.25f;

}

//�X�V
void CExplanationScene::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//���{�^���𗣂����烁�C���V�[���Ɉڍs
	if (Released(BUTTON_ID::LEFT))
	{
		Change(SCENE_ID::MAIN);
	}
}

//�`��
void CExplanationScene::Draw(void)
{
	m_BackGround.Draw();
	m_Explanation.Draw();
	m_Target.Draw();
	m_Label.Draw();
}

//���
void CExplanationScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Explanation.Delete();
	m_Target.Delete();
	m_Label.Draw();
}

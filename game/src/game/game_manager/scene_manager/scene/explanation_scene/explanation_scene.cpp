#include "explanation_scene.h"

//�R���X�g���N�^
CExplanationScene::CExplanationScene(aqua::IGameObject* parent)
	:IScene(parent, "Explanation")
{
}

//������
void CExplanationScene::Initialize(void)
{
	//�w�i�̐���
	m_BackGround.Create("data\\explanation.png");
	//�w�i�̈ʒu
	m_BackGround.position = aqua::CVector2::ZERO;

	//�������x���̐���
	m_Explanation.Create(37, 2);
	//�������x���̃G�b�W�̐F
	m_Explanation.edge_color = aqua::CColor::BLACK;
	//�������x���e�L�X�g
	m_Explanation.text = "�E�������ԓ��ɉ��L�̃y���M�����N���b�N������Q�[���N���A!";
	//�������x���̈ʒu
	m_Explanation.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Explanation.GetTextWidth() / 2.0f;
	m_Explanation.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Explanation.GetFontHeight() / 4.0f;

	//�y���M���̐���
	m_Target.Create("data\\current.png");
	//�y���M���̈ʒu
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 1.75f - (float)m_Target.GetTextureHeight() / 1.75f;

	//���b�Z�[�W�̐���
	m_Message.Create(35, 2);
	//���b�Z�[�W�̃G�b�W�̐F
	m_Message.edge_color = aqua::CColor::BLACK;
	//���b�Z�[�W�e�L�X�g
	m_Message.text = "�E���N���b�N������Q�[�����n�܂��";
	//���b�Z�[�W�̈ʒu
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Message.GetTextWidth() / 2.0f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Message.GetFontHeight() / 1.25f;

}

//�X�V
void CExplanationScene::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//�}�E�X�̍��{�^���𗣂�����Q�[�����C���V�[���̕ύX
	if (Released(BUTTON_ID::LEFT))
	{
		Change(SCENE_ID::MAIN);
	}
}

//�`��
void CExplanationScene::Draw(void)
{
	//�w�i�̕`��
	m_BackGround.Draw();
	//�������x���̕`��
	m_Explanation.Draw();
	//�y���M���̕`��
	m_Target.Draw();
	//���b�Z�[�W�̕`��
	m_Message.Draw();
}

//���
void CExplanationScene::Finalize(void)
{
	//�w�i�̉��
	m_BackGround.Delete();
	//�������x���̉��
	m_Explanation.Delete();
	//�y���M���̉��
	m_Target.Delete();
	//���b�Z�[�W�̉��
	m_Message.Draw();
}

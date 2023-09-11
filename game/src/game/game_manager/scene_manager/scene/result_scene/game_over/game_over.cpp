#include "game_over.h"

const int COver::m_width = 522;		//��
const int COver::m_height = 100;	//����

//�R���X�g���N�^
COver::COver(aqua::IGameObject* parent)
	:IScene(parent, "GameOverScene")
{
}

//������
void COver::Initialize(void)
{
	//���b�Z�[�W
	m_Message.Create(40, 2);
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.text = "�^�C�g���ɖ߂�";
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;

	//�Q�[���I�[�o�[
	m_Over.Create(70, 2);
	m_Over.edge_color = aqua::CColor::BLACK;
	m_Over.text = "GameOver";
	m_Over.position = { 450,100 };

	//�{�^��
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//�w�i
	m_BackGround.Create("data\\game_over.png");
	m_BackGround.position = aqua::CVector2::ZERO;
}

//�X�V
void COver::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	//�}�E�X�J�[�\�����{�^���̊O���ɂ���ꍇ
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//�{�^���i�����j�̍폜
		m_ButtonBlack.Delete();

		//�{�^���̉���
		m_Button.visible = true;
	}
	else
	{
		//�{�^���̕s����
		m_Button.visible = false;

		//�{�^���i�����j
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;
	
		//���{�^���𗣂�����^�C�g���Ɉڍs
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//�`��
void COver::Draw(void)
{
	m_BackGround.Draw();
	m_Over.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//���
void COver::Finalize(void)
{
	m_BackGround.Delete();
	m_Message.Delete();
	m_Over.Delete();
}

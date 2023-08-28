#include "game_clear.h"

const int CClearScene::m_width = 522;	//��
const int CClearScene::m_height = 100;	//����

//�R���X�g���N�^
CClearScene::CClearScene(aqua::IGameObject* parent)
	:IScene(parent, "ClearScene")
{
}

//������
void CClearScene::Initialize(void)
{
	//�w�i
	m_BackGround.Create("data\\green_ground.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//�Q�[���N���A
	m_Clear.Create(70, 2);
	m_Clear.edge_color = aqua::CColor::BLACK;
	m_Clear.text = "GameClear";
	m_Clear.position = { 450,250 };

	//�{�^��
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//���b�Z�[�W
	m_Message.Create(40, 2);
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.text = "�^�C�g���ɖ߂�";
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;
}

//�X�V
void CClearScene::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	//�}�E�X�J�[�\�����{�^���̊O���ɂ���ꍇ
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//�������Ă���{�^���̍폜
		m_ButtonBlack.Delete();

		//�{�^��������Ԃɂ���
		m_Button.visible = true;
	}
	else
	{
		//�{�^����s����Ԃɂ���
		m_Button.visible = false;

		//�������Ă���{�^��
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;

		//��������^�C�g���Ɉڍs
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//�`��
void CClearScene::Draw(void)
{
	m_BackGround.Draw();
	m_Clear.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//���
void CClearScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Clear.Delete();
	m_Message.Delete();
}

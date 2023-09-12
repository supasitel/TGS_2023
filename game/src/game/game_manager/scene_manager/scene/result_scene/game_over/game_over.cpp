#include "game_over.h"

const int CGameOver::m_width = 522;		//2��ނ̃{�^���̕�
const int CGameOver::m_height = 100;	//2��ނ̃{�^���̍���

//�R���X�g���N�^
CGameOver::CGameOver(aqua::IGameObject* parent)
	:IScene(parent, "GameOverScene")
{
}

//������
void CGameOver::Initialize(void)
{
	//���b�Z�[�W�̐���
	m_Message.Create(40, 2);
	//���b�Z�[�W�̃G�b�W�̐F
	m_Message.edge_color = aqua::CColor::BLACK;
	//���b�Z�[�W�e�L�X�g
	m_Message.text = "�^�C�g���ɖ߂�";
	//���b�Z�[�W�̈ʒu
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;

	//�Q�[���I�[�o�[���x���̐���
	m_GameOver.Create(70, 2);
	//�Q�[���I�[�o�[���x���̃G�b�W�̐F
	m_GameOver.edge_color = aqua::CColor::BLACK;
	//�Q�[���I�[�o�[���x���e�L�X�g
	m_GameOver.text = "GameOver";
	//�Q�[���I�[�o�[���x���̈ʒu
	m_GameOver.position = { 450,100 };

	//�{�^���̐���
	m_Button.Create("data\\button_black.png");
	//�{�^���̈ʒu
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//�w�i�̐���
	m_BackGround.Create("data\\game_over.png");
	//�w�i�̈ʒu
	m_BackGround.position = aqua::CVector2::ZERO;
}

//�X�V
void CGameOver::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//�}�E�X���W�̎擾
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

		//�{�^���i�����j�̐���
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		//�{�^���i�����j�̈ʒu
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_ButtonBlack.GetTextureHeight() / 1.25f;
	
		//�}�E�X�̍��{�^���𗣂�����^�C�g���V�[���ɕύX
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::TITLE);
		}
	}
}

//�`��
void CGameOver::Draw(void)
{
	//�w�i�̕`��
	m_BackGround.Draw();
	//�Q�[���I�[�o�[���x���̕`��
	m_GameOver.Draw();
	//�{�^���̕`��
	m_Button.Draw();
	//�{�^���i�����j�̕`��
	m_ButtonBlack.Draw();
	//���b�Z�[�W�̕`��
	m_Message.Draw();
}

//���
void CGameOver::Finalize(void)
{
	//�w�i�̉��
	m_BackGround.Delete();
	//���b�Z�[�W�̉��
	m_Message.Delete();
	//�Q�[���I�[�o�[���x���̉��
	m_GameOver.Delete();
}

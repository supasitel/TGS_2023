#include "title_scene.h"
#include "../../scene_manager.h"

const int CTitleScene::m_width = 522;	//��
const int CTitleScene::m_height = 100;	//����

//�R���X�g���N�^
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent, "TitleScene")
{
}

//������
void CTitleScene::Initialize(void)
{
	//�w�i
	m_BackGround.Create("data\\title_ground.png");
	m_BackGround.position = aqua::CVector2::ZERO;

	//�^�C�g��
	m_Title.Create(70, 2);
	m_Title.position.x = (float)aqua::GetWindowWidth() / 3.75f - (float)m_Title.GetTextWidth() / 3.75f;
	m_Title.position.y = (float)aqua::GetWindowHeight() / 4.0f - (float)m_Title.GetFontHeight() / 4.0f;
	m_Title.text = "�y���M���̕ߊl";

	//�{�^��
	m_Button.Create("data\\button_black.png");
	m_Button.position.x = (float)aqua::GetWindowWidth() / 2.5f - (float)m_Button.GetTextureWidth() / 2.5f;
	m_Button.position.y = (float)aqua::GetWindowHeight() / 1.25f - (float)m_Button.GetTextureHeight() / 1.25f;

	//���b�Z�[�W
	m_Message.Create(40, 2);
	m_Message.text = "�Q�[�����n�߂�";
	m_Message.edge_color = aqua::CColor::BLACK;
	m_Message.position.x = (float)aqua::GetWindowWidth() / 2.35f - (float)m_Message.GetTextWidth() / 2.35f;
	m_Message.position.y = (float)aqua::GetWindowHeight() / 1.33f - (float)m_Message.GetFontHeight() / 1.33f;
}

//�X�V
void CTitleScene::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//�}�E�X�J�[�\�����W�̎擾
	aqua::CPoint mpos = GetCursorPos();

	//�}�E�X�J�[�\�������{�^���̊O���ɂ���ꍇ
	if (mpos.x<m_Button.position.x || mpos.x>m_Button.position.x + m_width ||
		mpos.y<m_Button.position.y || mpos.y>m_Button.position.y + m_height)
	{
		//�������Ă��鍕�{�^���̍폜  
		m_ButtonBlack.Delete();

		//���{�^��������Ԃɂ���
		m_Button.visible = true;
	}
	//�}�E�X�J�[�\�������{�^���̏�ɂ���ꍇ
	else
	{
		//���{�^����s����Ԃɂ���
		m_Button.visible = false;

		//�������Ă��鍕�{�^���̐���
		m_ButtonBlack.Create("data\\button_black_hakkou.png");
		m_ButtonBlack.position.x = (float)aqua::GetWindowWidth() / 2.5f - m_ButtonBlack.GetTextureWidth() / 2.5f;
		m_ButtonBlack.position.y = (float)aqua::GetWindowHeight() / 1.25f - m_ButtonBlack.GetTextureHeight() / 1.25f;
		
		//���{�^���𗣂�����Q�[�����C���Ɉڍs
		if (Released(BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::EXPLANATION);
		}
	}
}

//�`��
void CTitleScene::Draw(void)
{
	m_BackGround.Draw();
	m_Title.Draw();
	m_Button.Draw();
	m_ButtonBlack.Draw();
	m_Message.Draw();
}

//���
void CTitleScene::Finalize(void)
{
	m_BackGround.Delete();
	m_Title.Delete();
	m_Message.Delete();
}

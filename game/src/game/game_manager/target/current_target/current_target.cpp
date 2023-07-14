#include "current_target.h"

const int CCurrentTarget::m_width = 100;	//��
const int CCurrentTarget::m_height = 138;	//����
const unsigned int CCurrentTarget::m_default_color = 0xffffffff;
const unsigned int CCurrentTarget::m_clicked_color = 0xffeeffff;

//�R���X�g���N�^
CCurrentTarget::CCurrentTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"CurrentTarget")
{
}

//������
void CCurrentTarget::Initialize(void)
{
	//�^�[�Q�b�g(����)�̐���
	m_CurrentTarget.Create("data\\current.png");
	//�^�[�Q�b�g�̈ʒu
	m_CurrentTarget.position.x = aqua::Rand(aqua::GetWindowWidth() - m_width);
	m_CurrentTarget.position.y = aqua::Rand(aqua::GetWindowHeight() - m_height);
}

//�X�V
void CCurrentTarget::Update(void)
{
	////aqua::mouse�̏ȗ�
	//using namespace aqua::mouse;

	//aqua::CPoint mpos = GetCursorPos();

	////�^�[�Q�b�g(����)��ɃJ�[�\�����Ȃ��ꍇ
	//if (mpos.x<m_CurrentTarget.position.x && mpos.x>m_CurrentTarget.position.x + m_width ||
	//	mpos.y<m_CurrentTarget.position.y && mpos.y>m_CurrentTarget.position.y + m_height)
	//{
	//	SetColor(m_default_color);
	//	return;
	//}
	////�^�[�Q�b�g(����)��ɃJ�[�\��������ꍇ
	//else
	//{
	//	SetColor(m_default_color);
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{
	//		SetColor(m_clicked_color);
	//	}
	//}
}

//�`��
void CCurrentTarget::Draw(void)
{
	m_CurrentTarget.Draw();
}

//���
void CCurrentTarget::Finalize(void)
{
	m_CurrentTarget.Delete();
}

//�F
void CCurrentTarget::SetColor(const aqua::CColor&& color)
{
	m_CurrentTarget.color = color;
}

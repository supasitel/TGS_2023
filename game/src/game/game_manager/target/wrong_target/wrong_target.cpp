#include "wrong_target.h"

const unsigned CWrongTarget::m_clicked_color = 0xffeeffff;	//�N���b�N���̐F
const unsigned CWrongTarget::m_default_color = 0xffffffff;	//�I��O�̐F
const int CWrongTarget::m_width = 100;						//��
const int CWrongTarget::m_height = 138;						//����

//�R���X�g���N�^
CWrongTarget::CWrongTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "WrongTarget")
{
}

//������
void CWrongTarget::Initialize(void)
{
	//�^�[�Q�b�g�i�s�����j�̐���
	m_WrongTarget.Create("data\\wrong.png");
	//�����ʒu
	m_WrongTarget.position.x = aqua::Rand(aqua::GetWindowWidth() - m_width);
	m_WrongTarget.position.y = aqua::Rand(aqua::GetWindowHeight() - m_height);
}

//�X�V
void CWrongTarget::Update(void)
{
	////aqua::mouse�̏ȗ�
	//using namespace aqua::mouse;

	//aqua::CPoint mpos = GetCursorPos();

	////�J�[�\�����^�[�Q�b�g(�s����)��ɂȂ��ꍇ
	//if (mpos.x<m_WrongTarget.position.x && mpos.x>m_WrongTarget.position.x + m_width ||
	//	mpos.y<m_WrongTarget.position.y && mpos.y>m_WrongTarget.position.y + m_height)
	//{
	//	//�I��O�̐F�ɂ���
	//	SetColor(m_default_color);
	//	return;
	//}
	////�J�[�\�����^�[�Q�b�g(�s����)��ɂ���ꍇ
	//else
	//{
	//	//�I��O�̐F�ɂ���
	//	SetColor(m_default_color);

	//	//���{�^������������I����̐F�ɂ���
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{
	//		SetColor(m_clicked_color);
	//	}
	//}
}

//�`��
void CWrongTarget::Draw(void)
{
	m_WrongTarget.Draw();
}

//���
void CWrongTarget::Finalize(void)
{
	m_WrongTarget.Delete();
}

//�F
void CWrongTarget::SetColor(const aqua::CColor&& color)
{
	m_WrongTarget.color = color;
}

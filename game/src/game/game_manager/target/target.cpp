#include "target.h"

const int CTarget::m_width = 264;	//��
const int CTarget::m_height = 300;	//����

//�R���X�g���N�^
CTarget::CTarget(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Target")
{
}

//������
void CTarget::Initialize(void)
{
	//�^�[�Q�b�g
	m_Target.Create("data\\cake.png");
	m_Target.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Target.GetTextureWidth() / 2.0f;
	m_Target.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Target.GetTextureHeight() / 2.0f;
}

//�X�V
void CTarget::Update(void)
{
}

//�`��
void CTarget::Draw(void)
{
	m_Target.Draw();
}

//���
void CTarget::Finalize(void)
{
	m_Target.Delete();
}

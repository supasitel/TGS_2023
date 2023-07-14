#include "target.h"

//�R���X�g���N�^
ITarget::ITarget(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, "Target")
	, m_Width(0), m_Height(0), m_Radius(0.0f), m_Velocity(aqua::CVector2::ZERO)
{
}

//������
void ITarget::Initialize(void)
{
	m_Position = aqua::CVector2::ZERO;

	m_Velocity = aqua::CVector2::ZERO;
}

//�X�V
void ITarget::Update(void)
{
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	m_Position += m_Velocity * aqua::GetDeltaTime();

	//if (m_Position.x > mpos.x && m_Position.x < mpos.x + m_Width ||
	//	m_Position.y > mpos.y && m_Position.x < mpos.y + m_Height)
	//{
	//	return;
	//}
	//else
	//{
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{

	//	}
	//}

	CheckHitWall();

}

//�`��
void ITarget::Draw(void)
{

}

//���
void ITarget::Finalize(void)
{
}

//���̎擾
int ITarget::GetWidth(void)
{
	return m_Width;
}

//�����̎擾
int ITarget::GetHeight(void)
{
	return m_Height;
}

//�����蔼�a�̎擾
float ITarget::GetRadius(void)
{
	return m_Radius;
}

//���S�ʒu�̎擾
//aqua::CVector2 ITarget::GetCenterPosition(void)
//{
//	return aqua::CVector2();
//}

//�ǔ���
void ITarget::CheckHitWall(void)
{
	//���̌v�Z
	const int width = (float)(aqua::GetWindowWidth() - m_Width);
	//�����̌v�Z
	const int height = (float)(aqua::GetWindowHeight() - m_Height);

	//��̕ǔ���
	if (m_Position.x < 0.0f)
	{
		m_Position.x = 0.0f - m_Position.x;

		m_Velocity.x *= -1.0f;
	}
	//���̕ǔ���
	if (m_Position.x > width)
	{
		m_Position.x = width - (m_Position.x - width);

		m_Velocity.x *= -1.0f;
	}
	//���̕ǔ���
	if (m_Position.y < 0.0f)
	{
		m_Position.y = 0.0f - m_Position.y;

		m_Velocity.y *= -1.0f;
	}
	//�E�̕ǔ���
	if (m_Position.y > height)
	{
		m_Position.y = height - (m_Position.y - height);

		m_Velocity.y *= -1.0f;
	}
}
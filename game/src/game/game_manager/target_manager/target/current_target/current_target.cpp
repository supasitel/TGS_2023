#include "current_target.h"

const std::string CCurrentTarget::m_category = "Target";	//�J�e�S���[
const std::string CCurrentTarget::m_name = "CurrentTarget";	//���O
const float CCurrentTarget::m_one_timer = 1.0f;				//1�b
const float CCurrentTarget::m_max_speed = 100.0f;			//�ō����x
const float CCurrentTarget::m_min_speed = 20.0f;			//�Œᑬ�x

//�R���X�g���N�^
CCurrentTarget::CCurrentTarget(aqua::IGameObject* parent)
	:IUnit(parent, m_name, m_category)
	, m_Width(100.0f), m_Height(138.0f), m_CurrentTarget_Count(1)
{
}

//������
void CCurrentTarget::Initialize(void)
{
	//�����^�[�Q�b�g�̐���
	m_CurrentTarget.Create("data\\current.png");

	//�ʒu�̑��
	m_Position = m_CurrentTarget.position;

	//�����_���̈ʒu�ɐ���
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//��]�̊�_
	m_CurrentTarget.anchor.x = (float)m_CurrentTarget.GetTextureWidth() / 2.0f;
	m_CurrentTarget.anchor.y = (float)m_CurrentTarget.GetTextureHeight() / 2.0f;

	//�`��͈�
	m_CurrentTarget.rect.top = 0;
	m_CurrentTarget.rect.left = 0;
	m_CurrentTarget.rect.bottom = m_CurrentTarget.rect.top + aqua::GetWindowHeight();
	m_CurrentTarget.rect.right = m_CurrentTarget.rect.left + aqua::GetWindowWidth();

	//�����蔼�a
	m_HitRadius = (float)m_CurrentTarget.GetTextureWidth() / 3.0f;

	//���x
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//�X�V
void CCurrentTarget::Update(void)
{
	CheckHitMouse();

	//�ʒu�̌v�Z
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_CurrentTarget.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_CurrentTarget.GetTextureHeight();

	//�ǔ���
	if (m_Position.x < 0.0f)
	{
		m_Position.x = 0.1f - m_Position.x;
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.x > w)
	{
		m_Position.x = w - (m_Position.x - w);
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.y < 0.0f)
	{
		m_Position.y = 0.1f - m_Position.y;
		m_Velocity.y *= -1.0f;
	}
	if (m_Position.y > h)
	{
		m_Position.y = h - (m_Position.y - h);
		m_Velocity.y *= -1.0f;
	}

	m_CurrentTarget.position = m_Position;

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

//�}�E�X����
void CCurrentTarget::CheckHitMouse(void)
{
	//if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	//{
	//}
	aqua::CPoint p = aqua::mouse::GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_CurrentTarget.position + aqua::CVector2(m_CurrentTarget.GetTextureWidth() / 2.0f, m_CurrentTarget.GetTextureHeight() / 3.0f) - mpos;

}

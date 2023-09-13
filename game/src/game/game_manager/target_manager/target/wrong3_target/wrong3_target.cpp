#include "wrong3_target.h"
#include "../../../sound_manager/sound_manager.h"

const std::string CWrong3::m_name = "Wrong3";
const std::string CWrong3::m_category = "Wrong3Target";
const int CWrong3::m_width = 100;
const int CWrong3::m_height = 137;
const float CWrong3::m_one_timer = 1.0f;				//1�b
const float CWrong3::m_max_speed = 100.0f;				//�ō����x
const float CWrong3::m_min_speed = 20.0f;				//�Œᑬ�x

//�R���X�g���N�^
CWrong3::CWrong3(aqua::IGameObject* parent)
	:IUnit(parent,m_name,m_category)
{
}

//������
void CWrong3::Initialize(void)
{
	//�^�[�Q�b�g(�͂���)�̐���
	m_Wrong3.Create("data\\wrong3.png");
	//�^�[�Q�b�g�̈ʒu
	m_Position = m_Wrong3.position;
	//�����_���Ȉʒu�ɐ���
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//��]�̊�_
	m_Wrong3.anchor.x = (float)m_Wrong3.GetTextureWidth() / 2.0f;
	m_Wrong3.anchor.y = (float)m_Wrong3.GetTextureHeight() / 2.0f;

	//�`��͈�
	m_Wrong3.rect.top = 0;
	m_Wrong3.rect.left = 0;
	m_Wrong3.rect.bottom = m_Wrong3.rect.top + aqua::GetWindowHeight();
	m_Wrong3.rect.right = m_Wrong3.rect.left + aqua::GetWindowWidth();

	//�����蔼�a�̌v�Z
	m_HitRadius = (float)m_Wrong3.GetTextureWidth() / 3.0f;

	//���x�̌v�Z
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//�X�V
void CWrong3::Update(void)
{
	CheckHitMouse();

	//�ʒu�̌v�Z
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_Wrong3.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_Wrong3.GetTextureHeight();

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
	m_Wrong3.position = m_Position;

}

//�`��
void CWrong3::Draw(void)
{
}

//���
void CWrong3::Finalize(void)
{
}

//�}�E�X����
void CWrong3::CheckHitMouse(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//���N���b�N������^�[�Q�b�g�N���b�N���̃T�E���h���Đ�
	if (Trigger(BUTTON_ID::LEFT))
	{
		CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

		if (sound)sound->Play(SOUND_ID::TCLICK);
	}

	aqua::CPoint p = GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_Wrong3.position + aqua::CVector2(m_Wrong3.GetTextureWidth() / 2.0f, m_Wrong3.GetTextureHeight() / 3.0f) - mpos;
}

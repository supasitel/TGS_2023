#include "wrong2_target.h"
#include "../../../sound_manager/sound_manager.h"

const std::string CWrong2::m_name = "Wrong2";			//���O
const std::string CWrong2::m_category = "Wrong2Target";	//�J�e�S���[
const int CWrong2::m_width = 100;						//��
const int CWrong2::m_height = 137;						//����
const float CWrong2::m_one_timer = 1.0f;				//1�b
const float CWrong2::m_max_speed = 100.0f;				//�ō����x
const float CWrong2::m_min_speed = 20.0f;				//�Œᑬ�x

//�R���X�g���N�^
CWrong2::CWrong2(aqua::IGameObject* parent)
	:IUnit(parent,m_name,m_category)
	,m_Width(m_width),m_Height(m_height)
{
}

//������
void CWrong2::Initialize(void)
{
	//�^�[�Q�b�g�i�͂���j�̐���
	m_Wrong2.Create("data\\wrong2.png");
	//�^�[�Q�b�g�̈ʒu
	m_Position = m_Wrong2.position;
	//�����_���Ȉʒu�ɐ���
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//��]�̊�_
	m_Wrong2.anchor.x = (float)m_Wrong2.GetTextureWidth() / 2.0f;
	m_Wrong2.anchor.y = (float)m_Wrong2.GetTextureHeight() / 2.0f;

	//�`��͈�
	m_Wrong2.rect.top = 0;
	m_Wrong2.rect.left = 0;
	m_Wrong2.rect.bottom = m_Wrong2.rect.top + aqua::GetWindowHeight();
	m_Wrong2.rect.right = m_Wrong2.rect.left + aqua::GetWindowWidth();

	//�����蔼�a�̌v�Z
	m_HitRadius = (float)m_Wrong2.GetTextureWidth() / 3.0f;

	//���x�̌v�Z
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));

}

//�X�V
void CWrong2::Update(void)
{
	CheckHitMouse();

	//�ʒu�̌v�Z
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_Wrong2.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_Wrong2.GetTextureHeight();

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
	m_Wrong2.position = m_Position;
}

//�`��
void CWrong2::Draw(void)
{
	m_Wrong2.Draw();
}

//���
void CWrong2::Finalize(void)
{
	m_Wrong2.Delete();
}

void CWrong2::CheckHitMouse(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//���N���b�N������^�[�Q�b�g�N���b�N���̃T�E���h���Đ�
	if (Trigger(BUTTON_ID::LEFT))
	{
		CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

		if (sound)sound->Play(SOUND_ID::TCLICK);
	}

	aqua::CPoint p= GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_Wrong2.position + aqua::CVector2(m_Wrong2.GetTextureWidth() / 2.0f, m_Wrong2.GetTextureHeight() / 3.0f) - mpos;

}

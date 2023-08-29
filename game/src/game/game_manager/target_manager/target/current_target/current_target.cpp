#include "current_target.h"

const std::string CCurrentTarget::m_category = "CurrentTarget";	//�J�e�S���[
const std::string CCurrentTarget::m_name = "Current";			//���O
const float CCurrentTarget::m_one_timer = 1.0f;					//1�b
const float CCurrentTarget::m_max_speed = 100.0f;				//�ō����x
const float CCurrentTarget::m_min_speed = 20.0f;				//�Œᑬ�x
const int   CCurrentTarget::m_width = 100.0f;					//��
const int   CCurrentTarget::m_height = 138.0f;					//����

//�R���X�g���N�^
CCurrentTarget::CCurrentTarget(aqua::IGameObject* parent)
	:IUnit(parent, m_name, m_category)
	, m_Width(m_width), m_Height(m_height), m_CurrentTarget_Count(1)
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
	//aqua::mouse�̏ȗ���
	using namespace aqua::mouse;

	//�}�E�X�̍��W�擾
	aqua::CPoint mpos = GetCursorPos();

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

	//�}�E�X�J�[�\�����O���ɂ���ꍇ
	if (mpos.x<m_CurrentTarget.position.x || mpos.x>m_CurrentTarget.position.x + m_width ||
		mpos.y<m_CurrentTarget.position.y || mpos.y>m_CurrentTarget.position.y + m_height)
	{
	}
	else
	{
		//�����^�[�Q�b�g���N���b�N������Q�[���N���A�V�[���Ɉڍs
		if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
		{
			((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::CLEAR);
		}
	}
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
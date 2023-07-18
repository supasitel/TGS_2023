#include "wrong_target.h"

const std::string CWrongTarget::m_name = "WrongTarget";	//���O
const std::string CWrongTarget::m_category = "Target";	//�J�e�S���[
const float CWrongTarget::m_one_timer = 1.0f;			//1�b
const float CWrongTarget::m_max_speed = 100.0f;			//�ō����x
const float CWrongTarget::m_min_speed = 20.0f;			//�Œᑬ�x

//�R���X�g���N�^
CWrongTarget::CWrongTarget(aqua::IGameObject* parent)
	:IUnit(parent, m_name, m_category)
	, m_Width(100.0f), m_Height(138.0f), m_WrongTarget_Count(10)
{
}

//������
void CWrongTarget::Initialize(void)
{
	//�s�����^�[�Q�b�g�̐���
	m_WrongTarget.Create("data\\wrong.png");

	//�ʒu�̑��
	m_Position = m_WrongTarget.position;

	//�����_���Ȉʒu�ɐ���
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//��]�̊�_�̌v�Z
	m_WrongTarget.anchor.x = (float)m_WrongTarget.GetTextureWidth() / 2.0f;
	m_WrongTarget.anchor.y = (float)m_WrongTarget.GetTextureHeight() / 2.0f;

	m_WrongTarget.rect.top = 0;
	m_WrongTarget.rect.left = 0;
	m_WrongTarget.rect.bottom = m_WrongTarget.rect.top + aqua::GetWindowHeight();
	m_WrongTarget.rect.right = m_WrongTarget.rect.left + aqua::GetWindowWidth();

	//�����蔼�a�̌v�Z
	m_HitRadius = (float)m_WrongTarget.GetTextureWidth() / 3.0f;

	//���x�̌v�Z
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//�X�V
void CWrongTarget::Update(void)
{
	//�ǔ���
	CheckHitWall();

	//�ʒu�̌v�Z
	m_Position += m_Velocity * aqua::GetDeltaTime();

	m_WrongTarget.position = m_Position;
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

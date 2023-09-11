#include "start_message.h"

const float CStartMessage::m_min_scale = 0.0f;		//�ŏ��g�嗦
const float CStartMessage::m_max_scale = 1.5f;		//�ő�g�嗦
const float CStartMessage::m_easing_time = 1.5f;	//�C�[�W���O����
const float CStartMessage::m_view_time = 2.0f;		//���b�Z�[�W�\������

//�R���X�g���N�^
CStartMessage::CStartMessage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StartMessage")
	, m_ElapsedTime(0.0f)
{
}

//������
void CStartMessage::Initialize(void)
{
	//�X�^�[�g���b�Z�[�W
	m_StartMessage.Create("data\\start.png");
	m_StartMessage.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_StartMessage.GetTextureWidth() / 2.0f;
	m_StartMessage.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_StartMessage.GetTextureHeight() / 2.0f;
	m_StartMessage.anchor.x = (float)m_StartMessage.GetTextureWidth() / 2.0f;
	m_StartMessage.anchor.y = (float)m_StartMessage.GetTextureHeight() / 2.0f;
	m_StartMessage.scale = aqua::CVector2::ZERO;
}

//�X�V
void CStartMessage::Update(void)
{
	//�o�ߎ��ԂɃf���^�^�C���̉��Z
	m_ElapsedTime += aqua::GetDeltaTime();

	//�o�ߎ��Ԃ����b�Z�[�W�\�����Ԃ𒴂�����X�^�[�g���b�Z�[�W���폜
	if (m_ElapsedTime > m_view_time)
	{
		DeleteObject();
	}

	//�g�嗦�̎���
	float time = m_ElapsedTime > m_easing_time ? m_easing_time : m_ElapsedTime;

	//�g�嗦�̃p�����[�^
	float scale = abs(aqua::easing::OutBack(time, m_easing_time, m_min_scale, m_max_scale));

	//�X�^�[�g���b�Z�[�W�̊g�嗦
	m_StartMessage.scale = aqua::CVector2(scale, scale);

}

//�`��
void CStartMessage::Draw(void)
{
	m_StartMessage.Draw();
}

//���
void CStartMessage::Finalize(void)
{
	m_StartMessage.Delete();
}

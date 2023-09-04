#include "finish_message.h"

const float CFinishMessage::m_min_scale = 0.0f;		//�ŏ��g�嗦
const float CFinishMessage::m_max_scale = 1.5f;		//�ő�g�嗦
const float CFinishMessage::m_easing_time = 1.5f;	//�C�[�W���O����
const float CFinishMessage::m_view_time = 2.5f;		//���b�Z�[�W�\������

//�R���X�g���N�^
CFinishMessage::CFinishMessage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "FinishMessage")
	,m_ElapsedTime(0.0f)
{
}

//������
void CFinishMessage::Initialize(void)
{
	//�I�����b�Z�[�W
	m_FinishMessage.Create("data\\finish.png");
	m_FinishMessage.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_FinishMessage.GetTextureWidth() / 2.0f;
	m_FinishMessage.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_FinishMessage.GetTextureHeight() / 2.0f;
	m_FinishMessage.anchor.x = (float)m_FinishMessage.GetTextureWidth() / 2.0f;
	m_FinishMessage.anchor.y = (float)m_FinishMessage.GetTextureHeight() / 2.0f;
	m_FinishMessage.scale = aqua::CVector2::ZERO;
}

//�X�V
void CFinishMessage::Update(void)
{
	//�o�ߎ��ԂɃf���^�^�C�������Z
	m_ElapsedTime += aqua::GetDeltaTime();

	//�o�ߎ��Ԃ����b�Z�[�W�\�����Ԃ𒴂�����I�����b�Z�[�W���폜
	if (m_ElapsedTime > m_view_time)
	{
		DeleteObject();
	}

	//�g�嗦�̎���
	float time = m_ElapsedTime > m_easing_time ? m_easing_time : m_ElapsedTime;

	//�g�嗦�̃p�����[�^
	float scale = abs(aqua::easing::OutBack(time, m_easing_time, m_min_scale, m_max_scale));

	//�I�����b�Z�[�W�̊g�嗦
	m_FinishMessage.scale = aqua::CVector2(scale, scale);
}

//�`��
void CFinishMessage::Draw(void)
{
	m_FinishMessage.Draw();
}

//���
void CFinishMessage::Finalize(void)
{
	m_FinishMessage.Delete();
}

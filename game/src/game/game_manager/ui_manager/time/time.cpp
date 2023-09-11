#include "time.h"
#include "../../message/finish_message/finish_message.h"

const int	CTime::m_default_time_limit = 3;	//��������
const float CTime::m_one_timer = 1.0f;//1�b

//�R���X�g���N�^
CTime::CTime(aqua::IGameObject* parent)
	:IUIManager(parent, "Time")
{
}

//������
void CTime::Initialize(void)
{
	//�e�L�X�g�̐���
	m_TimerLabel.Create(40, 2);

	//1�b�^�C�}�[���Z�b�g
	m_OneTimer.Setup(m_one_timer);

	//�^�C�����~�b�g�ɐ������Ԃ���
	m_TimeLimit = m_default_time_limit;

}

//�X�V
void CTime::Update(void)
{
	//�I����������A�Ԃ�
	if (Finished())
		return;

	//1�b�^�C�}�[�̍X�V
	m_OneTimer.Update();

	//1�b�^�C�}�[���I��
	if (m_OneTimer.Finished())
	{
		//�^�C�}�[���Z�b�g
		m_OneTimer.Reset();

		//�P�b���������Ԃ������Ă���
		--m_TimeLimit;
	}

	//�������Ԃ�0�b�ɂȂ�����
	if (m_TimeLimit == 0)
	{

		//�Q�[���I�[�o�[�V�[���Ɉڍs
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::OVER);

	}

}

//�`��
void CTime::Draw(void)
{
	//�^�C�}�[�e�L�X�g
	m_TimerLabel.text = "�c��" + std::to_string(m_TimeLimit) + "�b";

	//���[�܁[�e�L�X�g�̈ʒu
	m_TimerLabel.position = { 800.0f,0.0f };

	m_TimerLabel.Draw();
}

//���
void CTime::Finalize(void)
{
	m_TimerLabel.Delete();
}

//�I��
bool CTime::Finished(void)
{
	//�������Ԃ�0�b�ȉ��Ȃ�Ԃ�
	return (m_TimeLimit <= 0);
}

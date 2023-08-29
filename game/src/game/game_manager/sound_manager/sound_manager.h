#pragma once
#include "aqua.h"

enum class SOUND_ID
{
	BGM,		//BGM
	DECISION,	//���艹
	CLICK,		//�N���b�N��
	CORRENT,	//������
	MISTAKE,	//�ԈႢ��

	MAX			//�T�E���hID�̐�
};

class CSoundManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CSoundManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSoundManager() = default;

	//������
	void Initialize(void)override;

	//���
	void Finalize(void)override;

	//�Đ�
	void Play(SOUND_ID id);
private:
	static const std::string m_sound_file_name[];
	aqua::CSoundPlayer* m_SoundPlayer;
};
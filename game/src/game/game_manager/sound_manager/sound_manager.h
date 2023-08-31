#pragma once
#include "aqua.h"

//�T�E���hID
enum class SOUND_ID
{
	BGM,		//BGM
	DECISION,	//���艹
	BCLICK,		//�N���b�N��(�{�^��)
	TCLICK,		//�^�[�Q�b�g�N���b�N��

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
	static const std::string m_sound_file_name[];	//�T�E���h�t�@�C��
	aqua::CSoundPlayer* m_SoundPlayer;				//�T�E���h�v���C���[
};
#pragma once
#include "aqua.h"
#include "../scene_manager/scene/scene_id.h"

class CSceneManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CSceneManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSceneManager() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);

	//�V�[���ύX
	void Change(SCENE_ID id);
	//�V�[���̃X�^�b�N
	void Push(SCENE_ID id);

	//�V�[���̎��o��
	void Eject(void);

	//�V�[���̃��Z�b�g
	void Reset(void);

private:
	//���ID
	enum class STATE
	{
		SCENE_IN,		//�V�[���J�n
		SCENE_UPDATE,	//�V�[���X�V
		SCENE_OUT,		//�V�[���I��
		SCENE_CHANGE,	//�V�[���ύX
	};

	//�V�[���̐���
	void Create(SCENE_ID id);

	//���݂̃V�[���̍폜
	void Delete(void);

	//�V�[���̊J�n
	void SceneIn(void);

	//�V�[���̍X�V
	void SceneUpdate(void);

	//�V�[���̏I��
	void SceneOut(void);

	//�V�[���̕ύX
	void ScneChange(void);

	SCENE_ID                m_CurrentSceneID;	//���݂̃V�[��ID
	SCENE_ID                m_NextSceneID;		//���̃V�[��ID
	SCENE_ID                m_PushSceneID;		//�X�^�b�N����V�[��ID
	STATE                   m_State;			//�V�[�����
	bool					m_PushFlag;			//�X�^�b�N�t���O
	static const float      m_fade_speed;		//�t�F�[�h���x
	aqua::CBoxPrimitive     m_FadePlane;		//�t�F�[�h�v���[��

};
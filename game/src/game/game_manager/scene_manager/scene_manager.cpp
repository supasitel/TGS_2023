#include "scene_manager.h"
#include "scene/title_scene/title_scene.h"
#include "scene/main_scene/main_scene.h"
#include "scene/result_scene/result_scene.h"

const float CSceneManager::m_fade_speed = 250.0f;	//�t�F�[�h���x

//�R���X�g���N�^
CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_CurrentSceneID(SCENE_ID::DUMMY)
	, m_NextSceneID(SCENE_ID::DUMMY)
	, m_PushSceneID(SCENE_ID::DUMMY)
	, m_State(STATE::SCENE_IN)
	, m_PushFlag(false)

{
}

//������
void CSceneManager::Initialize(void)
{
	//�t�F�[�h�v���[���̃Z�b�g�A�b�v
	m_FadePlane.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLACK);

	//�^�C�g���V�[��ID�̐���
	Create(SCENE_ID::TITLE);

	//��Ԃ��V�[���J�n�ɂ���
	m_State = STATE::SCENE_IN;

	//�X�^�b�N�t���O��false������
	m_PushFlag = false;


}

//�X�V
void CSceneManager::Update(void)
{
	switch (m_State)
	{
	case STATE::SCENE_IN:		SceneIn();		break;
	case STATE::SCENE_UPDATE:	SceneUpdate();	break;
	case STATE::SCENE_OUT:		SceneOut();		break;
	case STATE::SCENE_CHANGE:	ScneChange();	break;
	}
}

//�`��
void CSceneManager::Draw(void)
{
	IGameObject::Draw();

	//�t�F�[�h�v���[���̕`��
	m_FadePlane.Draw();
}

//���
void CSceneManager::Finalize(void)
{
	IGameObject::Finalize();
}

//�ύX
void CSceneManager::Change(SCENE_ID id)
{
	//���̃V�[���ɕύX
	m_NextSceneID = id;
}

//�X�^�b�N
void CSceneManager::Push(SCENE_ID id)
{
	//�����t���[�����ɂ��łɃv�b�V������Ă���
	if (m_PushFlag || m_PushSceneID != SCENE_ID::DUMMY)
		return;

	//�X�^�b�N�t���O��true�ɂ���
	m_PushFlag = true;

	//�X�^�b�N����V�[��ID
	m_PushSceneID = id;
}

//���o��
void CSceneManager::Eject(void)
{
	//�q�̃V�[�����P�̏ꍇ�|�b�v�ł��Ȃ�
	if (m_ChildObjectList.size() <= 1)
		return;

	// �����̃V�[���̃C�e���[�^�擾
	aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

	// �V�[���N���X�ɃL���X�g
	IScene* scene = (IScene*)(*it);

	//�V�[�����폜����
	scene->DeleteObject();

	// �ЂƂO�̃V�[�����擾
	scene = (IScene*)(*(++it));

	//�V�[���̏�Ԃ�ACTIVE�ɂ���
	scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);
}

//���Z�b�g
void CSceneManager::Reset(void)
{
	m_NextSceneID = m_CurrentSceneID;

	m_CurrentSceneID = SCENE_ID::DUMMY;
}

//����
void CSceneManager::Create(SCENE_ID id)
{
	IScene* scene = nullptr;

	// id���ƂɐV�����V�[���𐶐�
	switch (id)
	{
	case SCENE_ID::TITLE:		scene = aqua::CreateGameObject<CTitleScene>(this); break;
	case SCENE_ID::MAIN:		scene = aqua::CreateGameObject<CMainScene>(this); break;
	}

	AQUA_ASSERT(scene, "�V�[���������ł��܂���ł����B");

	scene->Initialize();
	scene->Update();
}

//�폜
void CSceneManager::Delete(void)
{
	IGameObject::Finalize();
}

//�V�[���J�n
void CSceneManager::SceneIn(void)
{
	//�A���t�@�l�̌v�Z
	float alpha = (float)m_FadePlane.color.alpha;
	alpha -= m_fade_speed * aqua::GetDeltaTime();

	//�A���t�@�l��0��菬����������
	if (alpha < 0.0f)
	{
		//�A���t�@�l��0�ɂ���
		alpha = 0.0f;

		//�V�[�����X�V����
		m_State = STATE::SCENE_UPDATE;
	}
	//�t�F�[�h�v���[���̐F�̃A���t�@�l
	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//�V�[���X�V
void CSceneManager::SceneUpdate(void)
{
	//�v�b�V��������
	if (m_PushFlag)
	{
		//�����̃V�[���̃C�e���[�^���擾
		aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

		//�V�[���N���X�ɃL���X�g
		IScene* scene = (IScene*)(*it);

		//�V�[����ҋ@��Ԃɂ���
		scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

		//�X�^�b�N����V�[��ID�𐶐�
		Create(m_PushSceneID);

		//�X�^�b�N����V�[��ID���_�~�[�ɂ���
		m_PushSceneID = SCENE_ID::DUMMY;

		//�X�^�b�N�t���O��false�ɂ���
		m_PushFlag = false;
	}

	IGameObject::Update();

	//�V�[���ύX�̌��m
	if (m_CurrentSceneID != m_NextSceneID)
		m_State = STATE::SCENE_OUT;
}

//�V�[���I��
void CSceneManager::SceneOut(void)
{
	//�A���t�@�l�̌v�Z
	float alpha = (float)m_FadePlane.color.alpha;
	alpha += m_fade_speed * aqua::GetDeltaTime();

	//�A���t�@�l���F�̍ő�l���傫��������
	if (alpha > (float)aqua::CColor::MAX_COLOR)
	{
		//�A���t�@�l��F�̍ő�l�ɂ���
		alpha = (float)aqua::CColor::MAX_COLOR;

		//�V�[���ύX
		m_State = STATE::SCENE_CHANGE;
	}
	//�t�F�[�h�v���[���̐F�̃A���t�@�l
	m_FadePlane.color.alpha = (unsigned char)alpha;

}

//�V�[���ύX
void CSceneManager::ScneChange(void)
{
	//���݂̃V�[�����폜
	Delete();

	//���̃V�[��ID�𐶐�
	Create(m_NextSceneID);

	//���݂̃V�[��ID�Ɏ��̃V�[��ID����
	m_CurrentSceneID = m_NextSceneID;

	//�V�[����Ԃ��V�[���J�n�ɂ���
	m_State = STATE::SCENE_IN;
}
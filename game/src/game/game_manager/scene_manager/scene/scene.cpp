#include "scene.h"
#include "../scene_manager.h"

//�R���X�g���N�^
IScene::IScene(aqua::IGameObject* parent, const std::string object_name)
	:aqua::IGameObject(parent, object_name)
{
}

//�V�[���ύX
void IScene::Change(SCENE_ID id)
{
	//�V�[���}�l�[�W���[�̎擾
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[���ύX
	sm->Change(id);

}

//�V�[���X�^�b�N
void IScene::Push(SCENE_ID id)
{
	//�V�[���}�l�[�W���[�̎擾
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[���X�^�b�N
	sm->Push(id);

}

//�V�[�������o��
void IScene::Eject(void)
{
	//�V�[���}�l�[�W���[�̎擾
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[�������o��
	sm->Eject();

}

//�V�[�����Z�b�g
void IScene::Reset(void)
{
	//�V�[���}�l�[�W���[�̎擾
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[���̃��Z�b�g
	sm->Reset();

}

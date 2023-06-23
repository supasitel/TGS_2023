#pragma once
#include "aqua.h"
#include "scene_id.h"

class IScene :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IScene(aqua::IGameObject* parent, const std::string object_name);

	//�f�X�g���N�^
	~IScene(void) = default;

	//�ύX
	void Change(SCENE_ID id);

	//�X�^�b�N
	void Push(SCENE_ID id);

	//���o��
	void Eject(void);

	//���Z�b�g
	void Reset(void);

private:
	static const std::string	m_scene_category;	//�V�[���J�e�S���[
};
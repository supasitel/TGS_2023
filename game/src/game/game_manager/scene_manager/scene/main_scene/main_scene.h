#pragma once
#include "aqua.h"
#include "../scene.h"

class CMainScene :public IScene
{
public:
	//�R���X�g���N�^
	CMainScene(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CMainScene() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CSprite	m_GBackGround;	//�w�i
};

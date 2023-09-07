#pragma once
#include "aqua.h"
#include "../scene.h"

class CExplanationScene :public IScene
{
public:
	//�R���X�g���N�^
	CExplanationScene(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CExplanationScene() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CSprite	m_BackGround;	//�w�i
	aqua::CSprite	m_Target;		//�^�[�Q�b�g
	aqua::CLabel	m_Explanation;	//����
	aqua::CLabel	m_Label;		//���x��
};
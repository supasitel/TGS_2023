#pragma once
#include "aqua.h"
#include "../../scene.h"

class CClearScene :public IScene
{
public:
	//�R���X�g���N�^
	CClearScene(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CClearScene() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	static const int m_width;		//2��ނ̃{�^���̕�
	static const int m_height;		//2��ނ̃{�^���̍���

	aqua::CLabel	m_Clear;		//�N���A���b�Z�[�W
	aqua::CLabel	m_Message;		//���b�Z�[�W
	aqua::CSprite	m_BackGround;	//�w�i
	aqua::CSprite	m_Button;		//�{�^��
	aqua::CSprite	m_ButtonBlack;	//�{�^��(����)
};

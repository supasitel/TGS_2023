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
	static const int m_width;
	static const int m_height;

	aqua::CLabel	m_Clear;
	aqua::CLabel	m_Message;
	aqua::CSprite	m_BackGround;
	aqua::CSprite	m_Button;
	aqua::CSprite	m_ButtonBlack;
};

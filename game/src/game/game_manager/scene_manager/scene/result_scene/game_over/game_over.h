#pragma once
#include "aqua.h"
#include "../../scene.h"

class COver :public IScene
{
public:
	//�R���X�g���N�^
	COver(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~COver() = default;

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

	aqua::CLabel	m_Over;
	aqua::CLabel	m_Message;
	aqua::CSprite	m_Button;
	aqua::CSprite	m_ButtonBlack;
};
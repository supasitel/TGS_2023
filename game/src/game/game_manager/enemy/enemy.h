#pragma once
#include "aqua.h"

class CEnemy :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CEnemy(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CEnemy() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);
private:
	static const int m_width;	//��
	static const int m_height;	//����

	aqua::CSprite	m_Enemy;	//�G�l�~�[
};

#pragma once
#include "aqua.h"
#include "enemy/enemy_id.h"

class CEnemyManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CEnemyManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CEnemyManager() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);

	//�G�l�~�[����
	void Create(ENEMY_ID id);
private:
	static const float m_create_interval;	//�����Ԋu
	aqua::CTimer	   m_CreateTimer;		//�����^�C�}�[
};
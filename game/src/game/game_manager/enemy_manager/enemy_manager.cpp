#include "enemy_manager.h"
#include "enemy/enemy.h"

const float CEnemyManager::m_create_interval = 0.75;	//�����Ԋu

//�R���X�g���N�^
CEnemyManager::CEnemyManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyManager")
{
}

//������
void CEnemyManager::Initialize(void)
{
	//�����^�C�}�[�̏�����
	m_CreateTimer.Setup(m_create_interval);

	IGameObject::Initialize();
}

//�X�V
void CEnemyManager::Update(void)
{
	//�����^�C�}�[�̍X�V
	m_CreateTimer.Update();

	//�����^�C�}�[���I��������
	if (m_CreateTimer.Finished())
	{
		//�����^�C�}�[�����Z�b�g����
		m_CreateTimer.Reset();

		//�G�l�~�[1�𐶐�
		Create(ENEMY_ID::ENEMY1);
	}
	IGameObject::Update();
}

//�`��
void CEnemyManager::Draw(void)
{
	IGameObject::Draw();
}

//���
void CEnemyManager::Finalize(void)
{
	IGameObject::Finalize();
}

//�G�l�~�[����
void CEnemyManager::Create(ENEMY_ID id)
{
}

#pragma once
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/unit.h"

class CCurrnetTarget :public IUnit
{
public:
	//�R���X�g���N�^
	CCurrnetTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCurrnetTarget() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
};
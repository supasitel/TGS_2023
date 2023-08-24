#include "aqua.h"

class IUIManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IUIManager(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	~IUIManager() = default;

	//������
	void Initialize(void)override;
private:
	static const std::string	m_ui_category;	//�J�e�S���[
};
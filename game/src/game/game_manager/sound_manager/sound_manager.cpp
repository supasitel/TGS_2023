#include "sound_manager.h"

//サウンドファイル名
const std::string CSoundManager::m_sound_file_name[] =
{
	"data\\海岸1.mp3",
	"data\\decision.mp3",
	"data\\button_click.mp3",
	"data\\target_click.mp3",
};

//コンストラクタ
CSoundManager::CSoundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SoundManager")
	, m_SoundPlayer(nullptr)
{
}

//初期化
void CSoundManager::Initialize(void)
{
	if (!m_SoundPlayer)m_SoundPlayer = AQUA_NEW aqua::CSoundPlayer[(int)SOUND_ID::MAX];

	//BGMはループ再生設定
	m_SoundPlayer[(int)SOUND_ID::BGM].Create(m_sound_file_name[(int)SOUND_ID::BGM], true);

	//SEは単発
	for (int i = (int)SOUND_ID::DECISION; i < (int)SOUND_ID::MAX; ++i)
		m_SoundPlayer[i].Create(m_sound_file_name[i], false, 100);

}

//解放
void CSoundManager::Finalize(void)
{
	for (int i = 0; i < (int)SOUND_ID::MAX; ++i)
		m_SoundPlayer[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_SoundPlayer);
}

//再生
void CSoundManager::Play(SOUND_ID id)
{
	if (!m_SoundPlayer)return;
	m_SoundPlayer[(int)id].Play();
}

#pragma once

enum class MusicType
{
	NOTHING,
	OVERWORLD,
	OVERWORLDFAST,
	UNDERWORLD,
	UNDERWORLDFAST,
	UNDERWATER,
	UNDERWATERFAST,
	CASTLE,
	CASTLEFAST,
	LOWTIME,
	STAR,
	STARFAST,
	SCORERING,
};

enum class SoundType
{
	COIN,
	BLOCKBREAK,
	BLOCKHIT,
	BOOM,
	BOWSERFALL,
	BRIDGEBREAK,
	BULLETBILL,
	DEATH,
	FIRE,
	FIREBALL,
	GAMEOVER,
	INTERMISSION,
	JUMP,
	JUMPBIG,
	LEVELEND,
	LOWTIME,
	MUSHROOMAPPER,
	MUSHROOMMEAT,
	ONEUP,
	PASUE,
	PIPE,
	RAINBOOM,
	SHOT,
	SHRINK,
	STOMP,
	SWIM,
	VINE,
	CASTLEEND,
	PRINCESSMUSIC,
};

class MusicMgr
{
public:
	MusicMgr();
	~MusicMgr();

	void ChangeMusic(bool musicByLevel, bool forceChange);

	void PlayMusic();
	void PlayMusic(MusicType musicID);
	void StopMusic();
	void PauseMusic();

	void PlayChunk(SoundType chunkID);

	bool musicStopped;
private:
	Mix_Music* loadMusic(std::string fileName);
	Mix_Chunk* loadChunk(std::string fileName);
	
	std::vector<Mix_Music*> m_music;
	std::vector<Mix_Chunk*> m_chunk;
	const int m_volume = 100;
	MusicType m_currentMusic = MusicType::NOTHING;
};
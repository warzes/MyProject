#include "stdafx.h"
#include "Music.h"

Music::Music()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	m_music.push_back(LoadMusic("overworld"));
	m_music.push_back(LoadMusic("overworld-fast"));
	m_music.push_back(LoadMusic("underground"));
	m_music.push_back(LoadMusic("underground-fast"));
	m_music.push_back(LoadMusic("underwater"));
	m_music.push_back(LoadMusic("underwater-fast"));
	m_music.push_back(LoadMusic("castle"));
	m_music.push_back(LoadMusic("castle-fast"));
	m_music.push_back(LoadMusic("lowtime"));
	m_music.push_back(LoadMusic("starmusic"));
	m_music.push_back(LoadMusic("starmusic-fast"));
	m_music.push_back(LoadMusic("scorering"));

	m_chunk.push_back(LoadChunk("coin"));
	m_chunk.push_back(LoadChunk("blockbreak"));
	m_chunk.push_back(LoadChunk("blockhit"));
	m_chunk.push_back(LoadChunk("boom"));
	m_chunk.push_back(LoadChunk("bowserfall"));
	m_chunk.push_back(LoadChunk("bridgebreak"));
	m_chunk.push_back(LoadChunk("bulletbill"));
	m_chunk.push_back(LoadChunk("death"));
	m_chunk.push_back(LoadChunk("fire"));
	m_chunk.push_back(LoadChunk("fireball"));
	m_chunk.push_back(LoadChunk("gameover"));
	m_chunk.push_back(LoadChunk("intermission"));
	m_chunk.push_back(LoadChunk("jump"));
	m_chunk.push_back(LoadChunk("jumpbig"));
	m_chunk.push_back(LoadChunk("levelend"));
	m_chunk.push_back(LoadChunk("lowtime"));
	m_chunk.push_back(LoadChunk("mushroomappear"));
	m_chunk.push_back(LoadChunk("mushroomeat"));
	m_chunk.push_back(LoadChunk("oneup"));
	m_chunk.push_back(LoadChunk("pause"));
	m_chunk.push_back(LoadChunk("shrink"));
	m_chunk.push_back(LoadChunk("rainboom"));
	m_chunk.push_back(LoadChunk("shot"));
	m_chunk.push_back(LoadChunk("shrink"));
	m_chunk.push_back(LoadChunk("stomp"));
	m_chunk.push_back(LoadChunk("swim"));
	m_chunk.push_back(LoadChunk("vine"));
	m_chunk.push_back(LoadChunk("castleend"));
	m_chunk.push_back(LoadChunk("princessmusic"));

	SetVolume(100);
	currentMusic = mNOTHING;
}

Music::~Music()
{
	for ( size_t i = 0; i < m_music.size(); i++ )
	{
		Mix_FreeMusic(m_music[i]);
	}

	m_music.clear();

	for ( size_t i = 0; i < m_chunk.size(); i++ )
	{
		Mix_FreeChunk(m_chunk[i]);
	}

	m_chunk.clear();
}

void Music::ChangeMusic(bool musicByLevel, bool forceChange)
{
	eMusic eNew = currentMusic;

	if ( musicByLevel )
	{
		TODO_PRINT("void Music::ChangeMusic(bool musicByLevel, bool forceChange)");
	}

	if ( currentMusic != eNew || forceChange )
	{
		StopMusic();
		currentMusic = eNew;
		PlayMusic();
	}
}

void Music::PlayMusic()
{
	if ( currentMusic != mNOTHING )
	{
		Mix_PlayMusic(m_music[currentMusic - 1], -1);
		musicStopped = false;
	}
	else
	{
		StopMusic();
	}
}

void Music::PlayMusic(eMusic musicID)
{
	if ( musicID != mNOTHING )
	{
		Mix_PlayMusic(m_music[musicID - 1], -1);
		musicStopped = false;
		currentMusic = musicID;
	}
	else
	{
		StopMusic();
		currentMusic = mNOTHING;
	}
}

void Music::StopMusic()
{
	if ( !musicStopped )
	{
		Mix_HaltMusic();
		musicStopped = true;
	}
}

void Music::PauseMusic()
{
	if ( Mix_PausedMusic() == 1 )
	{
		Mix_ResumeMusic();
		musicStopped = false;
	}
	else
	{
		Mix_PauseMusic();
		musicStopped = true;
	}
}

/* ******************************************** */

void Music::PlayChunk(eChunk chunkID)
{
	Mix_VolumeChunk(m_chunk[chunkID], m_volume);
	Mix_PlayChannel(-1, m_chunk[chunkID], 0);
}

/* ******************************************** */

Mix_Music* Music::LoadMusic(std::string fileName)
{
	fileName = "data/sounds/" + fileName + ".wav";
	return Mix_LoadMUS(fileName.c_str());
}

Mix_Chunk* Music::LoadChunk(std::string fileName)
{
	fileName = "data/sounds/" + fileName + ".wav";
	return Mix_LoadWAV(fileName.c_str());
}

int Music::GetVolume()
{
	return m_volume;
}

void Music::SetVolume(int volume)
{
	m_volume = volume;
	Mix_VolumeMusic(m_volume);
}
// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "MusicMgr.h"
#include "App.h"

//=============================================================================
MusicMgr::MusicMgr()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_VolumeMusic(m_volume);

	m_music.push_back(loadMusic("overworld"));
	m_music.push_back(loadMusic("overworld-fast"));
	m_music.push_back(loadMusic("underground"));
	m_music.push_back(loadMusic("underground-fast"));
	m_music.push_back(loadMusic("underwater"));
	m_music.push_back(loadMusic("underwater-fast"));
	m_music.push_back(loadMusic("castle"));
	m_music.push_back(loadMusic("castle-fast"));
	m_music.push_back(loadMusic("lowtime"));
	m_music.push_back(loadMusic("starmusic"));
	m_music.push_back(loadMusic("starmusic-fast"));
	m_music.push_back(loadMusic("scorering"));

	m_chunk.push_back(loadChunk("coin"));
	m_chunk.push_back(loadChunk("blockbreak"));
	m_chunk.push_back(loadChunk("blockhit"));
	m_chunk.push_back(loadChunk("boom"));
	m_chunk.push_back(loadChunk("bowserfall"));
	m_chunk.push_back(loadChunk("bridgebreak"));
	m_chunk.push_back(loadChunk("bulletbill"));
	m_chunk.push_back(loadChunk("death"));
	m_chunk.push_back(loadChunk("fire"));
	m_chunk.push_back(loadChunk("fireball"));
	m_chunk.push_back(loadChunk("gameover"));
	m_chunk.push_back(loadChunk("intermission"));
	m_chunk.push_back(loadChunk("jump"));
	m_chunk.push_back(loadChunk("jumpbig"));
	m_chunk.push_back(loadChunk("levelend"));
	m_chunk.push_back(loadChunk("lowtime"));
	m_chunk.push_back(loadChunk("mushroomappear"));
	m_chunk.push_back(loadChunk("mushroomeat"));
	m_chunk.push_back(loadChunk("oneup"));
	m_chunk.push_back(loadChunk("pause"));
	m_chunk.push_back(loadChunk("shrink"));
	m_chunk.push_back(loadChunk("rainboom"));
	m_chunk.push_back(loadChunk("shot"));
	m_chunk.push_back(loadChunk("shrink"));
	m_chunk.push_back(loadChunk("stomp"));
	m_chunk.push_back(loadChunk("swim"));
	m_chunk.push_back(loadChunk("vine"));
	m_chunk.push_back(loadChunk("castleend"));
	m_chunk.push_back(loadChunk("princessmusic"));
}
//=============================================================================
MusicMgr::~MusicMgr()
{
	for ( size_t i = 0; i < m_music.size(); i++ )
		Mix_FreeMusic(m_music[i]);
	for ( size_t i = 0; i < m_chunk.size(); i++ )
		Mix_FreeChunk(m_chunk[i]);
	Mix_CloseAudio();
}
//=============================================================================
void MusicMgr::ChangeMusic(bool musicByLevel, bool forceChange)
{
	MusicType newMusic = m_currentMusic;

	if ( musicByLevel )
	{
		const auto game = App::GetGame();

		if ( game->getInEvent() && game->getEvent()->inEvent )
		{
			newMusic = MusicType::NOTHING;
			PlayChunk(SoundType::INTERMISSION);
		}
		else
		{
			switch ( game->getLevelType() )
			{
			case 0: case 4:
				newMusic = game->getMapTime() > 90 ? MusicType::OVERWORLD : MusicType::OVERWORLDFAST;
				break;
			case 1:
				newMusic = game->getMapTime() > 90 ? MusicType::UNDERWORLD : MusicType::UNDERWORLDFAST;
				break;
			case 2:
				newMusic = game->getMapTime() > 90 ? MusicType::UNDERWATER : MusicType::UNDERWATERFAST;
				break;
			case 3:
				newMusic = game->getMapTime() > 90 ? MusicType::CASTLE : MusicType::CASTLEFAST;
				break;
			case 100:
				newMusic = MusicType::NOTHING;
				PlayChunk(SoundType::INTERMISSION);
				game->setLevelType(0);
				break;
			default:
				newMusic = MusicType::NOTHING;
				break;
			}
		}
	}

	if ( m_currentMusic != newMusic || forceChange )
	{
		StopMusic();
		m_currentMusic = newMusic;
		PlayMusic();
	}
}
//=============================================================================
void MusicMgr::PlayMusic()
{
	if ( m_currentMusic != MusicType::NOTHING )
	{
		Mix_PlayMusic(m_music[static_cast<size_t>(m_currentMusic) - 1], -1);
		musicStopped = false;
	}
	else
		StopMusic();
}
//=============================================================================
void MusicMgr::PlayMusic(MusicType musicID)
{
	m_currentMusic = musicID;
	if ( musicID != MusicType::NOTHING )
	{
		Mix_PlayMusic(m_music[static_cast<size_t>(musicID) - 1], -1);
		musicStopped = false;		
	}
	else
		StopMusic();
}
//=============================================================================
void MusicMgr::StopMusic()
{
	if ( !musicStopped )
	{
		Mix_HaltMusic();
		musicStopped = true;
	}
}
//=============================================================================
void MusicMgr::PauseMusic()
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
//=============================================================================
void MusicMgr::PlayChunk(SoundType chunkID)
{
	const size_t id = static_cast<size_t>(chunkID);
	Mix_VolumeChunk(m_chunk[id], m_volume);
	Mix_PlayChannel(-1, m_chunk[id], 0);
}
//=============================================================================
Mix_Music* MusicMgr::loadMusic(std::string fileName)
{
	fileName = "data/sounds/" + fileName + ".wav";
	return Mix_LoadMUS(fileName.c_str());
}
//=============================================================================
Mix_Chunk* MusicMgr::loadChunk(std::string fileName)
{
	fileName = "data/sounds/" + fileName + ".wav";
	return Mix_LoadWAV(fileName.c_str());
}
//=============================================================================
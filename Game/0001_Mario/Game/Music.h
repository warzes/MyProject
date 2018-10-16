#pragma once

class Music
{
public:
	enum eMusic
	{
		mNOTHING,
		mOVERWORLD,
		mOVERWORLDFAST,
		mUNDERWORLD,
		mUNDERWORLDFAST,
		mUNDERWATER,
		mUNDERWATERFAST,
		mCASTLE,
		mCASTLEFAST,
		mLOWTIME,
		mSTAR,
		mSTARFAST,
		mSCORERING,
	};

	enum eChunk
	{
		cCOIN,
		cBLOCKBREAK,
		cBLOCKHIT,
		cBOOM,
		cBOWSERFALL,
		cBRIDGEBREAK,
		cBULLETBILL,
		cDEATH,
		cFIRE,
		cFIREBALL,
		cGAMEOVER,
		cINTERMISSION,
		cJUMP,
		cJUMPBIG,
		cLEVELEND,
		cLOWTIME,
		cMUSHROOMAPPER,
		cMUSHROOMMEAT,
		cONEUP,
		cPASUE,
		cPIPE,
		cRAINBOOM,
		cSHOT,
		cSHRINK,
		cSTOMP,
		cSWIM,
		cVINE,
		cCASTLEEND,
		cPRINCESSMUSIC,
	};

	Music();
	~Music();

	bool musicStopped;
	
	eMusic currentMusic;	

	void ChangeMusic(bool musicByLevel, bool forceChange);

	void PlayMusic();
	void PlayMusic(eMusic musicID);
	void StopMusic();
	void PauseMusic();

	void PlayChunk(eChunk chunkID);

	Mix_Music* LoadMusic(std::string fileName);
	Mix_Chunk* LoadChunk(std::string fileName);
	
	int GetVolume();
	void SetVolume(int volume);

private:
	std::vector<Mix_Music*> m_music;
	std::vector<Mix_Chunk*> m_chunk;

	int m_volume;
};
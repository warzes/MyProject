#include <libtcod.hpp>

#pragma comment(lib, "libtcod.lib")

/*
а может заменить на BearLibTerminal (проблема с русским)

- идея - игрок должен оборонять одну из сторон поселения гильдии. Поселение защищено щитом, который монстры могут дамажить (но по факту щит им придется долго разрушать, пока жив игрок - у них такого шанса не будет)

игрок играет партией персонажей. за свой ход он может активировать способности каждого (клавиши - 1-4, q,e или tab)

между волнами игрок может заниматься менеджментом

*/



int main()
{
	TCODConsole::initRoot(80, 50, "libtcod C++ tutorial", false);
	while ( !TCODConsole::isWindowClosed() )
	{
		TCOD_key_t key;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		TCODConsole::root->clear();
		TCODConsole::root->putChar(40, 25, '@');
		TCODConsole::flush();
	}
	return 0;
}
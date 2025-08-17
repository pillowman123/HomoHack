#include "bRRPlayerNumbering.h"

namespace Pointers::Networking {
	U_RRPlayerNumbering RRPlayerNumbering;

	void U_RRPlayerNumbering::Setup() {
		klass = { "RecRoom.Networking.RRNetworkLayer", "RecRoom.Networking", "RRPlayerNumbering" };

		SortedPlayers = klass.GetField("SortedPlayers");
	}
}
#include "Drawer.h"


namespace Karcassonne {

	std::ostream & operator<<(std::ostream & out, const Bounds & b) { return out << "{\"xmin\":" << b.xmin << ",\"xmax\":" << b.xmax << ",\"ymin\":" << b.ymin << ",\"ymax\":" << b.ymax << "}"; }
	void writeTileInfo(std::ostream & out, const Position & p, const Tile & t) { out << "{\"name\":\"" << t.name << "\",\"direction\":" << t.direction.get() << ",\"position\":" << p << "}"; }

	void writeCurrentState(std::ostream & out, const Game & g) {
		Bounds bounds{ 0, 0, 0, 0 };

		for (int i = 0, l = g.getNumberPositions(); i < l; i++)
			bounds.update(g.getPosition(i));
		for (int i = 0, l = g.getNumberReachablePositions(); i < l; i++)
			bounds.update(g.getReachablePosition(i));

		out << "{\"type\":\"oneState\",\"version\":\"20180624\",\"bounds\":" << bounds << ",";

		out << "\"tiles\":[";
		for (int i = 0, l = g.getNumberPositions() - 1; i < l; i++) {
			writeTileInfo(out, g.getPosition(i), g.getTile(i));
			out << ',';
		}
		writeTileInfo(out, g.getPosition(g.getNumberPositions() - 1), g.getTile(g.getNumberPositions() - 1));
		out << "],";

		out << "\"reachables\":[";
		for (int i = 0, l = g.getNumberReachablePositions() - 1; i < l; i++)
			out << g.getReachablePosition(i) << ',';
		out << g.getReachablePosition(g.getNumberReachablePositions() - 1);
		out << "]}";
	}

	void writeHTMLHeader(std::ostream & out)
	{
		out << "<!DOCTYPE html><html lang=\"fr\"><head><meta charset=\"utf-8\" /><title>Karcassonne</title><link rel=\"icon\" type=\"image/png\" href=\"tiles/icone.png\" /><link rel=\"stylesheet\" href=\"tiles/design.css\"><script src=\"tiles/script.js\"></script></head>";
	}

	void writeFollowerInfo(std::ostream & out, const Position & p, const FollowerLog & fl, int indexPlayer) {
		switch (fl.getFollowerType()) {
		case OptionFollowerType::None: out << "{type:'none'}"; break;
		case OptionFollowerType::Monk: out << "{type:'monk',position:" << p << ",player:" << indexPlayer << "}"; break;
		case OptionFollowerType::Knight: out << "{type:'knight',position:" << p << ",direction:" << fl.getDirection().get() << ",player:" << indexPlayer << "}"; break;
		case OptionFollowerType::Thief: out << "{type:'thief',position:" << p << ",direction:" << fl.getDirection().get() << ",player:" << indexPlayer << "}"; break;
		case OptionFollowerType::Farmer: out << "{type:'farmer',position:" << p << ",direction:" << fl.getDirection().get() << ",player:" << indexPlayer;
			switch (fl.getFieldPosition()) {
			case FieldPosition::Left: out << ",precision:'left'}"; break;
			case FieldPosition::Right: out << ",precision:'right'}"; break;
			case FieldPosition::Center: out << ",precision:'center'}"; break;
			default: out << ",precision:'center'}"; break;
			}
			break;
		default: out << "{type:'unknown'}"; break;
		}
	}

	void writeFollowers(std::ostream & out, const Game & g)
	{
		out << "[";
		int l = g.getNumberPositions() - 1;
		for (int i = 0; i < l; i++) {
			writeFollowerInfo(out, g.getPosition(i), g.getFollowerLog(i), i % g.getNumberOfPlayers());
			out << ',';
		}
		writeFollowerInfo(out, g.getPosition(l), g.getFollowerLog(l), l % g.getNumberOfPlayers());
		out << "]";
	}


}

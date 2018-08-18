#include "Drawer.h"


namespace kar {

	struct Bounds {
		int xmax; int xmin; int ymax; int ymin;
		void update(const Position & p) { if (p.x < xmin) xmin = p.x; else if (p.x > xmax) xmax = p.x; if (p.y < ymin) ymin = p.y; else if (p.y > ymax) ymax = p.y; }
	};

	void writeCurrentState(std::ostream & out, const Game & g);
	void writeHTMLHeader(std::ostream & out);
	void writeFollowers(std::ostream & out, const Game & g);



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
		out << "<!DOCTYPE html><html lang=\"fr\"><head><meta charset=\"utf-8\" /><title>kar</title><link rel=\"icon\" type=\"image/png\" href=\"tiles/icone.png\" /><link rel=\"stylesheet\" href=\"tiles/design.css\"><script src=\"tiles/script.js\"></script></head>";
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

	void writeMap20180729(std::ostream & out, const Game & g)
	{
		writeHTMLHeader(out);
		out << "<body><script language=\"javascript\">var state=";
		writeCurrentState(out, g);
		out << ";var followers =";
		writeFollowers(out, g);
		out << ";K.showLogState20180729(\"first\",state,followers);</script></body></html>";
	}

	void writeStats20180817(std::ostream & out, Game & g)
	{
		writeHTMLHeader(out);
		out << "<body><script language=\"javascript\">var state=";
		writeCurrentState(out, g);
		out << ";var followers =";
		writeFollowers(out, g);
		out << ";K.showLogState20180729(\"first\",state,followers);";
		out << "var colNames=[\"turn\",\"city points\",\"road points\",\"cloister points\"];";
		out << "var rows=";
		
		{
			out << "[";
			out << "[\"end\"," << g.getKnightScore(0) << ',' << g.getThiefScore(0) << ',' << g.getMonkScore(0) << "]";
			g.cancelEnd();

			for (; g.getNumberTiles() > 0; g.cancel())
				out << ",[" << g.getNumberTiles() << ',' << g.getKnightScore(0) << ',' << g.getThiefScore(0) << ',' << g.getMonkScore(0) << ']';

			out << ",[" << g.getNumberTiles() << ',' << g.getKnightScore(0) << ',' << g.getThiefScore(0) << ',' << g.getMonkScore(0) << ']';

			out << "]";
		}

		out << ";K.showTable20180817(\"stats20180817\",colNames,rows);";
		out << "</script></body></html>";
	}


}

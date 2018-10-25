# karcassonne-z
Little steps forward to making AI for Carcassonne.



The program simulates a play of [Carcassonne](https://en.wikipedia.org/wiki/Carcassonne_(board_game)), played by only one player.
The player try to get the higher score, by setting followers and tiles to complete the board.

You can configure the player to set followers :
- only on cloisters (command : Tylez.exe c > output.html);
- only on roads (command : Tylez.exe r > output.html);
- on cloisters and on roads (command : Tylez.exe b > output.html);
- on cloisters, roads and cities (command : Tylez.exe k > output.html);
- one follower at the start as farmer, the others on cities (command : Tylez.exe f > output.html).

The program writes its output in the standard output, as a html file, with the board drawn.
The output file and the "tiles" directory must be in the same directory.


#include <string>

std::string ticTacToeResult(const std::string& S) {
    bool xWins = false, oWins = false;

    for (size_t i = 0; i < S.size() - 2; ++i) {
        if (S.substr(i, 3) == "XXX") {
            xWins = true;
        }
        if (S.substr(i, 3) == "OOO") {
            oWins = true;
        }
    }

    if (xWins && oWins) {
        return "tie";
    } else if (xWins) {
        return "X";
    } else if (oWins) {
        return "O";
    } else {
        return "No winner";
    }
}
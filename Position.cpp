#include "Position.h"

bool Position::operator==(const Position& other) const {
    return file == other.file && rank == other.rank;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

bool Position::isValid() const {
    return file >= 0 && file < 8 && rank >= 0 && rank < 8;
}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    return os << (char)('A' + p.file) << (char)('1' + p.rank);
}
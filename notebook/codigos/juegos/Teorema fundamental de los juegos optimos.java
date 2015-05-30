boolean isWinning(position pos) {
    moves[] = possible positions to which I can move from the position pos;
    for (all x in moves) 
        if (!isWinning(x)) return true;
    
    return false; 
}
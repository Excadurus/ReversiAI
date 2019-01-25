# ReversiAI
AI for the Game Reversi, KNTU Project
Currently The AI works using a Priority(weight) System. This is the Priority
        0, 7, 1, 4, 4, 1, 7, 0
        7, 8, 6, 5, 5, 6, 8, 7
        1, 6, 2, 3, 3, 2, 6, 1
        4, 5, 3, 0, 0, 3, 5, 4
        4, 5, 3, 0, 0, 3, 5, 4
        1, 6, 2, 3, 3, 2, 6, 1
        7, 8, 6, 5, 5, 6, 8, 7
        0, 7, 1, 4, 4, 1, 7, 0
Algorithmwise, The AI first finds all Available moves then chooses the move with the highest priority(Lowest Number)if there are multiple available moves with the same
High score, then AI choosen the last One
finally it show the best move by Printing the X and Y for that move (arraywise this is what x and y are : Array[Y][X]) 
By Reza Liaghat and Ali Ghayoomi
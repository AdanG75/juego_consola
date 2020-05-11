#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        int x;
        int y;
        int lastX;
        int lastY;
        Player();
        void ResetToSafePosition();
        void ResetBegining(bool change);
        virtual ~Player();

        void callInput(int levelPlayer, bool change);

    protected:

    private:
};

#endif // PLAYER_H

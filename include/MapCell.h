#ifndef MAPCELL_H
#define MAPCELL_H


class MapCell
{
    public:
        char id;
        MapCell();
        bool IsBlocked();
        virtual ~MapCell();

    protected:

    private:
};

#endif // MAPCELL_H
